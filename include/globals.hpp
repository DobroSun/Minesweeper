#ifndef GLOBALS_CPP
#define GLOBALS_CPP
#include <string>
#include <array>

const int WIDTH = 600;
const int HEIGHT = 600;

const int CellSize = 20;

const int offset = 0;

const int UpperBound = 200;
const int LowerBound = HEIGHT - offset;
const int LeftBound = offset;
const int RightBound = WIDTH - offset;


const int num_cells_on_length = RightBound / CellSize;
const int num_cells_on_height = (LowerBound - UpperBound) / CellSize;

const std::string assets_path = "../assets/";

class Cell;
typedef std::array<std::array<Cell, num_cells_on_length>, num_cells_on_height> board_array;
#endif
