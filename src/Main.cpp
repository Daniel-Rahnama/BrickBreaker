#include "../include/Main.hpp"

int main() {
    Game game(Screen_Width, Screen_Height);

    Renderer renderer(Screen_Width, Screen_Height);

    Game.Run();

    return 0;
}