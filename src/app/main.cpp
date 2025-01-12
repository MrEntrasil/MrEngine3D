#include <SDL2/SDL.h>
#include "../window/Window.hpp"
#include <iostream>

void Window::on_heart(on_heart_t type)
{
    switch (type)
    {
        case on_heart_t::QUIT:
            this->Quit();
        default:
            break;
    }
    this->ChangeBackgroundColor(24, 24, 24, 255);
}

int main(int argc, char* argv[])
{
    Window* win = new Window("test window", 500, 350);
    win->InitLoop();

    return EXIT_SUCCESS;
}