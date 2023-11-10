//
//  Renderer_Create.cpp
//  Game_Final
//
//  Created by Tamim Dewan on 10/11/23.
//

#include "Renderer_Create.hpp"


SDL_Renderer* Renderer_Create :: Create_Renderer(SDL_Window *win){
    
    SDL_Renderer*  ren = SDL_CreateRenderer(win, -1, 0);
    
    if(ren == NULL){
        printf( "Renderer could not initialize! SDL_Error: %s\n", SDL_GetError());

    }
    return ren;
    
    

}
