#include "utils.hpp"
#include <cstdlib>
#include <iostream>

int get_random() {
    return std::rand() % 2 && std::rand() % 2;
}
