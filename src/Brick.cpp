#include "../include/Brick.hpp" 

Brick::Brick(int x, int y) {
    w = 25;
    h = 25;
    this->x = x;
    this->y = y;

    alive = true;
}

bool Brick::Alive() {
    return alive;
}

#include <iostream>
void Brick::CollisionDetection(std::shared_ptr<Bullet> bullet) {
    int x1 = x - w;
    int x2 = x + w;
    
    int y1 = y - h;
    int y2 = y + h;

    int bx1 = bullet->x - bullet->w;
    int bx2 = bullet->x + bullet->w;

    int by1 = bullet->y - bullet->h;
    int by2 = bullet->y + bullet->h;

    if (x1 <= bx2 && x2 >= bx1 && y1 <= by2 && y2 >= by1) {

        alive = false;

        bullet->angle += 180;
        if (bullet->angle > 360) bullet->angle -= 360;
    }
}