#include "bot.h"

bot::bot()
{
	m_x = 0;
	m_y = 0;
	m_nBeer = 0;
	m_moved = 0;
}

void bot::setInitialPos(int x, int y)
{
	m_x = x;
	m_y = y;
}

int bot::getPosX()
{
	return m_x;
}

int bot::getPosY()
{
	return m_y;
}

int bot::getMoved() {
	return m_moved;
}

int bot::getBeers() {
	return m_nBeer;
}
void bot::IncBeer() {
	m_nBeer+=1;
}

void bot::setPosX(int x) {
	m_x = x;
}

void bot::setPosY(int y) {
	m_y = y;
}

void bot::setMoved(int n) {
	m_moved = n;
}

//set the new PosX and PosY of bot
void bot::move(int x,int y) {
	m_x = x;
	m_y = y;
}

void bot::move(int direction) {
	switch (direction) {
	case UP:
		m_y -= 1;
		m_moved = UP;
		break;
	case DOWN:
		m_y += 1;
		m_moved = DOWN;
		break;
	case LEFT:
		m_x -= 1;
		m_moved = LEFT;
		break;
	case RIGHT:
		m_x += 1;
		m_moved = RIGHT;
		break;
	}
}