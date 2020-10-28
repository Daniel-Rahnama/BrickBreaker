#ifndef GAME_HPP
#define GAME_HPP

#include "Renderer.hpp"
#include "Controller.hpp"

#include "Player.hpp"
#include "Bullet.hpp"
#include "Brick.hpp"

#include <memory>
#include <vector>

class Game {
public:
    Game(std::size_t, std::size_t);
    void Run(Renderer&, Controller&,const float&);
private:
    void Update(bool&, bool&);

    std::shared_ptr<Player> player;
    std::shared_ptr<Bullet> bullet;
    std::vector<std::shared_ptr<Brick>> bricks;

    std::size_t Grid_Width;
    std::size_t Grid_Height;
};

#endif /* GAME_HPP */