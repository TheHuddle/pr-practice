#pragma once
#include "rlutil.h"

#include <chrono>
#include <random>
#include <thread>

class RendererConsole
{
  private:
    char characters[14] = { '.', ',', '|', '\\', '/', '-', '_',
                            '\'', '`', ')', '(', 'v', 'V', ' ' };

    std::vector<std::vector<char>> board;
    std::uint8_t sizeX;
    std::uint8_t sizeY;
    std::vector<std::vector<char>> vec;
    std::default_random_engine engine;
    std::uniform_int_distribution<> dist{ 0, 13 };

  public:
    RendererConsole(std::uint8_t sizeX, std::uint8_t sizeY,
                    std::vector<std::vector<char>> vec);
    bool Render();
};
