#ifndef GLOBALS_CPP
#define GLOBALS_CPP
#include <string>

const int WIDTH = 600;
const int HEIGHT = 600;

const int SurfSize = 200; 
const int CellSize = SurfSize/10; 

const int StartOfField = 200;
const int num_cells_on_length = WIDTH / CellSize;
const int num_cells_on_height = (HEIGHT - StartOfField) / CellSize;

const std::string assets_path = "../assets/";
#endif
