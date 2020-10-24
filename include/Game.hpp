#ifndef GAME_HPP
#define GAME_HPP

#include "Main.hpp"

class Game {
public:
    Game(int, int);
    void Run();
private:
    void Update(bool&);
};

#endif /* GAME_HPP */