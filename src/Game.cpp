#include "../include/Game.hpp"

#include "SDL2/SDL.h"

#include <iostream>
#include <algorithm>

Game::Game(std::size_t Grid_Width, std::size_t Grid_Height) : Grid_Width(Grid_Width), Grid_Height(Grid_Height) {
    player = std::make_shared<Player>(400, 750);
    bullet = std::make_shared<Bullet>(400, 500);
    bricks.emplace_back(std::make_shared<Brick>(600, 50));
    bricks.emplace_back(std::make_shared<Brick>(600, 200));
    bricks.emplace_back(std::make_shared<Brick>(200, 50));
    bricks.emplace_back(std::make_shared<Brick>(200, 200));
}

void Game::Run(Renderer& renderer, Controller& controller, const float& Target_Frame_Duration) {
    Uint32 Title_Timestamp = SDL_GetTicks();
    Uint32 Frame_Start;
    Uint32 Frame_End;
    Uint32 Frame_Duration;
    unsigned int Frame_Count;

    bool running = true;

    bool won = false;

    while (running) {
        Frame_Start = SDL_GetTicks();

        controller.HandleInput(player, running);

        Update(running, won);

        renderer.Render(player, bullet, bricks);

        Frame_End = SDL_GetTicks();

        Frame_Duration = Frame_End - Frame_Start;
        Frame_Count++;

        if (Frame_End - Title_Timestamp >= 1000) {
            renderer.UpdateWindowTitle(Frame_Count);
            std::cout << Frame_Count << std::endl;
            Frame_Count = 0;
            Title_Timestamp = Frame_End;
        }

        if (Frame_Duration < Target_Frame_Duration) {
            SDL_Delay(Target_Frame_Duration - Frame_Duration);
        }
    }
    std::cout << "Game Over" << std::endl;
    if (won) std::cout << "You Win!" << std::endl;
    else std::cout << "You Lose!" << std::endl;
}

void Game::Update(bool& running, bool& win) {
    bullet->Update();
    
    for (std::shared_ptr<Brick>& b : bricks) {
        b->CollisionDetection(bullet);
    }

    player->CollisionDetection(bullet);

    if (!bricks.empty()) bricks.erase(std::remove_if(bricks.begin(), bricks.end(), [](std::shared_ptr<Brick> b) { return !b->Alive(); }), bricks.end());

    if (bricks.empty()) running = false;

    if (!bullet->Alive()) {
        running = false;
    }
}