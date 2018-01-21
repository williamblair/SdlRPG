#include "Sprite.hpp"

// constructor/deconstructor
Sprite::Sprite()
{
    m_PosRect  = {0,0,0,0};
    m_ClipRect = {0,0,0,0};
}

Sprite::~Sprite()
{
    if(m_Surface) SDL_FreeSurface(m_Surface);
}

// load the given image as a SDL surface
bool Sprite::loadImage(const char *filename)
{
    bool status = true;
    m_Surface = IMG_Load(filename);
    if(!m_Surface){
        fprintf(stderr, "Sprite: failed to load: %s\n", filename);
        status = false;
    }
    else{
        m_PosRect.w = m_Surface->w;
        m_PosRect.h = m_Surface->h;
        m_ClipRect.w = m_Surface->w;
        m_ClipRect.h = m_Surface->h;
    }
    return status;
}

// getters
SDL_Surface *Sprite::getSurface(void)  {  return m_Surface;  }
SDL_Rect    *Sprite::getPosRect(void)  {  return &m_PosRect;  }
SDL_Rect    *Sprite::getClipRect(void) {  return &m_ClipRect; }