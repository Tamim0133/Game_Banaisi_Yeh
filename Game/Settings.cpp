//
//  Settings.cpp
//  Game
//
//  Created by  on 22/12/23.
//

#include "Settings.hpp"




void Settings_tab::play_settings(){
    SDL_Init(SDL_INIT_VIDEO);
    playing = true;

    SDL_Window* settings_win = w.create_window("Settings", 640, 480);
    SDL_Renderer* settings_ren = r.Create_Renderer(settings_win);


    SDL_Texture* bg = t.Create_tex("Resources/settings/bg.png", settings_ren);
    SDL_Texture* headline = t.Create_tex("Resources/settings/92.png", settings_ren);
    SDL_Texture* table = t.Create_tex("Resources/settings/table.png", settings_ren);

    SDL_Texture* on = t.Create_tex("Resources/settings/96.png", settings_ren);
    SDL_Texture* off = t.Create_tex("Resources/settings/95.png", settings_ren);
    SDL_Texture* on_bar = t.Create_tex("Resources/settings/94.png", settings_ren);
    SDL_Texture* off_bar = t.Create_tex("Resources/settings/93.png", settings_ren);
    SDL_Texture* up = t.Create_tex("Resources/settings/97.png", settings_ren);
    SDL_Texture* down = t.Create_tex("Resources/settings/98.png", settings_ren);
    SDL_Texture* sound = t.Create_tex("Resources/settings/sound.png", settings_ren);
    SDL_Texture* close = t.Create_tex("Resources/settings/close_2.png", settings_ren);
    


    SDL_Rect bg_rect = {112,52,380,360};
    SDL_Rect headline_rect = {210, 100, 180,80};
    SDL_Rect table_rect = {125,70, 350,300};
    SDL_Rect sound_rect = {130, 180, 150, 100};
    SDL_Rect sound_btn = {290, 200, 94, 64};
    SDL_Rect close_btn = {410, 5, 64, 64};
    
    SDL_Rect Volume_bar = {190, 300, 180,30};
    SDL_Rect Volume_up = {380, 300, 32,32};
    SDL_Rect Volume_down = {150, 300, 32,32};

    

    SDL_Event e;

    Mouse m(settings_ren);

    SDL_ShowWindow(settings_win);
    SDL_RaiseWindow(settings_win);
    SDL_SetRenderDrawColor(settings_ren, 255, 99, 71, 0.5);
    

    while(playing)
    {
        m.update();
        while (SDL_PollEvent(&e))
        {
            if(e.type == SDL_WINDOWEVENT
               && e.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                playing = false;
                SDL_DestroyRenderer(settings_ren);
                SDL_DestroyWindow(settings_win);
            }
            switch (e.type)
            {
                case SDL_QUIT: playing = false; break;
                case SDL_MOUSEBUTTONDOWN:
                    
                    //  Sound Btn Clicking
                    // -----------------------------------------------
                    
                    if(SDL_HasIntersection(&sound_btn, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            if(music_on)
                            Play_Music("assets/sounds/click.wav");
                            if(music_on){
                                music_on = false;
                                Mix_HaltMusic();
                                on = t.Create_tex("Resources/settings/95.png", settings_ren);
                            }
                            else{
                                music_on = true;
                                Mix_Music *music = Mix_LoadMUS("assets/sounds/alto.wav"); // Load Music
                                Mix_PlayMusic(music, -1);//
                                on = t.Create_tex("Resources/settings/96.png", settings_ren);
                            }

                        }
                    }
                    
                    //  Close Btn Clicking
                    // -----------------------------------------------
                    
                    if(SDL_HasIntersection(&close_btn, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            if(music_on)
                            Play_Music("assets/sounds/click.wav");
                            
                            playing = false; break;

                        }
                    }
                    
                    
                    //  Vol Up Btn Clicking
                    // -----------------------------------------------
                    if(SDL_HasIntersection(&Volume_up, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            if(music_on)
                            Play_Music("assets/sounds/click.wav");
                            if(Volume_bar.w < 180){
                                Volume_bar.w += 10;
                            }

                        }
                    }
                    
                    //  Vol Down Btn Clicking
                    // -----------------------------------------------
                    if(SDL_HasIntersection(&Volume_down, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            if(music_on)
                            Play_Music("assets/sounds/click.wav");
                            if(Volume_bar.w > 20){
                                Volume_bar.w -= 10;
                            }

                        }
                    }
                    
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE: {playing = false;} break;
                        case SDLK_SPACE:  {playing = false;} break;
                        default: break;
                    }
            }
         }
        
        /*--------------------------------------------------------
                        Checking Interaction
         --------------------------------------------------------*/
        
        if(SDL_HasIntersection(&sound_btn, &m.point))
        {
            sound_btn = {292, 202, 96, 66};
        }
        else{
            sound_btn = {290, 200, 94, 64};
        }
        if(SDL_HasIntersection(&close_btn, &m.point))
        {
            close_btn = {432, 52, 66, 66};
        }
        else{
            close_btn = {430, 50, 64, 64};
            
        }
        if(SDL_HasIntersection(&Volume_up, &m.point))
        {
            Volume_up = {382, 302, 34,34};
        }
        else{
            Volume_up = {380, 300, 32,32};
        }
        if(SDL_HasIntersection(&Volume_down, &m.point))
        {
            Volume_down = {152, 302, 34,34};
        }
        else{
            Volume_down = {150, 300, 32,32};
        }
        
        
        /*-------------------------------------------------
                        Render Start
        -------------------------------------------------*/
        
        SDL_RenderClear(settings_ren);

        SDL_RenderCopy(settings_ren, bg, NULL, &bg_rect);
        SDL_RenderCopy(settings_ren, table, NULL, &table_rect);
        SDL_RenderCopy(settings_ren, headline, NULL, &headline_rect);
        SDL_RenderCopy(settings_ren, sound, NULL, &sound_rect);
        if(music_on)
        {
            SDL_RenderCopy(settings_ren, on, NULL, &sound_btn);
            SDL_RenderCopy(settings_ren, on_bar, NULL, &Volume_bar);
        }
        else
            {
                SDL_RenderCopy(settings_ren, off, NULL, &sound_btn);
                SDL_RenderCopy(settings_ren, off_bar, NULL, &Volume_bar);
            }
        SDL_RenderCopy(settings_ren, up, NULL, &Volume_up);
        SDL_RenderCopy(settings_ren, down, NULL, &Volume_down);

        SDL_RenderCopy(settings_ren, close, NULL, &close_btn);

        
        m.draw(settings_ren);

        SDL_RenderPresent(settings_ren);
        
        /*-------------------------------------------------
                        Render Ends
        -------------------------------------------------*/
    }



    SDL_DestroyWindow(settings_win);
    SDL_DestroyRenderer(settings_ren);
}
