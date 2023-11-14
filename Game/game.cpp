//
//  game.cpp
//  Game
//
//  Created by Tamim Dewan on 10/11/23.
//

#include "game.hpp"


Game:: Game(){
   
    Init();
    
    FPS = 90;
    frameDelay = (1000 / FPS); // Time per frame
    
    quit = false;
    point_count = 0;
    super_saiyan_has_started_from = 0;
    activate_ssj  = false;
    game_has_just_began = true;
    mana_constant = 0;
    jumpstate = 0;
    
    N1 = (rand() % 2) + 1;
    N2 = (rand() % 3) + 1;
    random_of_hundred = (rand() % 300);
    
    
    window = w.create_window("Game_Body", 640, 480); // Main game window
    renderer = r.Create_Renderer(window);

    Create_game_textures();
    
    SDL_ShowWindow(window);
    SDL_RaiseWindow(window);
      
    while (!quit)
      {
          Framestart = SDL_GetTicks();// SDL initialize hoyar pore kotokkhon hoise
          

          while (SDL_PollEvent(&event) != 0)
          {
              if(event.type == SDL_WINDOWEVENT
                 && event.window.event == SDL_WINDOWEVENT_CLOSE)
                  {
                      quit = true;break;
                  }
              switch (event.type)
              {
                     
                  case SDL_QUIT: quit = true; break;
                  case SDL_KEYDOWN:
                          switch (event.key.keysym.sym)
                          {
                              case SDLK_LEFT :  set_image_at.x-= 10; break;
                              case SDLK_a :  set_image_at.x-= 10; break;

                              case SDLK_RIGHT: set_image_at.x+= 10; break;
                              case SDLK_d: set_image_at.x+= 10; break;
                                  
                              case SDLK_UP: { Play_Music("assets/sounds/smb_kick.wav"); jumpstate = 1;} break;
                              case SDLK_SPACE:{ Play_Music("assets/sounds/smb_kick.wav"); jumpstate = 1; } break;
                              case SDLK_w: { Play_Music("assets/sounds/smb_kick.wav"); jumpstate = 1; } break;
                                  
                          } break;
              }
              
          }

          SDL_RenderClear(renderer);//Clear the current rendering
          
          Move_everything();
          
          SDL_RenderCopy(renderer, mountains, NULL, &mountain1); // Bg Image
          SDL_RenderCopy(renderer, mountains, NULL, &mountain2);

          
          if(activate_ssj)  {Activate_ability();}
          
          if(jumpstate == 1)  {Show_jump();}
          
          if(jumpstate == 2) {Show_fall();}
          
          Detect_collision();
          
          if(game_has_just_began){ Play_Music("assets/sounds/game_start.wav");game_has_just_began = false;}
            
          Render_Coins();
          
          no_of_image = (Framestart / 100) % 6;
          if(jumpstate == 0)SDL_RenderCopy(renderer, running[no_of_image], NULL, &set_image_at);
          
          SDL_RenderCopy(renderer, rock_mons_tex, NULL , &rock_monster_01);
          SDL_RenderCopy(renderer, mana_txt, NULL , &mana_potion);
          
          int no_of_enemy = (Framestart/100) % 2;
          SDL_RenderCopy(renderer, enemy[no_of_enemy], NULL, &enemy_01);
          SDL_RenderCopy(renderer, enemy2[no_of_enemy], NULL, &enemy_03);
      
          Show_point();

          SDL_RenderPresent(renderer);//Update the screen with any rendering 
          
          FrameTime = SDL_GetTicks() - Framestart;
          if(frameDelay > FrameTime)// frame delay = 1000/fps ; current frame time kom hole
          {
              SDL_Delay(frameDelay - FrameTime);
          }
          
      }

      TTF_Quit();
      SDL_DestroyTexture(texture);
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      IMG_Quit();
      SDL_Quit();
  
}

void Game:: Init(){
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }
        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_PNG);
        TTF_Init();
        SDL_Init(SDL_INIT_AUDIO);
    

}

void Game:: Create_game_textures(){
 
    coin[0] = t.Create_tex("assets/coins/coin_01.png", renderer);
    coin[1] = t.Create_tex("assets/coins/coin_02.png", renderer);
    coin[2] = t.Create_tex("assets/coins/coin_03.png", renderer);
    coin[3] = t.Create_tex("assets/coins/coin_04.png", renderer);
    coin[4] = t.Create_tex("assets/coins/coin_05.png", renderer);
    coin[5] = t.Create_tex("assets/coins/coin_06.png", renderer);
    coin[6] = t.Create_tex("assets/coins/coin_07.png", renderer);
    coin[7] = t.Create_tex("assets/coins/coin_08.png", renderer);

    texture = t.Create_tex("sprite/running/run.png", renderer);
    
    rock_mons_tex = t.Create_tex("sprite/enemy/idle/rock_monster.png", renderer);
    
    mana_txt = t.Create_tex("sprite/enemy/idle/mana_potion.png", renderer);

    ssj_txt = t.Create_tex("sprite/idle/aura.png", renderer);
    
    mountains = t.Create_tex("assets/bg_2.png", renderer);

    running[0] = t.Create_tex("sprite/running/frame-1.png", renderer);
    running[1] = t.Create_tex("sprite/running/frame-2.png", renderer);
    running[2] = t.Create_tex("sprite/running/frame-3.png", renderer);
    running[3] = t.Create_tex("sprite/running/frame-4.png", renderer);
    running[4] = t.Create_tex("sprite/running/frame-5.png", renderer);
    running[5] = t.Create_tex("sprite/running/frame-6.png", renderer);
    
    jump_up[0] = t.Create_tex("sprite/standing/frame-1.png", renderer);
    jump_up[1] = t.Create_tex("sprite/jump/jump_up.png", renderer);

    jumo_fall_txt = t.Create_tex("sprite/jump/jump_fall.png", renderer);
    
    enemy[0] = t.Create_tex("sprite/enemy/idle/frame-1.png", renderer);
    enemy[1] = t.Create_tex("sprite/enemy/idle/frame-2.png", renderer);
    
    enemy2[0] = t.Create_tex("sprite/enemy/idle/frame-3.png", renderer);
    enemy2[1] = t.Create_tex("sprite/enemy/idle/frame-4.png", renderer);
}

void Game :: Move_everything(){
    
    mountain1.x --;
    mountain2.x --;
    if(mountain1.x < -639) mountain1.x = 640;
    if(mountain2.x < -639) mountain2.x = 640;
    
    enemy_01.x -= N1;
    enemy_02.x -=  N2;
    enemy_03.x -= N1;
    enemy_04.x -=  N2;
    
    if(enemy_01.x < -639) enemy_01.x = 5120;
    if(enemy_02.x < -639) enemy_02.x = 5120;
    if(enemy_03.x < -639) enemy_03.x = 5120;
    if(enemy_04.x < -639) enemy_04.x = 5120;
    
    
    coin_01.x --;
    coin_02.x --;
    coin_03.x --;
    coin_04.x --;
    coin_05.x --;
    coin_06.x --;
    
    if(coin_01.x < 0) coin_01.x = 640 + random_of_hundred;
    if(coin_01.y < 392) coin_01.y = 392;
    if(coin_02.x < 0) coin_02.x = 640 + random_of_hundred;
    if(coin_03.x < 0) coin_03.x = 640 + random_of_hundred;
    if(coin_04.x < 0) coin_04.x = 640 + random_of_hundred;
    if(coin_05.x < 0) coin_05.x = 640 + random_of_hundred;
    if(coin_06.x < 0) coin_06.x = 640 + random_of_hundred;
    
    rock_monster_01.x--;
    if(rock_monster_01.x < -639) rock_monster_01.x = 900 + random_of_hundred;
    
    mana_potion.x--;
    if(mana_potion.x < -10) {mana_potion.x += 3000; }
    
}

void Game :: Render_Coins(){
    int no_of_coin = (SDL_GetTicks() / 100) % 8;

    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_01);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_02);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_03);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_04);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_05);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_06);
}

void Game:: Detect_collision(){
    
    SDL_Rect hero_rect = {set_image_at.x , set_image_at.y + set_image_at.h/2, set_image_at.w/2, set_image_at.h/2};
    SDL_Rect enemy_01_rect = {enemy_01.x , enemy_01.y + enemy_01.h/2 , enemy_01.w/2, enemy_01.h/2};
    SDL_Rect enemy_03_rect = {enemy_03.x , enemy_03.y + enemy_03.h/2, enemy_03.w/2, enemy_03.h/2};
    SDL_Rect mana_potion_rect = {mana_potion.x , mana_potion.y + mana_potion.h/2 , mana_potion.w/2 , mana_potion.h/2};
    SDL_Rect rock_monster_rect = {rock_monster_01.x , rock_monster_01.y + rock_monster_01.h/2 , rock_monster_01.w/2 ,rock_monster_01.h/3};

    
    SDL_bool  collision_hero_enemy_01 = SDL_HasIntersection(&hero_rect, &enemy_01_rect);
    SDL_bool collision_hero_enemy_03 = SDL_HasIntersection(&hero_rect, &enemy_03_rect);
    SDL_bool collision_hero_mana_potion = SDL_HasIntersection(&hero_rect, &mana_potion_rect);
    SDL_bool collision_with_rock_monster = SDL_HasIntersection(&hero_rect, &rock_monster_rect);
    SDL_bool collision_with_coin_01 = SDL_HasIntersection(&set_image_at, &coin_01);
    SDL_bool collision_with_coin_02 = SDL_HasIntersection(&set_image_at, &coin_02);
    SDL_bool collision_with_coin_03 = SDL_HasIntersection(&set_image_at, &coin_03);
    SDL_bool collision_with_coin_04 = SDL_HasIntersection(&set_image_at, &coin_04);
    SDL_bool collision_with_coin_05 = SDL_HasIntersection(&set_image_at, &coin_05);
    SDL_bool collision_with_coin_06 = SDL_HasIntersection(&set_image_at, &coin_06);

    
    
    if(collision_hero_enemy_01 or collision_hero_enemy_03 or collision_with_rock_monster)
    {Play_Music("assets/sounds/smb_gameover.wav");
        d.present_window(text);quit = true;}

    if(collision_with_coin_01) { Play_Music("assets/sounds/smb_coin.wav"); coin_01.x = - 100; point_count++; }
    if(collision_with_coin_02) { Play_Music("assets/sounds/smb_coin.wav"); coin_02.x = -200; point_count++; }
    if(collision_with_coin_03) { Play_Music("assets/sounds/smb_coin.wav"); coin_03.x = -100; point_count++;}
    if(collision_with_coin_04) { Play_Music("assets/sounds/smb_coin.wav"); coin_04.x = - 100; point_count++;}
    if(collision_with_coin_05) { Play_Music("assets/sounds/smb_coin.wav"); coin_05.x = -200; point_count++;}
    if(collision_with_coin_06) { Play_Music("assets/sounds/smb_coin.wav"); coin_06.x = -100; point_count++;}
    
    if(collision_hero_mana_potion){
        Play_Music("assets/sounds/smb_powerup.wav");
        mana_potion.x += 3200;
        super_saiyan_has_started_from = SDL_GetTicks();
        activate_ssj = true; mana_constant = 50;
    }

}

void Game :: Activate_ability(){
    
    int ssj_sprite = (SDL_GetTicks()/100) % 4;

    SDL_Rect super_saiyan_aura_src = {ssj_sprite * 204, 0, 204,220};
    SDL_Rect super_saiyan_aura_dest = {set_image_at.x - 90, set_image_at.y-50, 210, 200};
    
    SDL_RenderCopy(renderer, ssj_txt, &super_saiyan_aura_src, &super_saiyan_aura_dest);
    
    if(SDL_GetTicks() - super_saiyan_has_started_from > 7000)
    { activate_ssj = 0; super_saiyan_has_started_from = 0; mana_constant = 0;}
    
}

void Game :: Show_point(){
    
    font = TTF_OpenFont("assets/fonts/terminal_font.ttf", 40);
    color = { 255, 255, 255 };
    
    for(int i = 0; i < 9; i++){
        text [i] = '0';
    }
    text[9] = '\0';
    
    int temp = point_count;
    int pos = 8;
    
    while(temp>0)
    {
        int r = temp % 10;
        temp = temp / 10;
        char ch = r + 48;
        text[pos] = ch;
        pos--;
    }
    
    SDL_Surface * fontSurface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture * fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);
   
    int texW = 0; int texH = 0;
    SDL_QueryTexture(fontTexture, NULL, NULL, &texW, &texH);
    SDL_Rect fontDstRect = { 630 - texW, 10, texW, texH };
    
    SDL_RenderCopy(renderer, fontTexture, NULL, &fontDstRect);
    SDL_RenderCopy(renderer, fontTexture, NULL, &fontDstRect);
}

void Game :: Show_jump(){
    SDL_RenderCopy(renderer, jump_up[1], NULL, &set_image_at);
    set_image_at.y -= 2;
    if(set_image_at.y < 170 - mana_constant) jumpstate = 2;
}

void Game :: Show_fall(){
    SDL_RenderCopy(renderer, jumo_fall_txt, NULL, &set_image_at);
    set_image_at.y += 2;
    
    if(set_image_at.y >= 296)
    { set_image_at.y= 296;jumpstate = 0;}
}
