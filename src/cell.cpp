#include <SDL2/SDL_image.h>

#include "cell.hpp"
#include "globals.hpp"

SDL_Rect make_SrcR(int posx, int posy) {
    SDL_Rect rect;
    return rect;
}

SDL_Rect make_DestR(int posx, int posy) {
    SDL_Rect rect;
    rect.x = posx;
    rect.y = posy;
    rect.w = CellSize;
    rect.h = CellSize;
    return rect;
}

SDL_Texture *make_texture(SDL_Renderer *renderer, std::string &path) {
    SDL_Surface *image = IMG_Load(path.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    return texture;
}

Cell::Cell() {
    texture = nullptr;
}
