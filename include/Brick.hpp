#ifndef BRICK_HPP
#define BRICK_HPP

#include "Entity.hpp"
#include "Bullet.hpp"

#include <memory>

class Brick : public Entity {
public:
    Brick(int, int);
    bool Alive();
    void CollisionDetection(std::shared_ptr<Bullet>);
private:
    bool alive;
};

#endif /* BRICK_HPP */