#include "../include/Player.hpp"

Player::Player(int x, int y) {
    this->x = x;
    this->y = y;

    this->w = 50;
    this->h = 10;
}

void Player::CollisionDetection(std::shared_ptr<Bullet> bullet) {
    int x1 = x - w;
    int x2 = x + w;
    
    int y1 = y - h;
    int y2 = y + h;

    int bx1 = bullet->x - bullet->w;
    int bx2 = bullet->x + bullet->w;

    int by1 = bullet->y - bullet->h;
    int by2 = bullet->y + bullet->h;

    if (x1 <= bx2 && x2 >= bx1 && y1 <= by2 && y2 >= by1) {
        int distance = bullet->x - x;
        bullet->angle = (360 + (distance * 1.5));
    }
}