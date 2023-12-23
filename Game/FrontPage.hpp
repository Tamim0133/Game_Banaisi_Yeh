//
//  FrontPage.hpp
//  Game
//
//  Created by on 13/11/23.
//

#ifndef FrontPage_hpp
#define FrontPage_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Window_Create.hpp"
#include "Renderer_Create.hpp"
#include "Texture_Create.hpp"
#include "Play_Music.hpp"
#include "mouse.hpp"
#include "menu.hpp"

struct FrontPage{
    
public:
    FrontPage();
    void FrontPage_init();
    void initiate_textures();
    
private:
    bool running;
    bool game_has_opened;
    
    SDL_Event e;
    Window_Create w;
    Renderer_Create r;
    Texture_Create t;
    
    
    int mouse_posx = 0 , mouse_posy = 0;
    
    SDL_Window * front_window;
    SDL_Renderer * front_renderer;
    
    //Textures
    //---------------------------
    SDL_Texture * jungle_jump;
    SDL_Texture * play;
    SDL_Texture * jungle_text[5];
    SDL_Texture * click_play[2];
    
    // Rectangles
    //--------------------------------------------
    SDL_Rect jungle_rect = {0 , 0 , 640, 480};
    SDL_Rect play_rect = {240 , 265 , 160, 200};
    SDL_Rect jungle_text_rect = {120, 75, 400, 150};
    SDL_Rect jungle_text_rect2 = {120, 460, 400, 20};
    
};
#endif /* FrontPage_hpp */
