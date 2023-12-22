//
//  Character_choose.cpp
//  Game
//
//  Created by Tamim Dewan on 23/12/23.
//

#include "Character_choose.hpp"

Character_choose :: Character_choose(){
    int FPS = 2;
    int frameDelay = (1000 / FPS);
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init(); // Font init

    playing = true;
    
    
    SDL_Window* win = SDL_CreateWindow("Transparent Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    
    SDL_GLContext
    gContext = SDL_GL_CreateContext(win);

    SDL_GL_SwapWindow(win);
    SDL_Renderer* ren = r.Create_Renderer(win);
    
    
    Mouse m(ren);
    SDL_SetRenderDrawColor(ren, 255, 99, 71, 0.5);
    
    SDL_Event e;

    SDL_ShowWindow(win);
    SDL_RaiseWindow(win);
    
    image[0] = t.Create_tex("sprite/standing/frame-1.png", ren);
    image[1] = t.Create_tex("sprite/standing/frame-2.png", ren);
    
    SDL_Rect img_01 = {100,100, 128, 180};
    SDL_Rect img_02 = {};
    
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
//                case SDL_MOUSEBUTTONDOWN:
                    
//                    if(SDL_HasIntersection(&close_btn, &m.point))
//                    {
//                        if(SDL_BUTTON_LEFT == e.button.button){
//                            Play_Music("assets/sounds/click.wav");
//
//                            playing = false; break;
//
//                        }
//                    }
                   
                    
                    
                
            }
         }
        
//        SDL_Rect face2 = {230, 155, 64, 64};
//        SDL_Rect textRect2 = {320, 175, texW, texH};
//        SDL_Rect btn2 = {360, 155, 96, 64};
//
//

                
      
//        if(SDL_HasIntersection(&close_btn, &m.point))
//        {
//            close_btn = {553, 13, 66, 66};
//        }
//        else{
//            close_btn = {550, 10, 64, 64};
//        }
       

        SDL_RenderClear(ren);

        
        int no_of_img = (Framestart/100) % 2;
        SDL_RenderCopy(ren, image[no_of_img], NULL, &img_01);
        SDL_RenderCopy(ren, image[no_of_img], NULL, &img_01);

        
        
       

        
        m.draw(ren);

        SDL_RenderPresent(ren);
        
        FrameTime = SDL_GetTicks() - Framestart;
        if(frameDelay > FrameTime)// frame delay = 1000/fps ; current frame time kom hole
        {
            SDL_Delay(frameDelay - FrameTime);
        }
    }



    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
}

    

