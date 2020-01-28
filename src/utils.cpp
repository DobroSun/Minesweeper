#include "utils.hpp"
#include <cstdlib>

int get_random(int stop) {
    return std::rand() % stop && std::rand() % stop;
}
