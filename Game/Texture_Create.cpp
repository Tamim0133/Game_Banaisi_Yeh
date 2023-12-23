//
//  Texture_Create.cpp
//  Game
//
//  Created by  on 10/11/23.
//

#include "Texture_Create.hpp"

SDL_Texture* Texture_Create:: Create_tex(string s, SDL_Renderer *ren){
    SDL_Surface * surf = IMG_Load(s.c_str());
    SDL_Texture * tex = SDL_CreateTextureFromSurface(ren, surf);
    
    
    
    return tex;
}

