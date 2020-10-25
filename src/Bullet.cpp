#include "../include/Bullet.hpp"

Bullet::Bullet(int x, int y) : angle(0), moving(0) {
    w = 5;
    h = 5;
    this->x = x;
    this->y = y;
    
    alive = true;
}

double Bullet::Angle() {
    return angle;
}

bool Bullet::Moving() {
    return moving;
}