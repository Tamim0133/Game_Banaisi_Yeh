//
//  mouse.hpp
//  Game
//
//  Created by Tamim Dewan on 21/12/23.
//

#ifndef mouse_hpp
#define mouse_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Mouse{
public:
    SDL_Texture* tex;
    SDL_Rect rect;
    SDL_Rect point; // collision
    
    Mouse(SDL_Renderer* ren){
        tex = IMG_LoadTexture(ren, "Resources/mouse/mouse2.png");
        rect.w = 50;
        rect.h = 50;
        point.w = 1;
        point.h = 1;
        SDL_ShowCursor(false);// system mouse hide
    }
    
    void update(){
        SDL_GetMouseState(&rect.x, &rect.y);
        point.x = rect.x;
        point.y = rect.y;
        
    }
    
    void draw(SDL_Renderer* ren){
        SDL_RenderCopy(ren, tex, NULL, &rect);
    }
};
#endif /* mouse_hpp */
