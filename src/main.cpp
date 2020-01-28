#include "board.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


int main() {
    bool is_running = true;
    Board board;
    
    if(SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cerr << "Error Initializing SDL: " << SDL_GetError() << std::endl;
    }
    SDL_Window *win = SDL_CreateWindow("Minesweeper", 
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WIDTH, HEIGHT, 0);
    if(!win) {
        std::cerr << "Couldn't create window: " << SDL_GetError() << std::endl;
    }

    SDL_Surface *src = SDL_GetWindowSurface(win);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, 0);
    if(!renderer) {
        std::cerr << "Couldn't create renderer: " << SDL_GetError() << std::endl;
    }

    CreateBoard(board, renderer);
    ComputeCells(board, renderer);

    SDL_Event event;

    while(is_running) {
        for(auto &layer: board.field) {
            for(auto &cell: layer) {
                SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
                SDL_Texture *cell_texture;

                if(cell.is_hidden) {
                    cell_texture = cell.default_texture;
                } else {
                    cell_texture = cell.texture;
                }
                SDL_RenderCopy(renderer, cell_texture, NULL, &cell.DestR);
            }
        }
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    is_running = false;
                    break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            is_running = false;
                            break;
                        default:
                            break;
                    }
                case SDL_MOUSEMOTION:
                    std::cout << event.motion.x << " " << event.motion.y << std::endl;

                    Cell *cell = Get_Cell(board, event.motion.x, event.motion.y);

                    if(!cell) break;
                    else std::cout << cell->DestR.x << " " << cell->DestR.y << "WORKING!!!" << std::endl;

                    break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return EXIT_SUCCESS;
}
