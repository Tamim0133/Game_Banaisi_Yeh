//
//  death.cpp
//  Game
//
//  Created by Tamim Dewan on 25/10/23.
//

#include "death.hpp"
#include "add_sound.hpp"

void Death:: present_window(char text[])
{
    AddSound a;
    a.ending_sound();
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    if(font == NULL){
        cout << "font ins NULL" << endl;
    }
    font = TTF_OpenFont("assets/fonts/terminal_font.ttf", 40);
    color  = { 0, 0, 0 };
    death_win = SDL_CreateWindow("Death", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 270, 360, 0);
    
    death_ren = SDL_CreateRenderer(death_win, -1, 0);
    
    death_surface = IMG_Load("Resources/you_win/header.png");
    death_surface_bg = IMG_Load("Resources/you_win/bg.png");
    fontSurface = TTF_RenderText_Solid(font,text, color);
    got_hit = IMG_Load("sprite/got hit/frame.png");
    
    death_txt = SDL_CreateTextureFromSurface(death_ren, death_surface);
    death_bg_txt = SDL_CreateTextureFromSurface(death_ren, death_surface_bg);
    got_hit_txt = SDL_CreateTextureFromSurface(death_ren, got_hit);
    fontTexture = SDL_CreateTextureFromSurface(death_ren, fontSurface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(fontTexture, NULL, NULL, &texW, &texH);
    cout << "texh : " << texH << texW << endl;
    SDL_Rect death_rect = {0,0,270, 110};
    SDL_Rect death_bg_rect = {0,0,270, 360};
    SDL_Rect got_hit_rect = {72,120,96,128};
    SDL_Rect fontDstRect = { 50,270, texW, texH };

    


    
  
    SDL_Event e;
    SDL_ShowWindow(death_win);
    SDL_RaiseWindow(death_win);
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
                case SDL_QUIT:
                    play = false;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        {
                            play = false;

                            SDL_DestroyRenderer(death_ren);
                            SDL_DestroyWindow(death_win);                        }

                            break;
                        case SDLK_SPACE:
                        {
                            play = false;

                            SDL_DestroyRenderer(death_ren);
                            SDL_DestroyWindow(death_win);                        }

                            break;
                            
                        default:
                            break;
                    }
            }
         }
    
        SDL_RenderClear(death_ren);// ager render clear na korle render copy kaj kore na
        SDL_RenderCopy(death_ren, death_bg_txt, NULL, &death_bg_rect);
        SDL_RenderCopy(death_ren, death_txt, NULL, &death_rect);
        SDL_RenderCopy(death_ren, got_hit_txt, NULL, &got_hit_rect);
        SDL_RenderCopy(death_ren, fontTexture, NULL, &fontDstRect);
            

        SDL_RenderPresent(death_ren); // Render present hobe
    }
    SDL_DestroyRenderer(death_ren);
    SDL_DestroyWindow(death_win);
//    SDL_Quit();
    
  

}
