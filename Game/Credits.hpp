//
//  Credits.hpp
//  Game
//
//  Created by on 22/12/23.
//

#ifndef Credits_hpp
#define Credits_hpp



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
#include "variables.hpp"
//#include "global.h"
using namespace std;

struct Credits{
private:
    bool playing;
    Window_Create w;
    Renderer_Create r;
    Texture_Create t;
    
public:
    Credits();

};
#endif /* Credits_hpp */
