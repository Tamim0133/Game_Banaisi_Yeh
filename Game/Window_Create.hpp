//
//  Window_Create.hpp
//  Game_Final
//
//  Created by Tamim Dewan on 10/11/23.
//

#ifndef Window_Create_hpp
#define Window_Create_hpp

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <SDL2/SDL.h>

using namespace std;

struct Window_Create{
public:
    SDL_Window * create_window(string heading, int width , int height);
    
//    ~Window_Create();
private:
   
};
#endif /* Window_Create_hpp */
