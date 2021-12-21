#include "RendererConsole.hpp"

RendererConsole::RendererConsole(std::uint8_t sizeX, std::uint8_t sizeY,
                                 std::vector<std::vector<char>> vec)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->vec = vec;

    for (int i = 0; i < sizeX; i++)
    {
        auto temp = new std::vector<char>();
        for (int j = 0; j < sizeY; j++)
        {
            temp->push_back(' ');
        }
        board.push_back(*temp);
    }

    rlutil::cls();
}

bool RendererConsole::Render()
{
    bool done = true;
    rlutil::hidecursor();
    for (std::uint8_t x = 0; x < sizeX; x++)
    {
        for (std::uint8_t y = 0; y < sizeY; y++)
        {
            if (vec[x][y] != board[x][y])
            {
                board[x][y] = characters[dist(engine)];

                done = false;
                rlutil::locate(y + 1, x + 1);
                rlutil::setChar(board[x][y]);
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    return done;
}
