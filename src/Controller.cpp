#include "../include/Controller.hpp"

#include "SDL2/SDL.h"

void Controller::HandleInput(std::shared_ptr<Player> player, bool& running) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type = SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_LEFT: MoveLeft(player); break;
            case SDLK_RIGHT: MoveRight(player); break;
            }
        }
    }
}

void Controller::MoveLeft(std::shared_ptr<Player> player) {
    player->x -= 20;
}

void Controller::MoveRight(std::shared_ptr<Player> player) {
    player->x += 20;
}