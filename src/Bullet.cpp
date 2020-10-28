#include "../include/Bullet.hpp"

#include <cmath>

Bullet::Bullet(int x, int y) : angle(0) {
    w = 5;
    h = 5;

    this->x = x;
    this->y = y;
    
    alive = true;
}

double Bullet::Angle() {
    return angle;
}

void Bullet::Update() {
    double a = angle * (3.1415 / 180);

    x += 2 * sin(a);
    y -= 2 * cos(a);

    if (x > 800) angle += 180;
    if (x < 5) angle = 135;
    if (y > 800) alive = false;
    if (y < 0) angle += 180;

    if (angle >= 360) angle -= 360;
}

bool Bullet::Alive() {
    return alive;
}