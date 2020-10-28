#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Player.hpp"

#include <memory>

class Controller {
public:
    void HandleInput(std::shared_ptr<Player>, bool&);
private:
    void MoveLeft(std::shared_ptr<Player>);
    void MoveRight(std::shared_ptr<Player>);
};

#endif /* CONTROLLER_HPP */