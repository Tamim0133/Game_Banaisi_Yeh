//
//  Texture_Create.hpp
//  Game
//
//  Created by Tamim Dewan on 10/11/23.
//

#ifndef Texture_Create_hpp
#define Texture_Create_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
using namespace std;

struct Texture_Create{
public:
    SDL_Texture * Create_tex(string s, SDL_Renderer* ren);
};
#endif /* Texture_Create_hpp */
