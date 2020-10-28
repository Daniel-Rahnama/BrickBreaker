#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Bullet.hpp"

#include <memory>

class Player : public Entity {
public:
    Player(int, int);
    void CollisionDetection(std::shared_ptr<Bullet>);
    bool Alive();
private:
    friend class Controller;
};

#endif /* PLAYER_HPP */