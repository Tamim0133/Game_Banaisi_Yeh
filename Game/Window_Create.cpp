//
//  Window_Create.cpp
//  Game_Final
//
//  Created by Tamim Dewan on 10/11/23.
//

#include "Window_Create.hpp"
//converts a string to an array of characters with a null character at the endd

SDL_Window * Window_Create :: create_window(string s, int width , int height){
    SDL_Window * win = SDL_CreateWindow(s.c_str(),SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    
    if(win == NULL){
        printf( "Window could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    return win;
}
