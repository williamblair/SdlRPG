// followalong of Code Rag SDL2 rpg tutorials:
// https://www.youtube.com/watch?v=b1BLuYorzX0&list=PLHM_A02NtaaVey-4Ezh7p6bbOsv-DKA-0

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <cstdio>

// dumb windows...
#ifdef __WIN32
#undef main
#endif

#include "Display.hpp"

Display display;
Sprite testSprite;

int main(int argc, char *argv[])
{
    display.init(640, 480, "Hello SDL!");
    testSprite.loadImage("businessman.png");
    
    // TODO - decide where to put poll events, etc...
    // probably a Game class
    SDL_Event event;
    bool quit = false;
    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) quit = true;
        }
        
        display.clear();
        
        display.drawSprite(testSprite);
        
        display.update();
    }
    
    return 0;
}