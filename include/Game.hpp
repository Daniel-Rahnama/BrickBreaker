#ifndef GAME_HPP
#define GAME_HPP

#include "Main.hpp"

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

    std::shared_ptr<Player> player;
    std::shared_ptr<Bullet> bullet;
    std::vector<std::shared_ptr<Brick>> bricks;

    std::size_t Grid_Width;
    std::size_t Grid_Height;
};

#endif /* GAME_HPP */