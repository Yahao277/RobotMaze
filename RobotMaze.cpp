#include "RobotMaze.h"


//read the maze
bool loadMaze(const char* txt, bot &bot, maze &maze)
{
	ifstream f;
	int sizeX, sizeY, startBotX, startBotY;

	f.open(txt);

	if (f.is_open())
	{
		//Extract robot initial postion and the size of the maze
		f >> startBotY >> startBotX;
		f >> sizeX >> sizeY;

		//Inicialize vector to a certanly size
		//Using vector non-default constructor
		vector<vector<box>> matrix(sizeY, vector<box>(sizeX));
		int boxType;

		//Extract de matrix
		for (int i = 0; i <sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
			{
				f >> boxType;
				switch (boxType)
				{
				case 0:
					matrix[j][i] = wall;
					break;
				case 1:
					matrix[j][i] = road;
					break;
				case 2:
					matrix[j][i] = beer;
					maze.incbeers();
					break;
					//default:
					//throw and exception, to do
				}
			}
		}

		bot.setInitialPos(startBotX, startBotY);
		maze.importMaze(matrix, sizeX, sizeY);

		f.close();
		return true;
	}
	else
	{
		return false;
	}

}

void ReadMovements(Queue<int> &q, const char* txt) {
	ifstream fitxer;
	fitxer.open(txt);
	int x, y;
	if (fitxer.is_open()) {
		while (!fitxer.eof()) {
			fitxer >> x >> y;
			q.add(x);
			q.add(y);
			cout << x << y << endl;
		}
	}
	fitxer.close();
}

void StackMovements(Stack<int> &s) {

}

void SaveMovements(const char* txt, maze &m) {
	ofstream fitxer;
	int x, y;
	fitxer.open(txt);
	if (fitxer.is_open()) {

		fitxer << m.getBot().getBeers() << endl;

		while (!m.getQueue()->empty()) {
			x = m.getQueue()->getFirst();
			fitxer << x;
			fitxer << " ";
			m.getQueue()->remove();

			y = m.getQueue()->getFirst();
			fitxer << y << endl;
			m.getQueue()->remove();
		}
		fitxer.close();
	}
	else {
		cout << "ERROR: No se pudo abrir el archivo non_file.txt";
	}
}
