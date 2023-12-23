//
//  game_2.cpp
//  Game
//
//  Created by  on 23/12/23.
//

#include "game_2.hpp"

Game2:: Game2(){
    
    Init();
    
    FPS = 30;
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
                            
                        case SDLK_UP: {
                            Play_Music("assets/sounds/smb_kick.wav");
                            jumpstate = 1;} break;
                        case SDLK_SPACE:{
                            Play_Music("assets/sounds/smb_kick.wav"); jumpstate = 1; } break;
                        case SDLK_w: {
                            Play_Music("assets/sounds/smb_kick.wav"); jumpstate = 1; } break;
                            
                    } break;
            }
            
        }
        
        SDL_RenderClear(renderer);//Clear the current rendering
        Move_everything();
        
        
        /*-------------------------------------------------
                       Cool Fade In Effect
        -------------------------------------------------*/
        
        if(game_has_just_began){
            for (int alpha = 255; alpha >= 0; alpha-=10) {
                SDL_RenderCopy(renderer, bg, NULL, &mountain1);
                
                
                
                
                SDL_RenderCopy(renderer, cloud, NULL, &cloud_rect);
                SDL_RenderCopy(renderer, cloud, NULL, &cloud_rect_opo);
                
                SDL_RenderCopy(renderer, hill2, NULL, &hill21);
                SDL_RenderCopy(renderer, hill2, NULL, &hill22);
                
                SDL_RenderCopy(renderer, hill1, NULL, &hill11);
                SDL_RenderCopy(renderer, hill1, NULL, &hill12);
                
                //
                SDL_RenderCopy(renderer, distant_tree, NULL, &distant_tree1);
                SDL_RenderCopy(renderer, distant_tree, NULL, &distant_tree2);
                //
                SDL_RenderCopy(renderer, bushes, NULL, &bushes1);
                SDL_RenderCopy(renderer, bushes, NULL, &bushes2);
                
                SDL_RenderCopy(renderer, tree, NULL, &tree1);
                SDL_RenderCopy(renderer, tree, NULL, &tree2);
                
                SDL_RenderCopy(renderer, cloud_1, NULL, &cloud_rect_11);
                SDL_RenderCopy(renderer, cloud_1, NULL, &cloud_rect_12);
                
                SDL_RenderCopy(renderer, cloud_2, NULL, &cloud_rect_21);
                SDL_RenderCopy(renderer, cloud_2, NULL, &cloud_rect_22);
                
                SDL_RenderCopy(renderer, cloud_3, NULL, &cloud_rect_31);
                SDL_RenderCopy(renderer, cloud_3, NULL, &cloud_rect_32);
                
                
                SDL_RenderCopy(renderer, ground, NULL, &ground1);
                SDL_RenderCopy(renderer, ground, NULL, &ground2);
                SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, alpha);
                
                SDL_RenderFillRect(renderer, &mountain1);
                SDL_RenderPresent(renderer);
                
                
                SDL_Delay(70);
            }
        }
        /*-------------------------------------------------
                        Render Start
        -------------------------------------------------*/
        SDL_RenderCopy(renderer, bg, NULL, &mountain1);
        
        SDL_RenderCopy(renderer, cloud, NULL, &cloud_rect);
        SDL_RenderCopy(renderer, cloud, NULL, &cloud_rect_opo);
        
        SDL_RenderCopy(renderer, hill2, NULL, &hill21);
        SDL_RenderCopy(renderer, hill2, NULL, &hill22);
        
        SDL_RenderCopy(renderer, hill1, NULL, &hill11);
        SDL_RenderCopy(renderer, hill1, NULL, &hill12);
        
        
        SDL_RenderCopy(renderer, distant_tree, NULL, &distant_tree1);
        SDL_RenderCopy(renderer, distant_tree, NULL, &distant_tree2);
        
        SDL_RenderCopy(renderer, bushes, NULL, &bushes1);
        SDL_RenderCopy(renderer, bushes, NULL, &bushes2);
        
        SDL_RenderCopy(renderer, tree, NULL, &tree1);
        SDL_RenderCopy(renderer, tree, NULL, &tree2);
        
        SDL_RenderCopy(renderer, cloud_1, NULL, &cloud_rect_11);
        SDL_RenderCopy(renderer, cloud_1, NULL, &cloud_rect_12);
        
        SDL_RenderCopy(renderer, cloud_2, NULL, &cloud_rect_21);
        SDL_RenderCopy(renderer, cloud_2, NULL, &cloud_rect_22);
        
        SDL_RenderCopy(renderer, cloud_3, NULL, &cloud_rect_31);
        SDL_RenderCopy(renderer, cloud_3, NULL, &cloud_rect_32);
        
        
        SDL_RenderCopy(renderer, ground, NULL, &ground1);
        SDL_RenderCopy(renderer, ground, NULL, &ground2);
        
        
        
        
        if(activate_ssj)  {Activate_ability();}
        
        if(jumpstate == 1)  {Show_jump();}
        
        if(jumpstate == 2) {Show_fall();}
        
        Detect_collision();
        
        
        
        if(game_has_just_began){
            Play_Music("assets/sounds/game_start.wav");game_has_just_began = false;}
        
        Render_Coins();
        
        no_of_image = (Framestart / 100) % 6;
        
        if(jumpstate == 0)SDL_RenderCopy(renderer, running[no_of_image], NULL, &set_image_at);
        
        SDL_RenderCopy(renderer, rock_mons_tex, NULL , &rock_monster_01);
        SDL_RenderCopy(renderer, mana_txt, NULL , &mana_potion);
        
        int no_of_enemy = (Framestart/100) % 2;
        int enemy_type_two_no = (Framestart/100) % 8;
        SDL_RenderCopy(renderer, enemy[no_of_enemy], NULL, &enemy_01);
        SDL_RenderCopy(renderer, enemy2[no_of_enemy], NULL, &enemy_03);
        SDL_RenderCopy(renderer, enemy3[enemy_type_two_no], NULL, &enemy_04);
        
        Show_point();
        
        SDL_RenderPresent(renderer);//Update the screen with any rendering
        /*-------------------------------------------------
                       Render End
        -------------------------------------------------*/
        
        // FPS
        // ----------------------------
        
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
    
    FrontPage f;
    
}


void Game2:: Init(){
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Init(SDL_INIT_AUDIO);
    
    
}

void Game2:: Create_game_textures(){
    
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
    
    mana_txt = t.Create_tex("sprite/enemy/idle/mana_potion2.png", renderer);
    
    ssj_txt = t.Create_tex("sprite/idle/aura.png", renderer);
    
    
    
    
    bg = t.Create_tex("assets/bg/11_background.png", renderer);
    ground = t.Create_tex("assets/bg/01_ground.png", renderer);
    tree = t.Create_tex("assets/bg/02_trees and bushes.png", renderer);
    bushes = t.Create_tex("assets/bg/04_bushes.png", renderer);
    distant_tree = t.Create_tex("assets/bg/03_distant_trees.png", renderer);
    hill1 = t.Create_tex("assets/bg/05_hill1.png", renderer);
    hill2 = t.Create_tex("assets/bg/06_hill2.png", renderer);
    cloud = t.Create_tex("assets/bg/07_huge_clouds.png", renderer);
    cloud_1 = t.Create_tex("assets/bg/08_clouds.png", renderer);
    cloud_2 = t.Create_tex("assets/bg/09_distant_clouds1.png", renderer);
    cloud_3 = t.Create_tex("assets/bg/10_distant_clouds.png", renderer);
    
    
    // character 0ne
    //----------------------------------------------------------------
    
    if(char_no == 1){
        running[0] = t.Create_tex("sprite/running/frame-1.png", renderer);
        running[1] = t.Create_tex("sprite/running/frame-2.png", renderer);
        running[2] = t.Create_tex("sprite/running/frame-3.png", renderer);
        running[3] = t.Create_tex("sprite/running/frame-4.png", renderer);
        running[4] = t.Create_tex("sprite/running/frame-5.png", renderer);
        running[5] = t.Create_tex("sprite/running/frame-6.png", renderer);
        
        jump_up[0] = t.Create_tex("sprite/standing/frame-1.png", renderer);
        jump_up[1] = t.Create_tex("sprite/jump/jump_up.png", renderer);
        
        jumo_fall_txt = t.Create_tex("sprite/jump/jump_fall.png", renderer);
    }
    
    //----------------------------------------------------------------
    
    
    
    // character two
    //----------------------------------------------------------------
    
    if(char_no == 2){
        running[0] = t.Create_tex("sprite/Character2/running/frame-1.png", renderer);
        running[1] = t.Create_tex("sprite/Character2/running/frame-2.png", renderer);
        running[2] = t.Create_tex("sprite/Character2/running/frame-3.png", renderer);
        running[3] = t.Create_tex("sprite/Character2/running/frame-4.png", renderer);
        running[4] = t.Create_tex("sprite/Character2/running/frame5.png", renderer);
        running[5] = t.Create_tex("sprite/Character2/running/frame-6.png", renderer);
        
        jump_up[0] = t.Create_tex("sprite/Character2/Idle/frame-1.png", renderer);
        jump_up[1] = t.Create_tex("sprite/Character2/Jump/Jump-up.png", renderer);
        jumo_fall_txt = t.Create_tex("sprite/Character2/Jump/Jump-fall.png", renderer);
    }
    
    //----------------------------------------------------------------
    
    
    // character three
    //----------------------------------------------------------------
    
    if(char_no == 3){
        running[0] = t.Create_tex("sprite/Character3/running/frame-1.png", renderer);
        running[1] = t.Create_tex("sprite/Character3/running/frame-2.png", renderer);
        running[2] = t.Create_tex("sprite/Character3/running/frame-3.png", renderer);
        running[3] = t.Create_tex("sprite/Character3/running/frame-4.png", renderer);
        running[4] = t.Create_tex("sprite/Character3/running/frame-5.png", renderer);
        running[5] = t.Create_tex("sprite/Character3/running/frame-1.png", renderer);
        
        jump_up[0] = t.Create_tex("sprite/Character3/Idle/frame-1.png", renderer);
        jump_up[1] = t.Create_tex("sprite/Character3/Jump/jump-up.png", renderer);
        jumo_fall_txt = t.Create_tex("sprite/Character3/Jump/jump-fall.png", renderer);
    }
    
    //----------------------------------------------------------------
    
    // character four
    //----------------------------------------------------------------
    
    if(char_no == 4){
        running[0] = t.Create_tex("sprite/Character4/idle/frame-1.png", renderer);
        running[1] = t.Create_tex("sprite/Character4/running/frame-1.png", renderer);
        running[2] = t.Create_tex("sprite/Character4/running/frame-2.png", renderer);
        running[3] = t.Create_tex("sprite/Character4/running/frame-3.png", renderer);
        running[4] = t.Create_tex("sprite/Character4/running/frame-4.png", renderer);
        running[5] = t.Create_tex("sprite/Character4/sliding/frame.png", renderer);
        
        jump_up[0] = t.Create_tex("sprite/Character4/idle/frame-2.png", renderer);
        jump_up[1] = t.Create_tex("sprite/Character4/jump_up/frame.png", renderer);
        jumo_fall_txt = t.Create_tex("sprite/Character4/jump_fall/frame.png", renderer);
    }
    
    //----------------------------------------------------------------
    
    
    enemy[0] = t.Create_tex("sprite/enemy/got_hit/frame-3.png", renderer);
    enemy[1] = t.Create_tex("sprite/enemy/got_hit/frame-4.png", renderer);
    
    enemy2[0] = t.Create_tex("sprite/enemy/idle/frame-3.png", renderer);
    enemy2[1] = t.Create_tex("sprite/enemy/idle/frame-4.png", renderer);
    
    enemy3[0] = t.Create_tex("sprite/Monster/frame-1.png", renderer);
    enemy3[1] = t.Create_tex("sprite/Monster/frame-2.png", renderer);
    enemy3[2] = t.Create_tex("sprite/Monster/frame-3.png", renderer);
    enemy3[3] = t.Create_tex("sprite/Monster/frame-4.png", renderer);
    enemy3[4] = t.Create_tex("sprite/Monster/frame-5.png", renderer);
    enemy3[5] = t.Create_tex("sprite/Monster/frame-6.png", renderer);
    enemy3[6] = t.Create_tex("sprite/Monster/frame-7.png", renderer);
    enemy3[7] = t.Create_tex("sprite/Monster/frame-8.png", renderer);
    
    super_jump = t.Create_tex("sprite/super_jump.png", renderer);
    
}


/*-------------------------------------------------
               Moving Everything
-------------------------------------------------*/
void Game2 :: Move_everything(){

    ground1.x -= 6;
    ground2.x -= 6;
    if(ground1.x < -639) ground1.x = 0;
    if(ground2.x < 0) ground2.x = 640;
    
    tree1.x -= 5;
    tree2.x -= 5;
    if(tree1.x < -639) tree1.x = 0;
    if(tree2.x < 1) tree2.x = 640;
    
    distant_tree1.x -= 4;
    distant_tree2.x -= 4;
    if(distant_tree1.x <= -639) distant_tree1.x = 0;
    if(distant_tree2.x <= 1) distant_tree2.x = 640;
    
    bushes1.x -=5;
    bushes2.x -=5;
    if(bushes1.x < -639) bushes1.x = 0;
    if(bushes2.x < 1) bushes2.x = 640;
    //
    //
    hill11.x -=3;
    hill12.x -=3;
    if(hill11.x < -639) hill11.x = 0;
    if(hill12.x < 0) hill12.x = 640;
    //
    //
    hill21.x -=2;
    hill22.x -=2;
    if(hill21.x < -639) hill21.x = 0;
    if(hill22.x <= 0) hill22.x = 640;
    
    cloud_rect.x-=1;
    cloud_rect_opo.x -= 1;
    if(cloud_rect.x < -639) cloud_rect.x = 0;
    if(cloud_rect_opo.x <= 0) cloud_rect_opo.x = 640;
    
    cloud_rect_11.x-=1;
    cloud_rect_12.x -= 1;
    if(cloud_rect_11.x < -639) cloud_rect_11.x = 0;
    if(cloud_rect_12.x <= 0) cloud_rect_12.x = 640;
    
    cloud_rect_21.x-=2;
    cloud_rect_22.x -= 2;
    if(cloud_rect_21.x < -639) cloud_rect_21.x = 0;
    if(cloud_rect_22.x <= 0) cloud_rect_22.x = 640;
    
    cloud_rect_31.x-=2;
    cloud_rect_32.x -= 2;
    if(cloud_rect_31.x < -639) cloud_rect_31.x = 0;
    if(cloud_rect_32.x <= 0) cloud_rect_32.x = 640;
    
    
    enemy_01.x -= (rand() % 2) + 2 + 5;
    enemy_02.x -=  (rand() % 2) + 2 + 5;
    enemy_03.x -= (rand() % 3) + 2 + 5;
    enemy_04.x -=    5;
    
    if(enemy_01.x < -639) enemy_01.x = 1120 + (rand() % 2000);
    if(enemy_02.x < -639) enemy_02.x = 5120;
    if(enemy_03.x < -639) enemy_03.x = 1120 + (rand() % 3000);
    if(enemy_04.x < -639) enemy_04.x = 3120 ;
    
    
    coin_01.x -= 5;
    coin_02.x -= 5;
    coin_03.x -= 5;
    coin_04.x -= 5;
    coin_05.x -= 5;
    coin_06.x -= 5;
    
    if(coin_01.x < 0) coin_01.x = 640 + random_of_hundred;
    if(coin_02.x < 0) coin_02.x = 640 + random_of_hundred;
    if(coin_03.x < 0) coin_03.x = 640 + random_of_hundred;
    if(coin_04.x < 0) coin_04.x = 640 + random_of_hundred;
    if(coin_05.x < 0) coin_05.x = 640 + random_of_hundred;
    if(coin_06.x < 0) coin_06.x = 640 + random_of_hundred;
    
    rock_monster_01.x-= 5;
    if(rock_monster_01.x < -639) rock_monster_01.x = 900 + (rand() % 300);
    
    mana_potion.x-= 5;
    if(mana_potion.x < -10) {mana_potion.x += 3000; }
    
}

void Game2 :: Render_Coins(){
    int no_of_coin = (SDL_GetTicks() / 100) % 8;
    
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_01);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_02);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_03);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_04);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_05);
    SDL_RenderCopy(renderer, coin[no_of_coin], NULL, &coin_06);
}


/*-------------------------------------------------
                Detect Collision
-------------------------------------------------*/


void Game2 :: Detect_collision(){
    
    SDL_Rect hero_rect = {set_image_at.x , set_image_at.y + set_image_at.h/2, set_image_at.w/2, set_image_at.h/2};
    SDL_Rect enemy_01_rect = {enemy_01.x , enemy_01.y + enemy_01.h/2 , enemy_01.w/2, enemy_01.h/2};
    SDL_Rect enemy_03_rect = {enemy_03.x , enemy_03.y + enemy_03.h/2, enemy_03.w/2, enemy_03.h/2};
    SDL_Rect mana_potion_rect = {mana_potion.x , mana_potion.y + mana_potion.h/2 , mana_potion.w/2 , mana_potion.h/2};
    SDL_Rect rock_monster_rect = {rock_monster_01.x , rock_monster_01.y + rock_monster_01.h/2 , rock_monster_01.w/2 ,rock_monster_01.h/3};
    SDL_Rect enemy_04_rect = {enemy_04.x , enemy_04.y + enemy_04.h/2 , enemy_04.w/2 , enemy_04.h/2};
    
    
    SDL_bool collision_hero_enemy_01 = SDL_HasIntersection(&hero_rect, &enemy_01_rect);
    SDL_bool collision_hero_enemy_03 = SDL_HasIntersection(&hero_rect, &enemy_03_rect);
    SDL_bool collision_hero_enemy_04 = SDL_HasIntersection(&hero_rect, &enemy_04_rect);
    SDL_bool collision_hero_mana_potion = SDL_HasIntersection(&hero_rect, &mana_potion_rect);
    SDL_bool collision_with_rock_monster = SDL_HasIntersection(&hero_rect, &rock_monster_rect);
    SDL_bool collision_with_coin_01 = SDL_HasIntersection(&set_image_at, &coin_01);
    SDL_bool collision_with_coin_02 = SDL_HasIntersection(&set_image_at, &coin_02);
    SDL_bool collision_with_coin_03 = SDL_HasIntersection(&set_image_at, &coin_03);
    SDL_bool collision_with_coin_04 = SDL_HasIntersection(&set_image_at, &coin_04);
    SDL_bool collision_with_coin_05 = SDL_HasIntersection(&set_image_at, &coin_05);
    SDL_bool collision_with_coin_06 = SDL_HasIntersection(&set_image_at, &coin_06);
    
    
    
    if(collision_hero_enemy_01 or collision_hero_enemy_03 or collision_hero_enemy_04 or collision_with_rock_monster)
        
    {
        Save_score(point_count);
        Play_Music("assets/sounds/smb_gameover.wav");
        Death d;
        d.present_window(text);quit = true;
        
        
    }
    
    if(collision_with_coin_01) {
        Play_Music("assets/sounds/smb_coin.wav"); coin_01.x = - 100; point_count++; }
    if(collision_with_coin_02) {
        Play_Music("assets/sounds/smb_coin.wav"); coin_02.x = -200; point_count++; }
    if(collision_with_coin_03) {
        Play_Music("assets/sounds/smb_coin.wav"); coin_03.x = -100; point_count++;}
    if(collision_with_coin_04) {
        Play_Music("assets/sounds/smb_coin.wav"); coin_04.x = - 100; point_count++;}
    if(collision_with_coin_05) {
        Play_Music("assets/sounds/smb_coin.wav"); coin_05.x = -200; point_count++;}
    if(collision_with_coin_06) {
        Play_Music("assets/sounds/smb_coin.wav"); coin_06.x = -100; point_count++;}
    
    if(collision_hero_mana_potion){
        Play_Music("assets/sounds/smb_powerup.wav");
        mana_potion.x += 3200;
        super_saiyan_has_started_from = SDL_GetTicks();
        activate_ssj = true; mana_constant = 50;
    }
    
}
/*-------------------------------------------------
                Activate ability
-------------------------------------------------*/
void Game2 :: Activate_ability(){
    
    int ssj_sprite = (SDL_GetTicks()/100) % 4;
    
    SDL_Rect super_saiyan_aura_src = {ssj_sprite * 204, 0, 204,220};
    SDL_Rect super_saiyan_aura_dest = {set_image_at.x - 90, set_image_at.y-50, 210, 200};
    
    SDL_RenderCopy(renderer, ssj_txt, &super_saiyan_aura_src, &super_saiyan_aura_dest);
    SDL_RenderCopy(renderer, super_jump, NULL, &super_jump_rect);
    
    
    if(SDL_GetTicks() - super_saiyan_has_started_from > 7000)
    { activate_ssj = 0; super_saiyan_has_started_from = 0; mana_constant = 0;}
    
}
/*-------------------------------------------------
                Show Point
-------------------------------------------------*/
void Game2 :: Show_point(){
    
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

void Game2 :: Show_jump(){
    SDL_RenderCopy(renderer, jump_up[1], NULL, &set_image_at);
    set_image_at.y -= 6;
    if(set_image_at.y < 170 - mana_constant) jumpstate = 2;
}

void Game2 :: Show_fall(){
    SDL_RenderCopy(renderer, jumo_fall_txt, NULL, &set_image_at);
    set_image_at.y += 6;
    
    if(set_image_at.y >= 296)
    { set_image_at.y= 296;jumpstate = 0;}
}

/*-------------------------------------------------
                Save Score
-------------------------------------------------*/
void Game2 :: Save_score(int n)
{
    cout << "Points : " << n << endl << endl;
    std::ifstream inputFile("Game/best_scores.txt");
    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file\n";

    }

    std::vector<int> v;
    
    int number;
    for (int i = 0; i < 5; ++i) {
        if (inputFile >> number) {
            v.push_back(number);
        } else {
            std::cerr << "Error reading integer from file\n";
            inputFile.close();

        }
    }
    
    inputFile.close();
    
    
    std::cout << "Integers read from file and stored in vector:\n";
    for (const auto& value : v) {
        std::cout << value << "\n";
    }
    
    v[5] = n;
    int temp = 5;
    for(int i = 0; i < 5; i++){
        if(v[i] < n){
            temp = i;
            break;
        }
    }
    
    for(int i = 5; i >temp; i--)
    {
        v[i] = v[i-1];
    }
    
    v[temp] = n;
    ofstream outputFile("Game/best_scores.txt");
    
    for (const auto& value : v) {
        outputFile << value << " ";
    }

    outputFile.close();

    
}

