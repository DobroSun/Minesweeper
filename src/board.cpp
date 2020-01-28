#include "board.hpp"
#include "utils.hpp"
#include <iostream>
#include <stack>
#include <unordered_set>


std::string default_path = assets_path+"facingDown.png";
std::array<std::string, 2> image_cellbomb {{ assets_path+"factingDown.png", assets_path+"bomb.png" }};
std::array<std::string, 9> image_numbers 
            {{ assets_path+"0.png",
               assets_path+"1.png", assets_path+"2.png",
               assets_path+"3.png", assets_path+"4.png",
               assets_path+"5.png", assets_path+"6.png",
               assets_path+"7.png", assets_path+"8.png",
            }};


void CreateBoard(Board &board, SDL_Renderer *renderer) {
    int posx = LeftBound; int posy = UpperBound;

    std::srand(time(NULL));
    for(auto &layer: board.field) {
        for(auto &cell: layer) {
            int random_num = get_random();
            std::string path = image_cellbomb[random_num];

            cell.is_bomb = random_num;
            cell.is_hidden = true;

            cell.default_texture = make_texture(renderer, default_path);
            cell.texture = make_texture(renderer, path);

            cell.SrcR = make_SrcR(posx, posy); cell.DestR = make_DestR(posx, posy);
            
            if(posx+CellSize < RightBound)
                posx += CellSize;
            else
                posx = LeftBound;
        }
        posy += CellSize;
    }
}

void ComputeCells(Board &board, SDL_Renderer *renderer) {
    for(int i = 0; i < num_cells_on_height; i++) {
        for(int j = 0; j < num_cells_on_length; j++) {
            auto &field = board.field;
            auto &cell = field[i][j];

            if(cell.is_bomb) {
                cell.bombs_around = -1;
                continue;
            }
            
            std::array<std::pair<int, int>, 8> cells_around 
                    {{ {i-1, j-1}, {i-1, j}, {i-1, j+1},
                       {i, j-1},             {i, j+1},
                       {i+1, j-1}, {i+1, j}, {i+1, j+1},
                    }};
            for(auto &coords: cells_around) {
                int i_ind = std::get<0>(coords);
                int j_ind = std::get<1>(coords);

                if(cell_exists(i_ind, j_ind) && field[i_ind][j_ind].is_bomb) {
                    cell.bombs_around += 1;
                }
            }

            std::string path = image_numbers[cell.bombs_around];
            cell.texture = make_texture(renderer, path);
        }
    }
}

Cell *Get_Cell(Board &board, double x, double y) {
    if(x < LeftBound || x >= RightBound || y < UpperBound || y >= LowerBound) {
        return nullptr;
    }
    auto &field = board.field;
    
    int left; int right; int middle;
    left = 0; right = field[0].size() - 1;

    int res1 = - 1;
    while(left < right+1) {
        middle = (left + right)/2;
        if(field[0][middle].DestR.x < x) {
            left = middle+1;
        } else if(field[0][middle].DestR.x > x) {
            right = middle-1;
        } else {
            res1 = middle;
            break;
        }
    }
    if(res1 == -1) res1 = left-1;

    left = 0; right = field.size()-1;

    int res2 = -1;
    while(left < right+1) {
        middle = (left + right)/2;
        if(field[middle][res1].DestR.y < y) {
            left = middle+1;
        } else if(field[middle][res1].DestR.y > y) {
            right = middle-1;
        } else {
            res2 = middle;
            break;
        }
    }
    if(res2 == -1) res2 = left-1;

    return &field[res2][res1];
}

void OpenEmptyCells(Board &board, Cell *cell) {
    auto &field = board.field;
    std::unordered_set<Cell *> visited;
    std::stack<Cell *> stack;

    stack.push(cell);
    while(!stack.empty()) {
        Cell *cell = stack.top();
        cell->is_hidden = false;

        stack.pop();
        visited.insert(cell);


        int i = (cell->DestR.y - UpperBound)/CellSize;
        int j = (cell->DestR.x - LeftBound)/CellSize;

        std::array<std::pair<int, int>, 8> cells_around 
                {{ {i-1, j-1}, {i-1, j}, {i-1, j+1},
                   {i, j-1},             {i, j+1},
                   {i+1, j-1}, {i+1, j}, {i+1, j+1} }};
        for(auto &coords: cells_around) {
            int i_ind = std::get<0>(coords);
            int j_ind = std::get<1>(coords);

            if(!cell_exists(i_ind, j_ind)) continue;
            auto &cell = field[i_ind][j_ind];
            if(visited.find(&cell) == visited.end()) {
                if(cell.bombs_around == 0) {
                    stack.push(&cell);
                } else if(!cell.is_bomb) {
                    cell.is_hidden = false;
                }
            }
        }
    }
}

void GameOver(Board &board) {
    for(auto &layer: board.field) {
        for(auto &cell: layer) {
            cell.is_clickable = false;
            if(cell.is_bomb) {
                cell.is_hidden = false;
            }
        }
    }
}
