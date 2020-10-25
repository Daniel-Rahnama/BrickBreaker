#ifndef BRICK_HPP
#define BRICK_HPP

#include "Entity.hpp"

class Brick : public Entity {
public:
    Brick(int, int);
    bool Alive();
private:
    bool alive;
};

#endif /* BRICK_HPP */