#include "../include/Main.hpp"

int main() {
    constexpr float Screen_Width = 800;
    constexpr float Screen_Height = 800;
    constexpr float Target_FPS = 60;
    constexpr float Target_Frame_Duration = Target_FPS / 1000;
    
    Game game(Screen_Width, Screen_Height);

    Renderer renderer(Screen_Width, Screen_Height);

    Controller controller;

    game.Run(renderer, controller, Target_Frame_Duration);

    return 0;
}