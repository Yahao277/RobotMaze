#pragma once

#include <SDL.h>
#include "keyboard_sdl.h"

struct T_KEYBOARD
{
  int cnt[NUM_KEYBOARD_KEY_CODES] ;              // Indica si la tecla est?f?icamente pulsada
  int trg[NUM_KEYBOARD_KEY_CODES] ;              // Indica si la tecla ha sido pulsada este frame
};

void Keyboard_ProcessKeyDown(int tecla) ;
void Keyboard_ProcessKeyUp(int tecla) ;
void Keyboard_Init() ;
void Keyboard_Tick() ;

int Keyboard_GetKeyCnt(int cual) ;
int Keyboard_GetKeyTrg(int cual) ;
