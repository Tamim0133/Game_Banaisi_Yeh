//
//  menu.hpp
//  Game
//
//  Created by on 22/12/23.
//

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Window_Create.hpp"
#include "Renderer_Create.hpp"
#include "Texture_Create.hpp"
#include "Play_Music.hpp"
#include "mouse.hpp"
#include "Settings.hpp"
#include "variables.hpp"
#include "Credits.hpp"
#include "Tutorial.hpp"
#include "High_scores.hpp"
#include "Character_choose.hpp"

struct Menu{
    
public:
    Menu();
    void MenuPage_init();
    void initiate_textures();
    void fade(float elapsedTime);
    
private:
    bool running;
    bool game_has_opened;
    SDL_Event e;
    Window_Create w;
    Renderer_Create r;
    Texture_Create t;
    Settings_tab s;
    
    int mouse_posx = 0 , mouse_posy = 0;
    
    SDL_Window * menu_window;
    SDL_Renderer * menu_renderer;
    SDL_Texture * jungle_jump;
    SDL_Texture * table;
    SDL_Texture * right_edge;
    SDL_Texture * play_now;
    SDL_Texture * settings;
    SDL_Texture * credits;
    SDL_Texture * scores;
    SDL_Texture * how_to_play;
    
    SDL_Texture * play;
    SDL_Texture * jungle_text[5];
    SDL_Texture * click_play[2];
    SDL_Texture * jump_up_txt;
    SDL_Texture * jump_fall_txt;

    SDL_Rect jungle_rect = {0 , 0 , 640, 480};
    SDL_Rect table_rect = {100, 50, 400, 360};
    SDL_Rect play_edge_rect = {175, 85, 230, 60};
    SDL_Rect play_now_rect = {185, 105, 200, 18};
    SDL_Rect settings_edge_rect = {175, 138, 230, 60};
    SDL_Rect settings_rect = {185, 153, 170, 20};
    SDL_Rect set_image_at_1 = {420,296, 96,192};
    SDL_Rect set_image_at_2 = {74,-20, 96,192};
    SDL_Rect overlay = {0,0, 640, 480};

    SDL_Rect credits_edge_rect = {175, 183, 230, 60};
    SDL_Rect credits_rect = {185, 200, 150, 18};
    SDL_Rect scores_edge_rect = {175, 228, 230, 60};
    SDL_Rect scores_rect = {185, 247, 150, 18};
    SDL_Rect how_play_edge_rect = {175, 273, 230, 60};
    SDL_Rect how_to_play_rect = {185, 290, 225, 18};

    SDL_Rect play_rect = {240 , 265 , 160, 200};
    SDL_Rect jungle_text_rect = {120, 75, 400, 150};
    SDL_Rect jungle_text_rect2 = {120, 460, 400, 20};
    
};

#endif /* menu_hpp */
