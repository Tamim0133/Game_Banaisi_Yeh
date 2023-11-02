//
//  death.hpp
//  Game
//
//  Created by Tamim Dewan on 25/10/23.
//

#ifndef death_hpp
#define death_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>
using namespace std;

struct Death{
    public :
    
    void present_window(char text[]);
    
    private :

    SDL_Window* death_win;
    SDL_Renderer* death_ren;
    SDL_Surface* death_surface;
    SDL_Surface*  death_surface_bg;
    SDL_Surface*  got_hit;
    SDL_Surface * fontSurface;
    SDL_Texture* death_txt;
    SDL_Texture* death_bg_txt;
    SDL_Texture* got_hit_txt;
    SDL_Texture * fontTexture;
    
    TTF_Font * font ;
    SDL_Color color ;
   
    bool play = true;
    char text[10];
};

#endif /* death_hpp */
