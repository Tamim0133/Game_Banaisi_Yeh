//
//  Tutorial.cpp
//  Game
//
//  Created by on 22/12/23.
//

#include "Tutorial.hpp"

Tutorial::Tutorial()
{

    SDL_Init(SDL_INIT_VIDEO);
    playing = true;

    SDL_Window *win = w.create_window("Tutorial", 640, 480);
    SDL_Renderer *ren = r.Create_Renderer(win);

    SDL_Texture *close = t.Create_tex("Resources/settings/close_2.png", ren);
    SDL_Texture *bg = t.Create_tex("Resources/settings/bg.png", ren);
    SDL_Texture *how = t.Create_tex("Resources/settings/how_to_play1.png", ren);
    SDL_Texture *tutorial = t.Create_tex("Resources/settings/tutorial.png", ren);

    SDL_Rect close_btn = {550, 10, 64, 64};
    SDL_Rect bg_rect = {20, 20, 600, 440};
    SDL_Rect heading = {200, 10, 200, 80};
    SDL_Rect pic2 = {30, 80, 600, 450};

    SDL_Event e;

    Mouse m(ren);

    SDL_ShowWindow(win);
    SDL_RaiseWindow(win);

    while (playing)
    {
        m.update();
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                playing = false;
                SDL_DestroyRenderer(ren);
                SDL_DestroyWindow(win);
            }
            switch (e.type)
            {
            case SDL_QUIT:
                playing = false;
                break;
            case SDL_MOUSEBUTTONDOWN:

                if (SDL_HasIntersection(&close_btn, &m.point))
                {
                    if (SDL_BUTTON_LEFT == e.button.button)
                    {
                        Play_Music("assets/sounds/click.wav");

                        playing = false;
                        break;
                    }
                }
            }
        }
        
        //  Check Intersection
        //-----------------------------------------------
        if (SDL_HasIntersection(&close_btn, &m.point))
        {
            close_btn = {553, 13, 66, 66};
        }
        else
        {
            close_btn = {550, 10, 64, 64};
        }
        /*-------------------------------------------------
                        Render Start
        -------------------------------------------------*/
        SDL_RenderClear(ren);

        SDL_RenderCopy(ren, bg, NULL, &bg_rect);

        SDL_RenderCopy(ren, close, NULL, &close_btn);

        SDL_RenderCopy(ren, how, NULL, &heading);

        SDL_RenderCopy(ren, tutorial, NULL, &pic2);

        m.draw(ren);

        SDL_RenderPresent(ren);
        /*-------------------------------------------------
                        Render End
        -------------------------------------------------*/
    }

    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
}
