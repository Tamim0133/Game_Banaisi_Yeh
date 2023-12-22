//
//  High_scores.cpp
//  Game
//
//  Created by Tamim Dewan on 22/12/23.
//

#include "High_scores.hpp"


High_scores::High_scores(){
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init(); // Font init

    playing = true;
    
    
    SDL_Window* win = SDL_CreateWindow("Transparent Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    
    SDL_GLContext
    gContext = SDL_GL_CreateContext(win);



    SDL_GL_SwapWindow(win);
    SDL_Renderer* ren = r.Create_Renderer(win);
    
    SDL_Texture* close = t.Create_tex("Resources/settings/close_2.png", ren);
    SDL_Texture* table = t.Create_tex("Resources/rating/table.png", ren);
    SDL_Texture* bg = t.Create_tex("Resources/settings/bg.png", ren);
    SDL_Texture* head = t.Create_tex("Resources/rating/header.png", ren);
    SDL_Texture* face = t.Create_tex("Resources/rating/face.png", ren);
    SDL_Texture* btn = t.Create_tex("Resources/rating/btn.png", ren);


    
    
    SDL_Rect close_btn = {550, 10, 64, 64};
    SDL_Rect bg_rect = {150,20, 420, 440};
    SDL_Rect table_rect = {200,35,320, 400};
    SDL_Rect heading = {200, 10, 250, 100};
    SDL_Rect pic2 = {30, 80, 600, 450};
    
    TTF_Font* font = TTF_OpenFont("assets/fonts/terminal_font.ttf", 40);
    SDL_Color color  = { 0, 0, 0 };
    
    
    SDL_Event e;
    
    std::ifstream inputFile("Game/best_scores.txt");
    std::vector<int> v;

 
    int number;
    for (int i = 0; i < 5; ++i) {
        if (inputFile >> number) {
            v.push_back(number);
        }
    }
    
    inputFile.close();

    int texW = 200; int texH = 200;

    char temp[] = {'1','0','0'};
    std::string text1 = std::to_string(v[0]);
    std::string text2 = std::to_string(v[1]);
    std::string text3 = std::to_string(v[2]);
    std::string text4 = std::to_string(v[3]);
    std::string text5 = std::to_string(v[4]);

    SDL_Color textColor = {0, 0, 0};

    SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(ren, TTF_RenderText_Solid(font,text1.c_str(), color));
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(ren, TTF_RenderText_Solid(font,text2.c_str(), textColor));
    SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(ren, TTF_RenderText_Solid(font,text3.c_str(), textColor));
    SDL_Texture* textTexture4 = SDL_CreateTextureFromSurface(ren, TTF_RenderText_Solid(font,text4.c_str(), textColor));
    SDL_Texture* textTexture5 = SDL_CreateTextureFromSurface(ren, TTF_RenderText_Solid(font,text5.c_str(), textColor));


   
    SDL_QueryTexture(textTexture1, NULL, NULL, &texW, &texH);
    
    SDL_Rect face1 = {230, 90, 64, 64};
    SDL_Rect textRect1 = {320, 110, texW, texH};
    SDL_Rect btn1 = {360, 90, 96, 64};
    
    SDL_Rect face2 = {230, 155, 64, 64};
    SDL_Rect textRect2 = {320, 175, texW, texH};
    SDL_Rect btn2 = {360, 155, 96, 64};
    
    SDL_Rect face3 = {230, 220, 64, 64};
    SDL_Rect textRect3 = {320, 240, texW, texH};
    SDL_Rect btn3 = {360, 220, 96, 64};

    SDL_Rect face4 = {230, 285, 64, 64};
    SDL_Rect textRect4 = {320, 305, texW, texH};
    SDL_Rect btn4 = {360, 285, 96, 64};

    SDL_Rect face5 = {230, 350, 64, 64};
    SDL_Rect textRect5 = {320, 370, texW, texH};
    SDL_Rect btn5 = {360, 350, 96, 64};


            

    

    
    Mouse m(ren);
    SDL_SetRenderDrawColor(ren, 255, 99, 71, 0.5);
    

    SDL_ShowWindow(win);
    SDL_RaiseWindow(win);
    while(playing)
    {
        m.update();
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
                    
                    if(SDL_HasIntersection(&close_btn, &m.point))
                    {
                        if(SDL_BUTTON_LEFT == e.button.button){
                            Play_Music("assets/sounds/click.wav");
                            
                            playing = false; break;

                        }
                    }
                    
                    
                
            }
         }
        
      
        if(SDL_HasIntersection(&close_btn, &m.point))
        {
            close_btn = {553, 13, 66, 66};
        }
        else{
            close_btn = {550, 10, 64, 64};
            
        }
      

        SDL_RenderClear(ren);

    
        
        SDL_RenderCopy(ren, bg, NULL, &bg_rect);
        
        SDL_RenderCopy(ren, table, NULL, &table_rect);


        SDL_RenderCopy(ren, close, NULL, &close_btn);
        
        SDL_RenderCopy(ren, head, NULL, &heading);
        
        SDL_RenderCopy(ren, face, NULL, &face1);
        SDL_RenderCopy(ren, textTexture1, NULL, &textRect1);
        SDL_RenderCopy(ren, btn, NULL, &btn1);

        
        SDL_RenderCopy(ren, face, NULL, &face2);
        SDL_RenderCopy(ren, textTexture2, NULL, &textRect2);
        SDL_RenderCopy(ren, btn, NULL, &btn2);

        SDL_RenderCopy(ren, face, NULL, &face3);
        SDL_RenderCopy(ren, textTexture3, NULL, &textRect3);
        SDL_RenderCopy(ren, btn, NULL, &btn3);

        SDL_RenderCopy(ren, face, NULL, &face4);
        SDL_RenderCopy(ren, textTexture4, NULL, &textRect4);
        SDL_RenderCopy(ren, btn, NULL, &btn4);

        SDL_RenderCopy(ren, face, NULL, &face5);
        SDL_RenderCopy(ren, textTexture5, NULL, &textRect5);
        SDL_RenderCopy(ren, btn, NULL, &btn5);


        
        
       

        
        m.draw(ren);

        SDL_RenderPresent(ren);
    }



    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
}
