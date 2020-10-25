#include "../include/Renderer.hpp"

#include <iostream>
#include <string>
#include <future>

Renderer::Renderer(std::size_t Screen_Width, std::size_t Screen_Height) : Screen_Width(Screen_Width), Screen_Height(Screen_Height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow("BrickBreaker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Screen_Width, Screen_Height, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        std::cout << "Window could not be created.\n";
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window,player -1 ,SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }
}

Renderer::~Renderer() {
    SDL_DestroyWindow(window)
    SDL_Quit();
}

void Renderer::Render(std::unique_ptr<Player> player, std::unique_ptr<Bullet> bullet, std::vector<std::unique_ptr<Brick>> bricks) {
    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);

    std::vector<std::future<void>> futures;

    futures.emplace_back(std::async(&Renderer::RenderPlayer, this, player));

    futures.emplace_back(std::async(&Renderer::RenderBullet, this, bullet));

    for (std::unique_ptr<Brick> brick& : bricks) 
        futures.emplace_back(std::async(&Renderer::RenderBrick, this, brick));

    for (std::future<void>& future : futures) future.wait();
}

void Renderer::RenderPlayer(std::unique_ptr<Player> player) {
    SDL_Rect* rect;

    rect->h = player->H();
    rect->w = player->W();
    rect->x = player->X();
    rect->y = player->Y();

    std::lock_guard<std::mutex>(RenderMtx);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, rect);
}

void Renderer::RenderBullet(std::unique_ptr<Bullet> bullet) {
    SDL_Rect* rect;

    rect->h = bullet->H();
    rect->w = bullet->W();
    rect->x = bullet->X();
    rect->y = bullet->Y();

    std::lock_guard<std::mutex>(RenderMtx);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, rect);
}

void Renderer::RenderBrick(std::unique_ptr<Brick> brick) {
    SDL_Rect* rect;

    rect->h = brick->H();
    rect->w = brick->W();
    rect->x = brick->X();
    rect->y = brick->Y();

    std::lock_guard<std::mutex>(RenderMtx);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, rect);
}

void Renderer::UpdateWindowTitle(unsigned int& FPS) {
    std::string title = "BrickBreaker FPS: " + FPS;
    SDL_SetWindowTitle(window, title.c_str());
}