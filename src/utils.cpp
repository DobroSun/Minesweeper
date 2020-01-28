#include "utils.hpp"
#include <cstdlib>
#include <iostream>

int get_random() {
    return (rand() % 100) < 20;
}
