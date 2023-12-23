//
//  Loacation_choose.cpp
//  Game
//
//  Created by  on 23/12/23.
///Users/tamimdewan/Desktop/Game_2/Game/Loacation_choose.hpp

#include "Loacation_choose.hpp"



Location_choose :: Location_choose(){
    
    SDL_Init(SDL_INIT_VIDEO);
    playing = true;
    
    SDL_Window* win = w.create_window("Choose Location", 640, 480);
    SDL_Renderer* ren = r.Create_Renderer(win);
    
    Mouse m(ren);
    SDL_SetRenderDrawColor(ren, 245, 99, 51, 0.3);
    
    SDL_Event e;
    
    SDL_ShowWindow(win);
    SDL_RaiseWindow(win);
    
    SDL_Texture* bg = t.Create_tex("Resources/upgrade/table.png", ren);
    SDL_Texture* head = t.Create_tex("Resources/btn/choose_l.png", ren);
    SDL_Texture* pre = t.Create_tex("Resources/btn/prew.png", ren);
    SDL_Texture* nxt = t.Create_tex("Resources/btn/next.png", ren);
    SDL_Texture* ok = t.Create_tex("Resources/btn/ok.png", ren);
    
    SDL_Rect overlay = {0,0, 640, 480};
    SDL_Rect credits_edge_rect = {175, 183, 230, 60};
    
    SDL_Rect bg_rect = {60,10, 520, 440};
    SDL_Rect img_01 = {130,100, 350, 220};
    SDL_Rect head_rect = {150,30,300,100};
    
    SDL_Rect pre_rect = {150,320,64,64};
    SDL_Rect next_rect = {350,320,64,64};
    SDL_Rect ok_rect = {250,320,64,64};
    
    
    while(playing)
    {
        m.update();
        Framestart = SDL_GetTicks();// SDL initialize hoyar pore kotokkhon hoise
        
        while (SDL_PollEvent(&e))
        {
            if(e.type == SDL_WINDOWEVENT
               && e.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                playing = false;
                SDL_DestroyRenderer(ren);
                SDL_DestroyWindow(win);
            }
            switch (e.type)
            {
                case SDL_QUIT: playing = false; break;
                case SDL_MOUSEBUTTONDOWN:
                    
                    /*-------------------------------------------------
                                    Check Clicking
                     -------------------------------------------------*/
                    if(SDL_HasIntersection(&pre_rect, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            Play_Music("assets/sounds/click.wav");
                            location_no--;
                            if(location_no <= 0) location_no = 2;
                            
                        }
                    }
                    if(SDL_HasIntersection(&ok_rect, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            Play_Music("assets/sounds/click.wav");
                            
                            playing = false;
                        }
                    }
                    if(SDL_HasIntersection(&next_rect, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            Play_Music("assets/sounds/click.wav");
                            location_no++;
                            if(location_no >= 3) location_no = 1;
                        }
                    }
            }
        }
        
        //location 1
        //----------------------------------------
        if(location_no == 1){
            location_01 = t.Create_tex("assets/location/1.png", ren);
        }
        
        // location 2
        //-----------------------------------
        if(location_no == 2){
            location_02 = t.Create_tex("assets/location/2.png", ren);
        }
        
        
        /*-------------------------------------------------
         Check Intersection
         -------------------------------------------------*/
        
        if(SDL_HasIntersection(&ok_rect, &m.point))
        {
            ok_rect = {252, 322, 66, 66};
        }
        else{
            ok_rect = {250,320,64,64};
        }
        if(SDL_HasIntersection(&pre_rect, &m.point))
        {
            pre_rect = {152,322,66,66};
        }
        else{
            pre_rect = {150,320,64,64};
        }
        if(SDL_HasIntersection(&next_rect, &m.point))
        {
            next_rect = {352, 322, 66, 66};
        }
        else{
            next_rect = {350,320,64,64};
            
        }
        
        /*-------------------------------------------------
                        Render Start
         -------------------------------------------------*/
        SDL_RenderClear(ren);
        
        
        
        SDL_RenderCopy(ren, bg, NULL, &bg_rect);
        
        
        SDL_RenderCopy(ren, head, NULL, &head_rect);
        if(location_no == 1)
            SDL_RenderCopy(ren, location_01, NULL, &img_01);
        if(location_no == 2)
            SDL_RenderCopy(ren, location_02, NULL, &img_01);
        SDL_RenderCopy(ren, pre, NULL, &pre_rect);
        SDL_RenderCopy(ren, nxt, NULL, &next_rect);
        SDL_RenderCopy(ren, ok, NULL, &ok_rect);
        m.draw(ren);
        
        SDL_RenderPresent(ren);
        
        /*-------------------------------------------------
                    Cool FADE OUT EFFECT !
         -------------------------------------------------*/
        if(!playing)
        {
            Mix_HaltMusic();
            
            for (int alpha = 0; alpha <= 255; alpha+=10) {
                SDL_RenderClear(ren);
                SDL_RenderCopy(ren, bg, NULL, &bg_rect);
                
                
                SDL_RenderCopy(ren, head, NULL, &head_rect);
                if(location_no == 1)
                    SDL_RenderCopy(ren, location_01, NULL, &img_01);
                if(location_no == 2)
                    SDL_RenderCopy(ren, location_02, NULL, &img_01);
                SDL_RenderCopy(ren, pre, NULL, &pre_rect);
                SDL_RenderCopy(ren, nxt, NULL, &next_rect);
                SDL_RenderCopy(ren, ok, NULL, &ok_rect);
                
                SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
                
                SDL_SetRenderDrawColor(ren, 0, 0, 0, alpha);
                
                SDL_RenderFillRect(ren, &overlay);
                
                
                SDL_RenderPresent(ren);
                SDL_Delay(50);
            }
            // Loading Image
            // ------------------------
            for(int i = 0; i <= 300; i+=10)
            {
                SDL_RenderClear(ren);
                SDL_RenderCopy(ren,t.Create_tex("Resources/menu/loading.png", ren), NULL, &credits_edge_rect);
                SDL_Delay(75);
                SDL_RenderPresent(ren);
            }
            
        }
        
    }
    
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    if(location_no == 1)
        Game g;
    else
        Game2 g;
}
