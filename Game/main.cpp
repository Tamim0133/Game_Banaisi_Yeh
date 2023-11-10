#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <iostream>
#include "death.hpp"
#include "Sound.hpp"
#include "game.hpp"
using namespace std;

int main(int argc, char ** argv)
{
    Game g;
   
      return 0;
}


/*
 You could have a jumpState variable,
 so that 0 = on the ground,
 1 = moving up, and
 2 = moving down. Also,
 store the y coordinate for a base level, say baseY.

 You press the jump key, and you have a jumping speed that will move you up to the maximum height. Set jumpstate = 1. While jumpstate = 1, cycle through
 your animations based on what the ratio is of baseY to Y. Also, have a maxHeight, the maxHeight you want the player to be able to jump.

 So if you have 3 animations for the first part of the jump, you might do something like this
 if (jumpState == 1)
 if (y - baseY < (maxHeight / 3))
 setAnimation(1);
 else if (y - baseY < (2 * maxHeight / 3))
 setAnimation(2);
 else if (y - baseY < (maxHeight)
 setAnimation(3);

 */

