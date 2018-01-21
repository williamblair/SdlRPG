#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <cstdio>

#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

class Sprite
{
public:
    // constructor/deconstructor
    Sprite();
    ~Sprite();
    
    // load the given image as a SDL surface
    bool loadImage(const char *filename);
    
    // so the display can draw our sprite
    SDL_Surface *getSurface(void);
    SDL_Rect    *getPosRect(void);
    SDL_Rect    *getClipRect(void);
private:
    SDL_Surface *m_Surface = NULL;
    SDL_Rect     m_PosRect;
    SDL_Rect     m_ClipRect;

};

#endif // SPRITE_H_INCLUDED
