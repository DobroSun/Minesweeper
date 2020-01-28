#ifndef BOARD_CPP
#define BOARD_CPP
#include "cell.hpp"
#include "globals.hpp"

#include <SDL2/SDL_image.h>
#include <array>

class Board;
void CreateBoard(Board &board, SDL_Renderer *renderer);
void ComputeCells(Board &board, SDL_Renderer *renderer);

Cell *Get_Cell(Board &board, double x, double y);
void OpenEmptyCells(Board &board, Cell *cell);
void GameOver(Board &board);

class Board {
public:
    std::array<std::array<Cell, num_cells_on_length>, num_cells_on_height> field;
};
#endif
