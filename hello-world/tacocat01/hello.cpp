#include "RendererConsole.hpp"

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<std::vector<char>> ReadFile(int& maxRow);

int main()
{

    int maxRow = 0;
    auto vec = ReadFile(maxRow);
    std::uint8_t rows = static_cast<std::uint8_t>(rlutil::trows());
    if (maxRow > rows)
    {
        std::cout << "Please make your terminal taller" << std::endl;
        return 0;
    }
    std::uint8_t columns = static_cast<std::uint8_t>(rlutil::tcols());
    if (vec.size() > columns)
    {
        std::cout << "Please make your terminal wider" << std::endl;
        return 0;
    }

    auto render = RendererConsole(vec.size(), maxRow, vec);

    while (!render.Render())
        ;

    return 0;
}

// Makes our vector of vectors containing the strings from the file
std::vector<std::vector<char>> ReadFile(int& maxRow)
{
    std::fstream figlet;
    figlet.open("figlet.txt", std::ios::in);
    std::vector<std::vector<char>> vec;
    int row = 0;

    if (figlet.is_open())
    {

        auto temp = new std::vector<char>;
        for (std::istreambuf_iterator<char> i(figlet), e; i != e; i++, row++)
        {

            if (*i == '\n')
            {
                // we hit the end of the line, add our vector on and make a new one for
                // the next row
                vec.push_back(*temp);
                temp = new std::vector<char>;

                // check our maxRow every time we hit a new line character
                if (row > maxRow)
                {
                    maxRow = row;
                }
                row = 0;
            }
            else
            {
                temp->push_back(*i);
            }
        }

        // standardize all the vectors to have the same length
        for (int i = 0; i < vec.size(); i++)
        {
            while (vec[i].size() != maxRow)
            {
                vec[i].push_back(' ');
            }
        }
    }
    figlet.close();
    return vec;
}
