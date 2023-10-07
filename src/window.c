#include"window.h"

void render(struct Window* window);

struct Window create_window(int width, int height, int scale){

    struct Window window;
    SDL_Init(SDL_INIT_VIDEO);

    window.width = width;
    window.height = height;
    window.scale = scale;

    window.window = SDL_CreateWindow("Graphics Programming from Scratch", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width * scale, height * scale, SDL_WINDOW_RESIZABLE);
    printf("Created window\n");

    window.renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetScale(window.renderer, scale, scale);
    printf("Created renderer\n");
    event_loop(&window);
    return window;
}

void destroy_window(struct Window* window){
    SDL_DestroyRenderer(window->renderer);
    printf("destrying renderer...\n");
    SDL_DestroyWindow(window->window);
    printf("destroying window...\n");
    SDL_Quit();
}

void put_pixel(struct Window* window, int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    SDL_SetRenderDrawColor(window->renderer, 0, 0, 0, 255);
    SDL_RenderClear(window->renderer);

    SDL_SetRenderDrawColor(window->renderer, red, green, blue, 255);
    SDL_RenderDrawPoint(window->renderer, x, y);

    SDL_RenderPresent(window->renderer);
}

void event_loop(struct Window* window){
    SDL_Event e;
    int quit = 0;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = 1;
            }
        }
        render(window);
    }
    destroy_window(window);
}

void render(struct Window* window){
    put_pixel(window, 50, 50, 255, 255, 255);
}
