#pragma once
#include <fstream>
#include <iostream>

using namespace std;
//Difinicions amb la variable d'activació de la llibreria gràfica, __viz_graphics__
#include "Stack.h"
#include "Queue.h"
#include "maze.h"
#include "bot.h"
#include "box.h"
bool loadMaze(const char* txt, bot &bot, maze &maze);

void ReadMovements(Queue<int> &q, const char* txt);

void StackMovements(Stack<int> &s);

void SaveMovements(const char* txt,maze &m);