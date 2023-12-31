//
//  death.hpp
//  Game
//
//  Created by  on 25/10/23.
//

#ifndef death_hpp
#define death_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <iostream>
#include "Play_Music.hpp"
#include "Window_Create.hpp"
#include "Renderer_Create.hpp"
#include "Texture_Create.hpp"
#include "mouse.hpp"
#include "menu.hpp"
#include "FrontPage.hpp"

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
    SDL_Texture* background;
    
    SDL_Texture * fontTexture;
    SDL_Texture * menu_back;
    

    
    TTF_Font * font ;
    SDL_Color color ;
   
    bool play;
    char text[10];
    int character_no;
    
    Window_Create w;
    Renderer_Create r;
    Texture_Create t;
    
    
  
};

#endif /* death_hpp */
