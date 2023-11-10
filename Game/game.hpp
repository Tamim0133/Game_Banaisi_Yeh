//
//  game.hpp
//  Game
//
//  Created by Tamim Dewan on 10/11/23.
//

#ifndef game_hpp
#define game_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <iostream>
#include "death.hpp"
#include "Sound.hpp"
#include "Play_Music.hpp"
#include "Window_Create.hpp"
#include "Renderer_Create.hpp"
#include "Texture_Create.hpp"
using namespace std;


struct Game {
public:
    Game();
    void Init();
    void Render_Coins();
    void Create_game_textures();
    void Move_everything();
    void Detect_collision();
    void Activate_ability();
    void Show_point();
    void Show_jump();
    void Show_fall();
    
private:
    Death d;
    Window_Create w;
    Renderer_Create r;
    Texture_Create t;
    
    Uint32 Framestart;
    bool quit;
    int FrameTime;
    int point_count;
    int FPS;
    int frameDelay;
    int no_of_image;
    int N1;
    int N2;
    int random_of_hundred;
    int super_saiyan_has_started_from;
    bool activate_ssj;
    bool game_has_just_began;
    int mana_constant;
    int jumpstate;
    int new_frame_till_jump_complete;
    char text[10];

    

    
    SDL_Event event;
    SDL_Window * window;
    SDL_Renderer * renderer;
    TTF_Font * font;
    SDL_Color color;
   
    
    SDL_Rect coin_01 = { 1280, 392 , 32, 32};
    SDL_Rect coin_02 = { 1240, 392 , 32, 32};
    SDL_Rect coin_03 = { 1200, 392 , 32, 32};
    SDL_Rect coin_04 = { 1160, 392 , 32, 32};
    SDL_Rect coin_05 = { 1120, 392 , 32, 32};
    SDL_Rect coin_06 = { 1080, 392 , 32, 32};
    
    SDL_Rect set_image_at = {84,296, 64,128};
    SDL_Rect super_saiyan_dest = {-10, 280, 142,144};
    
    
    SDL_Rect dstrect = { 50, 300, 130, 140 };
    SDL_Rect srcrect2 = { 0, 0, 130, 140 };
    
    
    SDL_Rect enemy_01 = {1280, 360 , 64, 64};
    SDL_Rect enemy_02 = {2560, 360 , 64, 64};
    SDL_Rect enemy_03 = {3840, 360 , 64, 64};
    SDL_Rect enemy_04 = {5120, 360 , 64, 64};
    
    SDL_Rect mana_potion = {2600 , 360, 64, 64};
    
    SDL_Rect mountain1 = {0, 0 , 640, 480};
    SDL_Rect mountain2 = {640, 0 , 640, 480};
    
    SDL_Rect rock_monster_01 = {1280 + (rand() % 300) , 360, 64, 64};


    SDL_Texture* coin[8];
    SDL_Texture * texture;
    SDL_Texture * rock_mons_tex;
    SDL_Texture * mana_txt;
    SDL_Texture* ssj_txt;
    SDL_Texture* mountains;
    SDL_Texture* running[6];
    SDL_Texture* jump_up[2];
    SDL_Texture * jumo_fall_txt;
    SDL_Texture* enemy[2];
    SDL_Texture* enemy2[2];
};

#endif /* game_hpp */
