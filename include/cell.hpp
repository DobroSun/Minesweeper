#ifndef CELL_CPP
#define CELL_CPP
#include <SDL2/SDL.h>
#include <string>

SDL_Rect make_SrcR(int posx, int posy);
SDL_Rect make_DestR(int posx, int posy);

SDL_Texture *make_texture(SDL_Renderer *renderer, std::string &path);

class Cell {
public:
    Cell();

    bool is_bomb;
    SDL_Texture *texture;
    SDL_Rect SrcR;
    SDL_Rect DestR;
};
#endif
