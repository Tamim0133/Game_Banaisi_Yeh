//
//  game.cpp
//  Game
//
//  Created by Tamim Dewan on 10/11/23.
//

#include "game.hpp"

Game:: Game(){
    Death d;
    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    Mix_Chunk * startSound =   Mix_LoadWAV("assets/sounds/game_start.wav");
    Mix_Chunk * endSound =  Mix_LoadWAV("assets/sounds/smb_gameover.wav");
    Mix_Chunk * jumpSound = Mix_LoadWAV("assets/sounds/smb_kick.wav");
    Mix_Chunk * manaPotionSound =   Mix_LoadWAV("assets/sounds/smb_powerup.wav");
    Mix_Chunk * coinSound = Mix_LoadWAV("assets/sounds/smb_coin.wav");


    char text[10] = {'0','0', '0','0','0','0','0','0','0','\0'};
    bool quit = false;
      SDL_Event event;
   
    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL Library
    IMG_Init(IMG_INIT_PNG);   // Initialize SDL_Image
    TTF_Init(); // Initializing TTF library
    SDL_Init(SDL_INIT_AUDIO);
    
    int point_count = 0;
    string point = to_string(point_count);
      SDL_Window * window = SDL_CreateWindow("SDL2 Sprite Sheets",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0); // window Banailam
      SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);  // Window Renderer
    
    
    TTF_Font * font = TTF_OpenFont("assets/fonts/terminal_font.ttf", 40);
    SDL_Color color = { 255, 255, 255 };
    
    

    
    int FPS = 90;
    const int frameDelay = 1000 / FPS;
    Uint32 Framestart ;
    int FrameTime;
    int no_of_image = 0;//
    int N1 = (rand() % 2) + 1;
    int N2 = (rand() % 3) + 1;
    int random_of_hundred = (rand() % 300);
    
    SDL_Surface * image = IMG_Load("sprite/running/run.png");     // Texture Surface
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image); // Texture (specific representation of pixel data)
    
    SDL_Surface * frame_1 = IMG_Load("sprite/running/frame-1.png");     // Texture Surface
    SDL_Texture * texture1 = SDL_CreateTextureFromSurface(renderer, frame_1); // Texture (specific representation of pixel data)
    SDL_Surface * frame_2 = IMG_Load("sprite/running/frame-2.png");     // Texture Surface
    SDL_Texture * texture2 = SDL_CreateTextureFromSurface(renderer, frame_2); // Texture (specific representation of pixel data)
    SDL_Surface * frame_3 = IMG_Load("sprite/running/frame-3.png");     // Texture Surface
    SDL_Texture * texture3 = SDL_CreateTextureFromSurface(renderer, frame_3); // Texture (specific representation of pixel data)
    SDL_Surface * frame_4 = IMG_Load("sprite/running/frame-4.png");     // Texture Surface
    SDL_Texture * texture4 = SDL_CreateTextureFromSurface(renderer, frame_4); // Texture (specific representation of pixel data)
    SDL_Surface * frame_5 = IMG_Load("sprite/running/frame-5.png");     // Texture Surface
    SDL_Texture * texture5 = SDL_CreateTextureFromSurface(renderer, frame_5); // Texture (specific representation of pixel data)
    SDL_Surface * frame_6 = IMG_Load("sprite/running/frame-6.png");     // Texture Surface
    SDL_Texture * texture6 = SDL_CreateTextureFromSurface(renderer, frame_6); // Texture (specific representation of pixel data)
    
    SDL_Surface * standing_01 = IMG_Load("sprite/standing/frame-1.png");     // Texture Surface
    SDL_Texture * standing_tex = SDL_CreateTextureFromSurface(renderer, standing_01); // Texture (specific representation of pixel data)
    SDL_Surface * standing_02 = IMG_Load("sprite/standing/frame-2.png");     // Texture Surface
    SDL_Texture * standing2_tex = SDL_CreateTextureFromSurface(renderer, standing_02); // Texture (specific representation of pixel data)
    SDL_Surface * jump_01 = IMG_Load("sprite/jump/jump_up.png");     // Texture Surface
    SDL_Texture * jump_up_txt = SDL_CreateTextureFromSurface(renderer, jump_01); // Texture (specific representation of pixel data)
    SDL_Surface * jump_02 = IMG_Load("sprite/jump/jump_fall.png");     // Texture Surface
    SDL_Texture * jumo_fall_txt = SDL_CreateTextureFromSurface(renderer, jump_02); // Texture (specific representation of pixel data)
    
    
    
    SDL_Surface * coin1 = IMG_Load("assets/coins/coin_01.png");     // Texture Surface
    SDL_Texture * coin1_tex = SDL_CreateTextureFromSurface(renderer, coin1); // Texture (specific representation of pixel data)
    SDL_Surface * coin2 = IMG_Load("assets/coins/coin_02.png");     // Texture Surface
    SDL_Texture * coin2_tex = SDL_CreateTextureFromSurface(renderer, coin2); // Texture (specific representation of pixel data)
    SDL_Surface * coin3 = IMG_Load("assets/coins/coin_03.png");     // Texture Surface
    SDL_Texture * coin3_tex = SDL_CreateTextureFromSurface(renderer, coin3); // Texture (specific representation of pixel data)
    SDL_Surface * coin4 = IMG_Load("assets/coins/coin_04.png");     // Texture Surface
    SDL_Texture * coin4_tex = SDL_CreateTextureFromSurface(renderer, coin4); // Texture (specific representation of pixel data)
    SDL_Surface * coin5 = IMG_Load("assets/coins/coin_05.png");     // Texture Surface
    SDL_Texture * coin5_tex = SDL_CreateTextureFromSurface(renderer, coin5); // Texture (specific representation of pixel data)
    SDL_Surface * coin6 = IMG_Load("assets/coins/coin_06.png");     // Texture Surface
    SDL_Texture * coin6_tex = SDL_CreateTextureFromSurface(renderer, coin6); // Texture (specific representation of pixel data)
    SDL_Surface * coin7 = IMG_Load("assets/coins/coin_07.png");     // Texture Surface
    SDL_Texture * coin7_tex = SDL_CreateTextureFromSurface(renderer, coin7); // Texture (specific representation of pixel data)
    SDL_Surface * coin8 = IMG_Load("assets/coins/coin_08.png");     // Texture Surface
    SDL_Texture * coin8_tex = SDL_CreateTextureFromSurface(renderer, coin8); // Texture (specific representation of pixel data)
    
    
    SDL_Surface * enemy1 = IMG_Load("sprite/enemy/idle/frame-1.png");     // Texture Surface
    SDL_Texture * enemy1_tex = SDL_CreateTextureFromSurface(renderer, enemy1); // Texture (specific representation of pixel data)
    SDL_Surface * enemy2 = IMG_Load("sprite/enemy/idle/frame-2.png");     // Texture Surface
    SDL_Texture * enemy2_tex = SDL_CreateTextureFromSurface(renderer, enemy2); // Texture (specific representation of pixel data)
    
    SDL_Surface * enemy3 = IMG_Load("sprite/enemy/idle/frame-3.png");     // Texture Surface
    SDL_Texture * enemy3_tex = SDL_CreateTextureFromSurface(renderer, enemy3); // Texture (specific representation of pixel data)
    SDL_Surface * enemy4 = IMG_Load("sprite/enemy/idle/frame-4.png");     // Texture Surface
    SDL_Texture * enemy4_tex = SDL_CreateTextureFromSurface(renderer, enemy4); // Texture (specific representation of pixel data)
    
    SDL_Surface * rock_mons = IMG_Load("sprite/enemy/idle/rock_monster.png");     // Texture Surface
    SDL_Texture * rock_mons_tex = SDL_CreateTextureFromSurface(renderer, rock_mons); // Texture (specific representation of pixel data)
    
    SDL_Surface * mana = IMG_Load("sprite/enemy/idle/mana_potion.png");     // Texture Surface
    SDL_Texture * mana_txt = SDL_CreateTextureFromSurface(renderer, mana); // Texture (specific representation of pixel data)
    
    SDL_Surface* super_saiyan = IMG_Load("sprite/idle/aura.png");
    SDL_Texture* ssj_txt = SDL_CreateTextureFromSurface(renderer, super_saiyan);
    
    
    
    
    
    
    
    SDL_Surface* mountainSurface = IMG_Load("assets/bg_2.png");
    SDL_Texture* mountains = SDL_CreateTextureFromSurface(renderer, mountainSurface);
    SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 0, 0, 0 ));
   
    SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255); // Renderer er Background e Color dei
    
    
    SDL_Rect set_image_at = {84,296, 64,128}; // Hero
    
    
    SDL_Rect super_saiyan_dest = {-10, 280, 142,144};
    
    SDL_Rect mountain1 = {0, 0 , 640, 480};
    SDL_Rect mountain2 = {640, 0 , 640, 480};
    
    SDL_Rect enemy_01 = {1280, 360 , 64, 64};
    SDL_Rect enemy_02 = {2560, 360 , 64, 64};
    SDL_Rect enemy_03 = {3840, 360 , 64, 64};
    SDL_Rect enemy_04 = {5120, 360 , 64, 64};
    
    
    SDL_Rect coin_01 ={ 1280, 392 , 32, 32};
    SDL_Rect coin_02 ={ 1240, 392 , 32, 32};
    SDL_Rect coin_03 ={ 1200, 392 , 32, 32};
    SDL_Rect coin_04 ={ 1160, 392 , 32, 32};
    SDL_Rect coin_05 ={ 1120, 392 , 32, 32};
    SDL_Rect coin_06 ={ 1080, 392 , 32, 32};
    
    SDL_Rect rock_monster_01 = {coin_06.x + random_of_hundred , 360, 64, 64};
    SDL_Rect mana_potion = {2600 , 360, 64, 64};
    


    int super_saiyan_has_started_from = 0;
    bool activate_ssj  = false;
    bool game_has_just_began = true;
    int mana_constant = 0;
    int jumpstate = 0; // 0 = walking , 1 = going up , 2 = going down;
    
    // srcrect => (to draw only a portion of the image)
    // destRect =>  (to draw the image only to a portion of the screen)
    
    // prothom image x =  0 * 130, y = 0; 2nd er ta x = 1 * 130, , y = 0 , 3rd er ta x = 2 * 130 , y = 0 eivabe agabe
    
    SDL_Rect dstrect = { 50, 300, 130, 140 }; // texture er moddhe destination hobe x axis e 50 ar y axis e 300 ar height width same
    SDL_Rect srcrect2 = { 0, 0, 130, 140 }; // imgaer er height 140 , width 130 , er prottekbar ami 0 , 1 , 2, 3, 4, tomo image nicci
    int new_frame_till_jump_complete;

    
      while (!quit)
      {
          SDL_Texture* running[6] = {texture1, texture2, texture3, texture4, texture5, texture6};
          SDL_Texture* jump_up[2] = {standing_tex, jump_up_txt};
          SDL_Texture* enemy[2] = {enemy1_tex, enemy2_tex};
          SDL_Texture* enemy2[2] = {enemy3_tex, enemy4_tex};
          
          SDL_Texture* coin[8] = {coin1_tex, coin2_tex, coin3_tex, coin4_tex, coin5_tex, coin6_tex, coin7_tex, coin8_tex};
          
          
          Framestart = SDL_GetTicks();
          cout << Framestart << endl;
          int sprite = (Framestart / 100) % 5; // protter point second e ekta kore frame nicchi ar oi moment e ekota kore sprite show kortechi
          int ssj_sprite = (Framestart/100) % 4;
          no_of_image = (Framestart / 100) % 6; // For our Hero
          int no_of_enemy = (Framestart/100) % 2; // For our Enemy
          int jump_up_animation_no = (Framestart/100) % 2;
          int no_of_coin = (Framestart / 100) % 8;
          int new_frame_till_jump_complete = (Framestart) + 2000;

          SDL_Rect srcrect = { sprite * 130, 0, 130, 140 }; // imgaer er height 140 , width 130 , er prottekbar ami 0 , 1 , 2, 3, 4, tomo image nicci
          
          
          SDL_Rect super_saiyan_aura_src = {ssj_sprite * 204, 0, 204,220};
          SDL_Rect super_saiyan_aura_dest = {set_image_at.x - 90, set_image_at.y-50, 210, 200};
   
          while (SDL_PollEvent(&event) != 0) // Poll for currently pending events.
          {
              switch (event.type)
              {
                  case SDL_QUIT:
                      quit = true;
                      break;
                  case SDL_KEYDOWN:
                          switch (event.key.keysym.sym)
                          {
                              case SDLK_LEFT :  set_image_at.x-= 10; break;
                              case SDLK_a :  set_image_at.x-= 10; break;

                              case SDLK_RIGHT: set_image_at.x+= 10; break;
                              case SDLK_d: set_image_at.x+= 10; break;

                              case SDLK_UP:
                                  {
                                      jumpstate = 1;
                                  }
                                   break;
                              case SDLK_SPACE:
                              {
                                  Mix_PlayChannel( -1, jumpSound, 0 );

//                                  JumpSound->SetupDevice();
//                                  JumpSound->PlaySound();
                                  jumpstate = 1;
                              }                                  break;
                              case SDLK_w:
                              {
                                  jumpstate = 1;
                              }                                  break;
//                              case SDLK_DOWN:  rect1.y++; break;
                          }
                          break;
              }
              
          }
          
//          SDL_bool collision = SDL_HasIntersection(&rect1, &rect2);


          SDL_RenderClear(renderer);// ager render clear na korle render copy kaj kore na
          
         
          mountain1.x --;
          mountain2.x --;
          
          enemy_01.x -= N1;
          enemy_02.x -=  N2;
          enemy_03.x -= N1;
          enemy_04.x -=  N2;
          
          
          coin_01.x --;
          coin_02.x --;
          coin_03.x --;
          coin_04.x --;
          coin_05.x --;
          coin_06.x --;
          
          rock_monster_01.x--;
          mana_potion.x--;
          
          if(mountain1.x < -639) mountain1.x = 640;
          if(mountain2.x < -639) mountain2.x = 640;
          
          if(enemy_01.x < -639) enemy_01.x = 5120;
          if(enemy_02.x < -639) enemy_02.x = 5120;
          if(enemy_03.x < -639) enemy_03.x = 5120;
          if(enemy_04.x < -639) enemy_04.x = 5120;
          
          if(rock_monster_01.x < -639) rock_monster_01.x = 900 + random_of_hundred;
          if(mana_potion.x < -10) {mana_potion.x += 3000; }
          
          if(coin_01.x < 0) coin_01.x = 640 + random_of_hundred;
          if(coin_01.y < 392) coin_01.y = 392;
          if(coin_02.x < 0) coin_02.x = 640 + random_of_hundred;
          if(coin_03.x < 0) coin_03.x = 640 + random_of_hundred;
          if(coin_04.x < 0) coin_04.x = 640 + random_of_hundred;
          if(coin_05.x < 0) coin_05.x = 640 + random_of_hundred;
          if(coin_06.x < 0) coin_06.x = 640 + random_of_hundred;

              
          
          
          SDL_RenderCopy(renderer, mountains, NULL, &mountain1);
          SDL_RenderCopy(renderer, mountains, NULL, &mountain2);
          
          
          
          

          
          
          if(activate_ssj)
 //          SDL_RenderCopy(renderer, ssj_txt, NULL, &super_saiyan_dest); // renderer e texture source point ar destination point e boshaitechi
                 {   SDL_RenderCopy(renderer, ssj_txt, &super_saiyan_aura_src, &super_saiyan_aura_dest);
                     
                     if(SDL_GetTicks() - super_saiyan_has_started_from > 7000){
                         activate_ssj = 0;
                         super_saiyan_has_started_from = 0;
                         mana_constant = 0;
                     }
                     
                 }// renderer e texture source point ar destination point e boshaitechi
          // texture e blue dress e character ache..
//          SDL_RenderCopy(renderer, texture, &srcrect, &dstrect); // renderer e texture source point ar destination point e boshaitechi
         if(jumpstate == 1)
         {
             SDL_RenderCopy(renderer, jump_up[1], NULL, &set_image_at);
             set_image_at.y -= 2;
             if(set_image_at.y < 170 - mana_constant)
             {
//                 set_image_at.y= 296;
                 jumpstate = 2;
                 
             }// renderer e texture source point ar destination point e boshaitechi
         }
          if(jumpstate == 2)
          {
              SDL_RenderCopy(renderer, jumo_fall_txt, NULL, &set_image_at);
              set_image_at.y += 2;
              if(set_image_at.y >= 296)
              {
                  set_image_at.y= 296;
                  jumpstate = 0;
                  
              }
          }
          
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

          
          
          if(collision_hero_enemy_01 or collision_hero_enemy_03 or collision_with_rock_monster){
//              GameOverSound->SetupDevice();
//              GameOverSound->PlaySound();
              Mix_PlayChannel( -1, endSound, 0 );
              d.present_window(text);
              quit = true;
}
    
          if(collision_with_coin_01) {
//              CoinSound -> SetupDevice();
//              CoinSound -> PlaySound();
              Mix_PlayChannel( -1, coinSound, 0 );

              coin_01.x = - 100;
              point_count++;}
          if(collision_with_coin_02){
//              CoinSound -> SetupDevice();
//              CoinSound -> PlaySound();
              Mix_PlayChannel( -1, coinSound, 0 );

              coin_02.x = -200;point_count++;}
          if(collision_with_coin_03) {
//              CoinSound -> SetupDevice();
//              CoinSound -> PlaySound();
              Mix_PlayChannel( -1, coinSound, 0 );

              coin_03.x = -100;point_count++;}
          if(collision_with_coin_04) {
//              CoinSound -> SetupDevice();
//              CoinSound -> PlaySound();
              Mix_PlayChannel( -1, coinSound, 0 );

              coin_04.x = - 100;point_count++;}
          if(collision_with_coin_05) {
//              CoinSound -> SetupDevice();
//              CoinSound -> PlaySound();
              Mix_PlayChannel( -1, coinSound, 0 );

              coin_05.x = -200; point_count++;}
          if(collision_with_coin_06) {
//              CoinSound -> SetupDevice();
//              CoinSound -> PlaySound();
              Mix_PlayChannel( -1, coinSound, 0 );

              coin_06.x = -100;point_count++;}
          
          if(collision_hero_mana_potion){
              Mix_PlayChannel( -1, manaPotionSound, 0 );
              mana_potion.x += 3200;
              super_saiyan_has_started_from = SDL_GetTicks();
              activate_ssj = true; mana_constant = 50;
              
          }
          
       
          int temp = point_count;
          int pos = 8;
          cout << "Point Count : " << point_count << endl;
          while(point_count>0)
          {
              int r = point_count % 10;
              cout << r << endl;
              point_count = point_count / 10;
              char ch = r + 48;
              text[pos] = ch;
              pos--;
          }
          point_count = temp;
          
          SDL_Surface * fontSurface = TTF_RenderText_Solid(font, text, color);
          SDL_Texture * fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);
         
          int texW = 0;
          int texH = 0;
          SDL_QueryTexture(fontTexture, NULL, NULL, &texW, &texH);
          SDL_Rect fontDstRect = { 630 - texW, 10, texW, texH };
          
          SDL_RenderCopy(renderer, fontTexture, NULL, &fontDstRect);
          if(game_has_just_began){
//              GameStartSound -> SetupDevice();
//              GameStartSound -> PlaySound();
              Mix_PlayChannel( -1, startSound, 0 );

              game_has_just_began = false;
          }
              


              
              
              SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_01);
              SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_02);
              SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_03);
              SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_04);
              SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_05);
              SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_06);
          
          if(jumpstate == 0)
          SDL_RenderCopy(renderer, running[no_of_image], NULL, &set_image_at); // renderer e texture source point ar destination point e boshaitechi
        
          
          SDL_RenderCopy(renderer, rock_mons_tex, NULL , &rock_monster_01);
          SDL_RenderCopy(renderer, mana_txt, NULL , &mana_potion);

        
          
//          SDL_RenderCopy(renderer, enemy[no_of_enemy], NULL, &enemy_02);
//          SDL_RenderCopy(renderer, enemy2[no_of_enemy], NULL, &enemy_04);
          SDL_RenderCopy(renderer, enemy[no_of_enemy], NULL, &enemy_01);
          SDL_RenderCopy(renderer, enemy2[no_of_enemy], NULL, &enemy_03);
          
          SDL_RenderCopy(renderer, fontTexture, NULL, &fontDstRect);

       
          
          




          
          
          
          SDL_RenderPresent(renderer); // Render present hobe
          

          FrameTime =SDL_GetTicks() - Framestart;
          if(frameDelay > FrameTime)
          {
              SDL_Delay(frameDelay - FrameTime);
          }
          
      }

        // Tarpore ja ja memory te declare korsi , oigula clear kre dtci
        TTF_Quit();
      SDL_DestroyTexture(texture);
      SDL_FreeSurface(image);
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      IMG_Quit();
      SDL_Quit();
  
}
