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
void put_pixel(struct Window*, int x, int y);
void event_loop(struct Window* window);

#endif