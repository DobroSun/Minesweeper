#include "board.hpp"
#include "utils.hpp"
#include <iostream>

std::array<std::string, 2> image_paths {{ assets_path+"0.png", assets_path+"bomb.png" }};;

void CreateBoard(Board &board, SDL_Renderer *renderer) {
    int posx = 0; int posy = StartOfField;

    for(auto &layer: board.field) {
        for(auto &cell: layer) {
            int random_num = get_random(2);
            std::string path = image_paths[random_num];
            cell.is_bomb = random_num;


            cell.texture = make_texture(renderer, path);

            //SDL_Surface *image = IMG_Load("../assets/1.png");
            //cell.texture = SDL_CreateTextureFromSurface(renderer, image);
            //SDL_FreeSurface(image);

            cell.SrcR = make_SrcR(posx, posy);
            cell.DestR = make_DestR(posx, posy);
            
            if(posx+CellSize < WIDTH)
                posx += CellSize;
            else
                posx = 0;
        }
        posy += CellSize;
    }
}
