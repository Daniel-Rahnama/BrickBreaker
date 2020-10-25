#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"

class Bullet : public Entity {
public:
    Bullet(int, int);
    double Angle();
    bool Moving();
private:
    double angle;
    bool moving;
    bool alive;
};

#endif /* BULLET_HPP */