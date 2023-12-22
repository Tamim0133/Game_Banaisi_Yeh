//
//  Tutorial.hpp
//  Game
//
//  Created by Tamim Dewan on 22/12/23.
//

#ifndef Tutorial_hpp
#define Tutorial_hpp



#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <iostream>

#include "Window_Create.hpp"
#include "Renderer_Create.hpp"
#include "Texture_Create.hpp"
#include "Play_Music.hpp"
#include "mouse.hpp"


using namespace std;

struct Tutorial{
private:
    bool playing;
    Window_Create w;
    Renderer_Create r;
    Texture_Create t;
    
public:
    Tutorial();

};
#endif /* Tutorial_hpp */
