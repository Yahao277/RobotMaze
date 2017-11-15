#pragma once

#include <SDL.h>

#define ACTIVAR_CONSOLA_DE_DEBUG

static const bool RUN_IN_WINDOW_MODE     = 0;
static const bool RUN_IN_FULLSCREEN_MODE = 1;

static const int MAX_FPS     =  60;

class Game {
public:
  //"a" = resolucioX , "b" = resolucioY
  Game(unsigned int a, unsigned int b);
  //Default: resolucioX = 600, resolucioY = 550
  Game();
  ~Game();

  void Video_ShowWindow();
  void ProcessEvents();
  void VideoUpdate();
  void Init();
  bool isExit() const;

private:
  void InitializeHardware(int new_resolution_x, int new_resolution_y, int fps_maximos, bool FullScreen);
  void Video_Init(int new_resx, int new_resy, bool FullScreen);
  void Video_ClearBackBuffer(int, int, int);
  void ProcessEventSystem();
  void Video_Flip();

  const unsigned int resolucioX;
  const unsigned int resolucioY;
  
  struct GameStatus
  {
    bool Exit ;
    bool Minimized ;
    int CurrentFrameNumber;
  } GameStatus;

};



//! En esta estructura se guarda el status del control de v?eo
struct DatosVideo
{
  int resx ;
  int resy ;

  SDL_Window *window ;
  SDL_Renderer *renderer ;
} ;

// Extern para acceder a la variable de status de v?eo
extern struct DatosVideo g_Video ;
