#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* Window;
    Window = SDL_CreateWindow("Janela Teste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
    if (Window == NULL)
    {
        std::cout << "Cannot open window. Error: " << SDL_GetError() << "\n";
        return EXIT_FAILURE;
    }

    SDL_Event Event;
    while (true)
    {
        if (SDL_PollEvent(&Event))
        {
            switch (Event.type)
            {
            case SDL_QUIT:
                SDL_DestroyWindow(Window);
                SDL_Quit();
                exit(EXIT_SUCCESS);
            }
        }
    }

    SDL_DestroyWindow(Window);
    SDL_Quit();
    return EXIT_SUCCESS;
}