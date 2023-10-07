#include<stdio.h>
#include<SDL2/SDL.h>

#define WIDTH 640
#define HEIGHT 480
#define SCALE 1


int main(){
   
   SDL_Init(SDL_INIT_VIDEO);

   SDL_Window* window;
   window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH * SCALE, HEIGHT * SCALE, SDL_WINDOW_RESIZABLE);
   printf("Created window\n");

   SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   printf("Created renderer\n");

   SDL_Event e;
   int quit = 0;
   while (!quit){
      while (SDL_PollEvent(&e)){
         if (e.type == SDL_QUIT){
               quit = 1;
         }
      }
   }

   printf("closing window...\n");
   SDL_DestroyWindow(window);

   SDL_Quit();
}