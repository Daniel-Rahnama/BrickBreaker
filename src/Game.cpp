#include "../include/Game.hpp"

#include <SDL2/SDL.h>

Game::Game(int, int) {

}

void Game::Run() {
    Uint32 Title_Timestamp = SDL_GetTicks();
    Uint32 Frame_Start;
    Uint32 Frame_End;
    Uint32 Frame_Duration;
    unsigned int Frame_Count;

    bool running = true;

    while (running) {
        Frame_Start = SDL_GetTicks();

        // controller.HandleInput();

        Update(running);

        // renderer.Render();

        Frame_End = SDL_GetTicks();

        Frame_Duration = Frame_End - Frame_Start;
        Frame_Count++;

        if (Frame_End - Title_Timestamp > 1000) {
            // renderer.UpdateWindowTitle(Score, Frame_Count);
            Frame_Count = 0;
            Title_Timestamp = Frame_End;
        }

        if (Frame_Duration < Target_Frame_Duration) {
            SDL_Delay(Target_Frame_Duration - Frame_Duration);
        }
    }
}

void Game::Update(bool& running) {

}