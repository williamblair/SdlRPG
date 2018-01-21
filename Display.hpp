#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <string>
#include <cstdio>
#include <cstdlib>

#include "Sprite.hpp"

#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

class Display
{
public:
    // constructor/deconstructor
    Display();
    ~Display();
    
    // create the game window
    bool init(const int w, const int h, const std::string &title);
    
    // update the screen and delay
    bool update(void);
    
    // blit the given sprite to our surface
    bool drawSprite(Sprite &s);
    
    // clear the window surface
    void clear(void);
    
private:
    SDL_Window  *m_Window       = NULL;
    SDL_Surface *m_WinSurface   = NULL;
    bool         m_imageWasInit = false;
    int          m_ScreenWidth  = 0;
    int          m_ScreenHeight = 0;
    
};

#endif // DISPLAY_H_INCLUDED
