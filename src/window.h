#ifndef WINDOW
#define WINDOW

#include<stdio.h>
#include<SDL2/SDL.h>

struct Window{
    int width;
    int height;
    int scale;

    SDL_Window* window;
    SDL_Renderer* renderer;
};

struct Window create_window(int width, int height, int scale);
void put_pixel(struct Window* window, int x, int y, Uint8 red, Uint8 green, Uint8 blue);
void event_loop(struct Window* window);

#endif