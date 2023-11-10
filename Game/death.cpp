//
//  death.cpp
//  Game
//
//  Created by Tamim Dewan on 25/10/23.
//

#include "death.hpp"

void Death:: present_window(char text[])
{

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    if(font == NULL){
        cout << "font ins NULL" << endl;
    }
    
    font = TTF_OpenFont("assets/fonts/terminal_font.ttf", 40);
    color  = { 0, 0, 0 };
    
    death_win = w.create_window("Death", 380, 360);
    death_ren = r.Create_Renderer(death_win);

    death_txt = t.Create_tex("Resources/you_win/header.png", death_ren);
    death_bg_txt = t.Create_tex("Resources/you_win/bg.png", death_ren);
    background = t.Create_tex("Resources/you_win/table.png", death_ren);
    got_hit_txt = t.Create_tex("sprite/got hit/frame.png", death_ren);
    
    fontSurface = TTF_RenderText_Solid(font,text, color);
    fontTexture = SDL_CreateTextureFromSurface(death_ren, fontSurface);
    
    int texW = 0; int texH = 0;
    SDL_QueryTexture(fontTexture, NULL, NULL, &texW, &texH);
    
    SDL_Rect death_rect = {50,30,270, 110};
    SDL_Rect death_bg_rect = {50,30,270, 300};
    SDL_Rect background_rect = {10, 5, 360, 350};
    SDL_Rect got_hit_rect = {122,150,96,128};
    SDL_Rect fontDstRect = { 100,280, texW, texH };
  
    SDL_Event e;
    SDL_ShowWindow(death_win);
    SDL_RaiseWindow(death_win);
    SDL_SetRenderDrawColor(death_ren, 255, 99, 71, 0.5);
    
    
    while( play)
    {
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
            }
         }
    
        SDL_RenderClear(death_ren);// ager render clear na korle render copy kaj kore na
        SDL_RenderCopy(death_ren, background, NULL, &background_rect);
        SDL_RenderCopy(death_ren, death_bg_txt, NULL, &death_bg_rect);
        SDL_RenderCopy(death_ren, death_txt, NULL, &death_rect);
        SDL_RenderCopy(death_ren, got_hit_txt, NULL, &got_hit_rect);
        SDL_RenderCopy(death_ren, fontTexture, NULL, &fontDstRect);
            

        SDL_RenderPresent(death_ren);
    }
    
    
    
    SDL_DestroyRenderer(death_ren);
    SDL_DestroyWindow(death_win);
}
