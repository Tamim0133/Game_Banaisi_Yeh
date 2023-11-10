//
//  Play_Music.cpp
//  Game
//
//  Created by Tamim Dewan on 10/11/23.
//

#include "Play_Music.hpp"


Play_Music::Play_Music(string location){
    Mix_Chunk * sound = Mix_LoadWAV(location.c_str());
    Mix_PlayChannel( -1, sound, 0 );
    
}
