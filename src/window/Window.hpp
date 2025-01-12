#pragma once
#include <SDL2/SDL.h>

enum class on_heart_t
{
    QUIT
};

class Window
{
private:
    SDL_Renderer* colorRenderer;
    SDL_Window* window;
public:
    bool isRunning = true;
    Window(const char* title, const int w, const int y)
    {
        this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)w, (int)y, SDL_WINDOW_SHOWN);
        this->colorRenderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    }
    void ChangeBackgroundColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
    {
        SDL_SetRenderDrawColor(this->colorRenderer, r, g, b, a);
        SDL_RenderClear(this->colorRenderer);
        SDL_RenderPresent(this->colorRenderer);
    }
    void InitLoop()
    {
        SDL_Event Event;
        while (this->isRunning)
        {
            if (SDL_PollEvent(&Event))
            {
                switch (Event.type)
                {
                case SDL_QUIT:
                    this->on_heart(on_heart_t::QUIT);
                    break;
                }
            }
        }
    }
    void Quit()
    {
        this->isRunning = false;
        SDL_DestroyWindow(this->window);
        SDL_DestroyRenderer(this->colorRenderer);
        SDL_Quit();
    }
    void on_heart(on_heart_t type);
};