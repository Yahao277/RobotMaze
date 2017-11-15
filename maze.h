#pragma once

#include <vector>



#include "box.h"
#include "bot.h"
#include "Queue.h"
#include "Stack.h"

#define RIGHT 2
#define LEFT -2
#define DOWN -1
#define UP 1

using namespace std;

class maze
{
public:
	maze();
	~maze();
	void importMaze(const vector<vector<box>>& matrix,int sizeX,int sizeY);
	int lenghtX();
	int lenghtY();

	vector<vector<box>> getMatrix();
	void setMatrix(vector<vector<box>> matrix);
	bot& getBot();
	void incbeers();
	void incbotbeers();
	void update(int x,int y);
	bool move2(Queue<int> &q,Stack<int> &s);
	bool move();
	bool move3();
	bool movehome();
	Queue<int>* getQueue();
private:
	//Maze saved as dinamic
	int SIZE_X;
	int SIZE_Y;

	//Llista<int> stack_movements;
	Queue<int>* save_movements;
	Stack<int>* home_rute;
	Stack<Stack<int>*>* bif_position;// save the movements of the bot
	int total_beers;
	bool go_home;
	bot m_pBot;
	vector<vector<box>> m_matrix;
};
