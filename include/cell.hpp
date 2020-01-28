#ifndef CELL_CPP
#define CELL_CPP
#include <SDL2/SDL.h>
#include "globals.hpp"
#include <string>

SDL_Rect make_SrcR(int posx, int posy);
SDL_Rect make_DestR(int posx, int posy);

SDL_Texture *make_texture(SDL_Renderer *renderer, std::string &path);

bool cell_exists(int i, int j);
class Cell {
public:
    Cell();

    size_t bombs_around;
    bool is_bomb;
    bool is_hidden;
    SDL_Texture *texture;
    SDL_Texture *default_texture;
    SDL_Rect SrcR;
    SDL_Rect DestR;
};
#endif
