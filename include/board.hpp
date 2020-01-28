#ifndef BOARD_CPP
#define BOARD_CPP
#include "cell.hpp"
#include "globals.hpp"

#include <SDL2/SDL_image.h>
#include <array>

class Board;
static std::array<std::string, 2> paths;
void CreateBoard(Board &board, SDL_Renderer *renderer);

int get_random(int stop);

class Board {
public:
    std::array<std::array<Cell, num_cells_on_length>, num_cells_on_height> field;
};
#endif
