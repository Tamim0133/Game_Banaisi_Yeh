//
//  Play_Music.cpp
//  Game
//
//  Created  on 10/11/23.
//

#include "Play_Music.hpp"
#include "variables.hpp"

Play_Music::Play_Music(string location){
    if(music_on)
    {
    
        Mix_Chunk * sound = Mix_LoadWAV(location.c_str());
        Mix_PlayChannel( -1, sound, 0 );
    }
    
}
