#ifndef MAIN
#define MAIN

#include<stdio.h>
#include<SDL2/SDL.h>
#include"window.h"

int main(){ 
   struct Window window = create_window(100,100,5);
}

// This is extremely spaghetti, but I wanted to have a draw function in the main method for convenience, in the style of processingJS, since C does not support interfaces.
void render(struct Window* window){
   put_pixel(window, 50, 50);
}

void trace_ray(){
   
}


#endif