//
//  add_sound.cpp
//  Game
//
//  Created by Tamim Dewan on 27/10/23.
//

#include "add_sound.hpp"

void AddSound :: play_sound(){
    SDL_LoadWAV("assets/sounds/coin.wav", &wavSpec1, &wavBuffer1, &wavLength1);
    SDL_AudioDeviceID deviceId1 = SDL_OpenAudioDevice(NULL, 0, &wavSpec1, NULL, 0);
    int success = SDL_QueueAudio(deviceId1, wavBuffer1, wavLength1);
    SDL_PauseAudioDevice(deviceId1, 0);
//    SDL_Delay(1000);
}

void AddSound:: jump_sound(){
    
}

void AddSound:: ending_sound(){
    {
        SDL_LoadWAV("assets/sounds/end.wav", &wavSpec2, &wavBuffer2, &wavLength2);
        SDL_AudioDeviceID deviceId3 = SDL_OpenAudioDevice(NULL, 0, &wavSpec2, NULL, 0);
        int success = SDL_QueueAudio(deviceId3, wavBuffer2, wavLength2);
        SDL_PauseAudioDevice(deviceId3, 0);
    //    SDL_Delay(1000);
    }
}

void AddSound::mana_potion_sound(){
    {
        SDL_LoadWAV("assets/sounds/mana_potion.wav", &wavSpec3, &wavBuffer3, &wavLength3);
        SDL_AudioDeviceID deviceId4 = SDL_OpenAudioDevice(NULL, 0, &wavSpec3, NULL, 0);
        int success = SDL_QueueAudio(deviceId4, wavBuffer3, wavLength3);
        SDL_PauseAudioDevice(deviceId4, 0);
    //    SDL_Delay(1000);
    }
}

