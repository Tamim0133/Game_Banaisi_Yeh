//
//  FrontPage.cpp
//  Game
//
//  Created by on 13/11/23.
//

#include "FrontPage.hpp"

FrontPage ::FrontPage()
{

    FrontPage_init();

    running = true;
    game_has_opened = 1;

    front_window = w.create_window("Front_Page", 640, 480);
    front_renderer = r.Create_Renderer(front_window);

    initiate_textures();

    SDL_ShowWindow(front_window);
    SDL_RaiseWindow(front_window);

    Mouse m(front_renderer);

    if (game_has_opened)
    {
        Mix_Music *music = Mix_LoadMUS("assets/sounds/alto.wav"); // Load Music
        Mix_PlayMusic(music, -1);                                 // -1 means Infinite porjonto cholbe
        game_has_opened = 0;                                      // Ensuring Only once this happens
    }

    while (running)
    {
        m.update(); // Mouse
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                running = false;
                SDL_DestroyRenderer(front_renderer);
                SDL_DestroyWindow(front_window);
            }
            switch (e.type)
            {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                {
                    running = false;
                }
                break; // Escape Button
                case SDLK_SPACE:
                {
                    running = false;
                }
                break; // Space Button
                default:
                    break;
                }

            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&mouse_posx, &mouse_posy);
                break;

            case SDL_MOUSEBUTTONDOWN: // Detecting Mouse Click in a Particular Region
                if ((mouse_posx >= 220 and mouse_posx <= 220 + 160) and (mouse_posy >= 265 and mouse_posy <= 260 + 200))
                {
                    if (SDL_BUTTON_LEFT == e.button.button)
                    {
                        Play_Music("assets/sounds/click.wav");
                        running = false;
                        break;
                    }
                }
            }
        }
        
        //  Check Intersection
        //-----------------------------------------------
        if (SDL_HasIntersection(&play_rect, &m.point))
        {
            play_rect = {235, 260, 170, 210};
        }
        else
        {
            play_rect = {240, 265, 160, 200};
        }
        
        //  Rendering
        //-----------------------------------------------
        
        SDL_RenderClear(front_renderer);

        SDL_RenderCopy(front_renderer, jungle_jump, NULL, &jungle_rect); // Bg
        SDL_RenderCopy(front_renderer, play, NULL, &play_rect);          // Play Btn

        int no_of_img2 = (SDL_GetTicks()/100) % 2;
        
        cout << SDL_GetTicks() << endl;
        
        SDL_RenderCopy(front_renderer, click_play[no_of_img2], NULL, &jungle_text_rect2); // Last er Text

        m.draw(front_renderer); // Mouse
        SDL_RenderPresent(front_renderer);
    }
    Menu n;
};


// Initialize
// ------------------------------------------------------------
void FrontPage::FrontPage_init()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Init(SDL_INIT_AUDIO);
}


// Texture
// ------------------------------------------------------------
void FrontPage::initiate_textures()
{

    jungle_jump = t.Create_tex("assets/Jungle-Jump.png", front_renderer); // Bg Chobi
    play = t.Create_tex("Resources/btn/play.png", front_renderer);        // play btn

    click_play[0] = t.Create_tex("assets/click_play_0.png", front_renderer); // Likha Sada CHOBI
    click_play[1] = t.Create_tex("assets/click_play_1.png", front_renderer); // Calo Chobi
}
