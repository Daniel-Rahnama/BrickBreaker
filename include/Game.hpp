#ifndef GAME_HPP
#define GAME_HPP

#include "Renderer.hpp"

#include "Player.hpp"
#include "Bullet.hpp"
#include "Brick.hpp"

#include <memory>
#include <vector>

class Game {
public:
    Game(std::size_t, std::size_t);
    void Run(Renderer&);
private:
    void Update(bool&);

    std::size_t Grid_Width;
    std::size_t Grid_Height;
};

#endif /* GAME_HPP */