//
//  menu.cpp
//  Game
//
//  Created by Tamim Dewan on 22/12/23.
//

#include "menu.hpp"
#include "game.hpp"


Menu :: Menu(){
    
    MenuPage_init();
    
    running = true;
    game_has_opened = 1;
    
    menu_window = w.create_window("Menu_Page", 640, 480);
    menu_renderer = r.Create_Renderer(menu_window);
    
    initiate_textures();
    
    SDL_ShowWindow(menu_window);
    SDL_RaiseWindow(menu_window);
    
    Mouse m(menu_renderer);
    SDL_Texture* yourTexture = t.Create_tex("Resources/menu/fade_out.png", menu_renderer);
    

    
    jump_up_txt = t.Create_tex("sprite/jump/jump_up.png", menu_renderer);

    jump_fall_txt = t.Create_tex("sprite/jump/jump_fall.png", menu_renderer);
    
    if(game_has_opened) {
        game_has_opened = 0; // Ensuring Only once this happens
    }
    int FPS = 90;
    int frameDelay = (1000 / FPS); // Time per frame
    while(running)
    {
        m.update();
        while (SDL_PollEvent(&e))
        {
            if(e.type == SDL_WINDOWEVENT
               && e.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                running = false;
                SDL_DestroyRenderer(menu_renderer);
                SDL_DestroyWindow(menu_window);
            }
            switch (e.type)
            {
                case SDL_QUIT: running = false; break;
                 
                case SDL_MOUSEBUTTONDOWN:
                    if(SDL_HasIntersection(&play_edge_rect, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            if(music_on)
                            Play_Music("assets/sounds/click.wav");

                            running = false; break;}
                    }
                    if(SDL_HasIntersection(&settings_edge_rect, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            if(music_on)
                            Play_Music("assets/sounds/click.wav");
//                            bool ok = music_on;
                            s.play_settings();
                           
                        }
                    }
                    if(SDL_HasIntersection(&credits_edge_rect, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            if(music_on)
                            Play_Music("assets/sounds/click.wav");
                            Credits c;
                            //                            bool ok = music_on;
                        }
                    }
                    if(SDL_HasIntersection(&scores_edge_rect, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            if(music_on)
                            Play_Music("assets/sounds/click.wav");
                            High_scores h;
                        }
                    }
                    if(SDL_HasIntersection(&how_play_edge_rect, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            if(music_on)
                            Play_Music("assets/sounds/click.wav");
                            Tutorial t;
                           
                        }
                    }
//
            }
            
         }
    
        if(SDL_HasIntersection(&play_edge_rect, &m.point))
        {
            play_edge_rect = {174, 89, 234, 64};
            play_now_rect = {179, 108, 206, 22};
            SDL_PollEvent(&e);
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                running = false; break;
            }

        }
        else{
            play_edge_rect = {175, 87, 230, 60};
            play_now_rect = {185, 107, 200, 18};
        }
        
        
        if(SDL_HasIntersection(&settings_edge_rect, &m.point))
        {
           
            settings_edge_rect = {174, 137, 234, 64};
            settings_rect = {179, 151, 172, 22};

        }
        else{
            settings_edge_rect = {175, 135, 230, 60};
            settings_rect = {185, 150, 170, 20};
        }
        
        
        if(SDL_HasIntersection(&credits_edge_rect, &m.point))
        {
            credits_edge_rect = {174, 187, 234, 64};
            credits_rect = {179, 203, 156, 22};

        }
        else{
            credits_edge_rect = {175, 185, 230, 60};
            credits_rect = {185, 202, 150, 18};
        }
        
        
        if(SDL_HasIntersection(&scores_edge_rect, &m.point))
        {
            scores_edge_rect = {174, 238, 234, 64};
            scores_rect = {179, 257, 156, 22};

        }
        else{
            scores_edge_rect = {178, 236, 230, 60};
            scores_rect = {185, 256, 150, 18};
        }
        
        
        if(SDL_HasIntersection(&how_play_edge_rect, &m.point))
        {
            how_play_edge_rect = {174, 292, 234, 64};
            how_to_play_rect = {179, 308, 231, 22};

        }
        else{
            how_play_edge_rect = {175, 290, 230, 60};
            how_to_play_rect = {185, 307, 225, 18};
        }
        
        
        SDL_RenderClear(menu_renderer);
        
        SDL_RenderCopy(menu_renderer, jungle_jump, NULL, &jungle_rect);  
        SDL_RenderCopy(menu_renderer, table, NULL, &table_rect);  // Bg
        SDL_RenderCopy(menu_renderer, right_edge, NULL, &play_edge_rect);  // Bg
        SDL_RenderCopy(menu_renderer, play_now, NULL, &play_now_rect);  // Bg
        
        SDL_RenderCopy(menu_renderer, right_edge, NULL, &settings_edge_rect);  // Bgr
        SDL_RenderCopy(menu_renderer, settings, NULL, &settings_rect);  // Bg

        SDL_RenderCopy(menu_renderer, right_edge, NULL, &credits_edge_rect);  // Bgr
        SDL_RenderCopy(menu_renderer, credits, NULL, &credits_rect);  // Bg

        SDL_RenderCopy(menu_renderer, right_edge, NULL, &scores_edge_rect);  // Bgr
        SDL_RenderCopy(menu_renderer, scores, NULL, &scores_rect);  // Bg

        SDL_RenderCopy(menu_renderer, right_edge, NULL, &how_play_edge_rect);  // Bgr
        SDL_RenderCopy(menu_renderer, how_to_play, NULL, &how_to_play_rect);  // Bg
        
        SDL_RenderCopy(menu_renderer, jump_up_txt, NULL, &set_image_at_1);  // Bg
        SDL_RenderCopy(menu_renderer, jump_fall_txt, NULL, &set_image_at_2);  // Bg

        m.draw(menu_renderer);
        if(!running)
        {
            for (int alpha = 0; alpha <= 255; alpha+=10) {
                SDL_RenderPresent(menu_renderer);
                SDL_RenderCopy(menu_renderer, jungle_jump, NULL, &jungle_rect);  // Bg
                SDL_RenderCopy(menu_renderer, table, NULL, &table_rect);  // Bg
                SDL_RenderCopy(menu_renderer, right_edge, NULL, &play_edge_rect);  // Bg
                SDL_RenderCopy(menu_renderer, play_now, NULL, &play_now_rect);  // Bg
                
                SDL_RenderCopy(menu_renderer, right_edge, NULL, &settings_edge_rect);  // Bgr
                SDL_RenderCopy(menu_renderer, settings, NULL, &settings_rect);  // Bg

                SDL_RenderCopy(menu_renderer, right_edge, NULL, &credits_edge_rect);  // Bgr
                SDL_RenderCopy(menu_renderer, credits, NULL, &credits_rect);  // Bg

                SDL_RenderCopy(menu_renderer, right_edge, NULL, &scores_edge_rect);  // Bgr
                SDL_RenderCopy(menu_renderer, scores, NULL, &scores_rect);  // Bg

                SDL_RenderCopy(menu_renderer, right_edge, NULL, &how_play_edge_rect);  // Bgr
                SDL_RenderCopy(menu_renderer, how_to_play, NULL, &how_to_play_rect);  // Bg
                
                SDL_RenderCopy(menu_renderer, jump_up_txt, NULL, &set_image_at_1);  // Bg
                SDL_RenderCopy(menu_renderer, jump_fall_txt, NULL, &set_image_at_2);
                SDL_SetRenderDrawBlendMode(menu_renderer, SDL_BLENDMODE_BLEND);
                
                SDL_SetRenderDrawColor(menu_renderer, 0, 0, 0, alpha);
                
                SDL_RenderFillRect(menu_renderer, &overlay);
                
           
           
                   SDL_Delay(40);
               }
            
            for(int i = 0; i <= 300; i+=10)
            {
                SDL_RenderClear(menu_renderer);
                SDL_RenderCopy(menu_renderer,t.Create_tex("Resources/menu/loading.png", menu_renderer), NULL, &credits_edge_rect);
                SDL_Delay(25);
                SDL_RenderPresent(menu_renderer);
            }
            


           

            

        }
        SDL_RenderPresent(menu_renderer);
    }
    SDL_DestroyWindow(menu_window);
    SDL_DestroyRenderer(menu_renderer);
    Game g;
    
    Mix_HaltMusic();  // Stops Playing Music
    
};


void Menu:: MenuPage_init(){
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Init(SDL_INIT_AUDIO);
}

void Menu :: initiate_textures(){
    
    jungle_jump = t.Create_tex("Resources/menu/bg1.png", menu_renderer); // Bg Chobi
    table = t.Create_tex("Resources/menu/table.png", menu_renderer); // Bg Chobi
    right_edge = t.Create_tex("Resources/menu/edge.png", menu_renderer); // Bg Chobi
    play_now = t.Create_tex("Resources/menu/play_now.png", menu_renderer); // Bg Chobi
    settings = t.Create_tex("Resources/menu/settings.png", menu_renderer); // Bg Chobi
    credits = t.Create_tex("Resources/menu/credits.png", menu_renderer); // Bg Chobi
    scores = t.Create_tex("Resources/menu/scores.png", menu_renderer); // Bg Chobi
    how_to_play = t.Create_tex("Resources/menu/how_to_play.png", menu_renderer); // Bg Chobi
    
   
}
#define FADE_SPEED 0.07f;
Uint8 alpha;
float alphaCalc;


