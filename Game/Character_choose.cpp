//
//  Character_choose.cpp
//  Game
//
//  Created by  on 23/12/23.
//

#include "Character_choose.hpp"

Character_choose :: Character_choose(){
    int FPS = 30;
    int frameDelay = (1000 / FPS);
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init(); // Font init
    
    playing = true;
    
    SDL_Window* win = w.create_window("Choose Character", 640, 480);
    SDL_Renderer* ren = r.Create_Renderer(win);
    
    Mouse m(ren);
    SDL_SetRenderDrawColor(ren, 255, 99, 71, 0.5);
    
    SDL_Event e;
    
    SDL_ShowWindow(win);
    SDL_RaiseWindow(win);
    
    SDL_Texture* bg = t.Create_tex("Resources/upgrade/table.png", ren);
    SDL_Texture* head = t.Create_tex("Resources/btn/choose.png", ren);
    SDL_Texture* pre = t.Create_tex("Resources/btn/prew.png", ren);
    SDL_Texture* nxt = t.Create_tex("Resources/btn/next.png", ren);
    SDL_Texture* ok = t.Create_tex("Resources/btn/ok.png", ren);
    
    SDL_Rect bg_rect = {60,10, 520, 440};
    SDL_Rect img_01 = {210,120, 128, 180};
    SDL_Rect head_rect = {150,30,300,100};
    
    SDL_Rect pre_rect = {150,320,64,64};
    SDL_Rect next_rect = {350,320,64,64};
    SDL_Rect ok_rect = {250,320,64,64};
    
    
    while(playing)
    {
        m.update();
        Framestart = SDL_GetTicks();
        
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
                            char_no--;
                            if(char_no == 0) char_no = 4;
                            
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
                            char_no++;
                            if(char_no == 5) char_no = 1;
                        }
                    }
                    
                    
            }
        }
        
       
        // character 01
        //---------------------------------
        if(char_no == 1){
            image[0] = t.Create_tex("sprite/standing/frame-1.png", ren);
            image[1] = t.Create_tex("sprite/standing/frame-2.png", ren);}
        
        // character 2
        //---------------------------------
        if(char_no == 2){
            image[0] = t.Create_tex("sprite/Character2/Idle/frame-1.png", ren);
            image[1] = t.Create_tex("sprite/Character2/Idle/frame-2.png", ren);}
        
        // character 3
        //---------------------------------

        if(char_no == 3){
            image[0] = t.Create_tex("sprite/Character3/Idle/frame-1.png", ren);
            image[1] = t.Create_tex("sprite/Character3/Idle/frame-2.png", ren);}
        
        //character 4
        // ---------------------------------

        if(char_no == 4){
            image[0] = t.Create_tex("sprite/Character4/idle/frame-1.png", ren);
            image[1] = t.Create_tex("sprite/Character4/idle/frame-2.png", ren);}
        
        //  Button Intersection
        // ------------------------------------
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
        
        
        int no_of_img = (Framestart/100) % 2;
        
        SDL_RenderCopy(ren, bg, NULL, &bg_rect);
        
        SDL_RenderCopy(ren, image[no_of_img], NULL, &img_01);
        SDL_RenderCopy(ren, head, NULL, &head_rect);
        
        SDL_RenderCopy(ren, pre, NULL, &pre_rect);
        SDL_RenderCopy(ren, nxt, NULL, &next_rect);
        SDL_RenderCopy(ren, ok, NULL, &ok_rect);
        
        FrameTime = SDL_GetTicks() - Framestart;
        if(frameDelay > FrameTime)// frame delay = 1000/fps ; current frame time kom hole
        {
            SDL_Delay(frameDelay - FrameTime);
        }
        m.draw(ren);
        
        SDL_RenderPresent(ren);
        /*-------------------------------------------------
                        Render End
        -------------------------------------------------*/
    }
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    
    Location_choose l;
}



