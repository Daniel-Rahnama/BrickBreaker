#include "../include/Main.hpp"

int main() {
    Game game(Screen_Width, Screen_Height);

    Renderer renderer(Screen_Width, Screen_Height);

    game.Run(renderer);

    return 0;
}