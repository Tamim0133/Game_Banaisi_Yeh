//
//  add_sound.hpp
//  Game
//
//  Created by Tamim Dewan on 27/10/23.
//

#ifndef add_sound_hpp
#define add_sound_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>
#endif /* add_sound_hpp */

struct AddSound{
public:
    void add_sound();
    void play_sound();
    void jump_sound();
    void ending_sound();
    void mana_potion_sound();
private:
    SDL_AudioSpec wavSpec1, wavSpec2 , wavSpec3;
    Uint32 wavLength1,wavLength2,wavLength3;
    Uint8 *wavBuffer1, *wavBuffer2,*wavBuffer3 ;
     
};
