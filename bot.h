#pragma once

#include <iostream>
#define RIGHT 2
#define LEFT -2
#define DOWN -1
#define UP 1
using namespace std;


class bot
{
public:
	bot();
	void setInitialPos(int x, int y);
	int getPosX();
	int getPosY();
	int getMoved();
	int getBeers();
	
	void setPosX(int x);
	void setPosY(int y);
	void setMoved(int n);
	void IncBeer();// increase number of beers
	//Travel around the maze, thinking the movements
	//void walkThink(int& x,int& y);
	void move(int x,int y);
	void move(int direction);
private:
	int m_x;
	int m_y;
	//Number of beers taked
	int m_nBeer;
	int m_moved;
};