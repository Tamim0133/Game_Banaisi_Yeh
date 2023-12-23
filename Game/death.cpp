//
//  death.cpp
//  Game
//
//  Created by  on 25/10/23.
//

#include "death.hpp"

void Death:: present_window(char text[])
{
    
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init(); // Font init
    
    play = true;
    
    font = TTF_OpenFont("assets/fonts/terminal_font.ttf", 40);
    color  = { 0, 0, 0 }; // black
    
    death_win = w.create_window("Death", 380, 360);
    death_ren = r.Create_Renderer(death_win);
    
    //  Textures
    // ----------------------
    death_txt = t.Create_tex("Resources/you_win/header.png", death_ren);
    death_bg_txt = t.Create_tex("Resources/you_win/bg.png", death_ren);
    background = t.Create_tex("Resources/you_win/table.png", death_ren);
    menu_back = t.Create_tex("Resources/btn/menu.png", death_ren);
    got_hit_txt = t.Create_tex("sprite/got hit/frame.png", death_ren);
    got_hit_txt = t.Create_tex("sprite/got hit/frame.png", death_ren);
    
    fontSurface = TTF_RenderText_Solid(font,text, color);
    fontTexture = SDL_CreateTextureFromSurface(death_ren, fontSurface);
    
    int texW = 0; int texH = 0;
    SDL_QueryTexture(fontTexture, NULL, NULL, &texW, &texH);
    
    //  Rectangles
    // -----------------------
    SDL_Rect death_rect = {50,30,270, 110};
    SDL_Rect death_bg_rect = {50,30,270, 300};
    SDL_Rect background_rect = {10, 5, 360, 350};
    SDL_Rect got_hit_rect = {122,100,96,128};
    SDL_Rect fontDstRect = {100,230, texW, texH};
    SDL_Rect back_to_menu_rect = {150, 260, 64, 64};
    
    SDL_Event e;
    
    SDL_ShowWindow(death_win);
    SDL_RaiseWindow(death_win);
    
    SDL_SetRenderDrawColor(death_ren, 255, 99, 71, 0.5);
    
    Mouse m(death_ren);
    
    
    
    while(play)
    {
        m.update();
        while (SDL_PollEvent(&e))
        {
            if(e.type == SDL_WINDOWEVENT
               && e.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                play = false;
                SDL_DestroyRenderer(death_ren);
                SDL_DestroyWindow(death_win);
            }
            switch (e.type)
            {
                case SDL_QUIT: play = false; break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE: {play = false;} break;
                        case SDLK_SPACE:  {play = false;} break;
                        default: break;
                    }
                case SDL_MOUSEBUTTONDOWN:
                    /*-------------------------------------------------
                                    Check Clicking
                    -------------------------------------------------*/
                    if(SDL_HasIntersection(&back_to_menu_rect, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            Play_Music("assets/sounds/click.wav");
                            //                            Menu m;
                            play = 0; break;
                            
                            
                        }
                    }
            }
        }
        /*-------------------------------------------------
                        Check Intersection
        -------------------------------------------------*/
        if(SDL_HasIntersection(&back_to_menu_rect, &m.point))
        {
            back_to_menu_rect = {148, 258, 66, 66};
        }
        else{
            back_to_menu_rect = {150, 260, 64, 64};
        }
        /*-------------------------------------------------
                        Render Start Clicking
        -------------------------------------------------*/
        SDL_RenderClear(death_ren);// ager render clear na korle render copy kaj kore na
        
        SDL_RenderCopy(death_ren, background, NULL, &background_rect);
        
        SDL_RenderCopy(death_ren, death_bg_txt, NULL, &death_bg_rect);
        
        SDL_RenderCopy(death_ren, death_txt, NULL, &death_rect);
        
        SDL_RenderCopy(death_ren, got_hit_txt, NULL, &got_hit_rect);
        
        SDL_RenderCopy(death_ren, fontTexture, NULL, &fontDstRect);
        
        SDL_RenderCopy(death_ren, menu_back, NULL, &back_to_menu_rect);
        
        m.draw(death_ren);
        
        SDL_RenderPresent(death_ren);
    }
    
    
    
    SDL_DestroyRenderer(death_ren);
    
    SDL_DestroyWindow(death_win);
    
    Mix_Music *music = Mix_LoadMUS("assets/sounds/alto.wav"); // Load Music
    Mix_PlayMusic(music, -1); // -1 means Infinite porjonto cholbe
    
    // Back to Menu Page
    // -------------------
    Menu q;
    
}
