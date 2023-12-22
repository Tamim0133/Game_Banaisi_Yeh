//
//  Character_choose.hpp
//  Game
//
//  Created by Tamim Dewan on 23/12/23.
//

#ifndef Character_choose_hpp
#define Character_choose_hpp


#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "Window_Create.hpp"
#include "Renderer_Create.hpp"
#include "Texture_Create.hpp"
#include "Play_Music.hpp"
#include "mouse.hpp"


using namespace std;

struct Character_choose{
private:
    bool playing;
    Window_Create w;
    Renderer_Create r;
    Texture_Create t;
    
    SDL_Texture* image[2];
    
    Uint32 Framestart;
    int FrameTime;
    int FPS;
    int frameDelay;

    
public:
    Character_choose();

};
#endif /* Character_choose_hpp */
