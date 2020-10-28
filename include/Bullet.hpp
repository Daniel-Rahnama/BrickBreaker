#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"

class Bullet : public Entity {
public:
    Bullet(int, int);
    double Angle();
    void Update();
    bool Alive();
private:
    double angle;
    bool alive;
    friend class Brick;
    friend class Player;
};

#endif /* BULLET_HPP */