#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "SDL2/SDL.h"

#include "Brick.hpp"
#include "Bullet.hpp"
#include "Player.hpp"

#include <memory>
#include <vector>
#include <mutex>

class Renderer {
public:
    Renderer(std::size_t, std::size_t);
    ~Renderer();
    void Render(std::unique_ptr<Player>, std::unique_ptr<Bullet>, std::vector<std::unique_ptr<Brick>>);
    void UpdateWindowTitle(unsigned int&);
private:
    void RenderPlayer(std::unique_ptr<Player>);
    void RenderBullet(std::unique_ptr<Bullet>);
    void RenderBrick(std::unique_ptr<Brick>);

    SDL_Window* window;
    SDL_Renderer* renderer;

    std::size_t Screen_Width;
    std::size_t Screen_Height;

    std::mutex RenderMtx;
};

#endif /* RENDERER_HPP */