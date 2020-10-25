#include "../include/Brick.hpp" 

Brick::Brick(int x, int y) {
    w = 50;
    h = 50;
    this->x = x;
    this->y = y;

    alive = true;
}

bool Brick::Alive() {
    return alive;
}