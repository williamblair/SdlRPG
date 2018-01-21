#include "Display.hpp"

// constructor
Display::Display()
{
    // init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Failed to init SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    // init IMG
    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == -1)
    {
        fprintf(stderr, "Failed to init IMG: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }
    else{
        m_imageWasInit = true;
    }
    
    // init TTF
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Failed to init TTF: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
}

// deconstructor
Display::~Display()
{
    // free memory
    if(m_WinSurface) SDL_FreeSurface(m_WinSurface);
    if(m_Window)     SDL_DestroyWindow(m_Window);
    
    // quit SDL
    if(m_imageWasInit)              IMG_Quit();
    if(TTF_WasInit())               TTF_Quit();
    if(SDL_WasInit(SDL_INIT_VIDEO)) SDL_Quit();
}

// create the game window
bool Display::init(const int w, const int h, const std::string &title)
{
    // store stuff
    m_ScreenWidth  = w;
    m_ScreenHeight = h;
    
    // create window
    m_Window = SDL_CreateWindow(
        title.c_str(), 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        w, h,
        SDL_WINDOW_SHOWN
    );
    if(!m_Window)
    {
        fprintf(stderr, "Failed to create SDL Window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // get game surface
    m_WinSurface = SDL_GetWindowSurface(m_Window);
    if(!m_WinSurface) 
    {
        fprintf(stderr, "Failed to get window surface: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return true;
}

// clear the window surface
void Display::clear(void)
{
    SDL_FillRect(m_WinSurface, NULL, SDL_MapRGB(m_WinSurface->format, 0,0,0));
}

// update the screen and delay
bool Display::update(void)
{
    
    SDL_UpdateWindowSurface(m_Window);
    
    // TODO - accurate FPS control
    SDL_Delay(1000.0f / 60.0f);
    
    return true;
}

// blit the given sprite to our surface
bool Display::drawSprite(Sprite &s)
{
    bool status = true;
    if(SDL_BlitSurface(s.getSurface(), s.getClipRect(), m_WinSurface, s.getPosRect()) != 0) {
        fprintf(stderr, "Failed to blit surface: %s\n", SDL_GetError());
        status = false;
    }
    return status;
}