//
//  Renderer_Create.hpp
//  Game_Final
//
//  Created by Tamim Dewan on 10/11/23.
//

#ifndef Renderer_Create_hpp
#define Renderer_Create_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

struct Renderer_Create{
public:
       SDL_Renderer * Create_Renderer( SDL_Window* win);
};

#endif /* Renderer_Create_hpp */
