
#include <vector>


//Difinicions amb la variable d'activaci� de la llibreria gr�fica, __viz_graphics__
#include "Definitions.h"

#include "maze.h"
#include "bot.h"
#include "box.h"
#include "RobotMaze.h"

//Includes de les llibreries gr�fiques
#ifdef GRAPHICS
#define SDL_MAIN_HANDLED
#include "lib\libreria.h"
#include <windows.h>
#endif


//Do the code more complex
bool printMaze()
{
	return false;
}

int main(int argc, char* argv[])
{
	if (argc == 3) {
		const int SIZE_WINDOW = 600;
		Queue<int> q;
		Stack<int> rutes;
		maze maze;
		bot robot;
		bool fileOpen;
		int incbeer = 0;

		fileOpen = loadMaze(argv[1], maze.getBot(), maze);

		//laberint2
		//ReadMovements(q, "moviments.txt");
		if (!fileOpen)
		{
			cout << "ERROR: No se pudo abrir el archivo non_file.txt" << endl;
		}
		else {

#ifdef GRAPHICS
			SDL_SetMainReady();
			SDL_Init(SDL_INIT_VIDEO);

			//Set de size of window
			Game game(SIZE_WINDOW, SIZE_WINDOW);

			game.Init();

			Sprite wallGraphic;
			wallGraphic.Create("cnegre.png");
			Sprite roadGraphic;
			roadGraphic.Create("cblanc.png");
			Sprite beerGraphic;
			beerGraphic.Create("beer.png");
			Sprite robotGraphic;
			robotGraphic.Create("bender.png");

			game.Video_ShowWindow();
#endif
			int counter = 0;
			int i = 0;
			vector<vector<box>> matrix;
			bool finish = false;
			do {

				//get the matrix in the maze
				cout << "loop: " << i << " beers collected " << incbeer << endl;
				cout << "bot beers: " << maze.getBot().getBeers() << endl;
				matrix = maze.getMatrix();
#if GRAPHICS
				system("cls");
				for (int i = 0; i < maze.lenghtX(); i++)
				{
					for (int j = 0; j < maze.lenghtY(); j++)
					{
						switch (matrix[i][j])
						{
						case wall:
							//XGraphic.getScaleX() always get the same value 60, that it's the pixels of
							//image
							wallGraphic.Draw(i*wallGraphic.getScaleX(), j*wallGraphic.getScaleY());
							break;
						case road:
							roadGraphic.Draw(i*roadGraphic.getScaleX(), j*roadGraphic.getScaleY());
							break;
						case beer:
							beerGraphic.Draw(i*beerGraphic.getScaleX(), j*beerGraphic.getScaleY());
							break;
						}
					}
				}
				//Draw the robot
				robotGraphic.Draw(maze.getBot().getPosX()*robotGraphic.getScaleX(), maze.getBot().getPosY()* robotGraphic.getScaleY());
#endif
				//increase n� of beers if have beer in the maze
				if (matrix[maze.getBot().getPosX()][maze.getBot().getPosY()] == beer) {
					matrix[maze.getBot().getPosX()][maze.getBot().getPosY()] = road;
					maze.incbotbeers();
					incbeer++;
					//return the new matrix in the maze
					maze.setMatrix(matrix);
				}

				//finish = maze.move(); //laberint1
				finish = maze.move3();			 //laberint 2
				if (finish == true) cout << "finish movement" << endl;
				i++;

#ifdef GRAPHICS
				game.VideoUpdate();
				//6000 ms it's equal to 6 seconds
				Sleep(1000);
#endif

			} while (finish);

			SaveMovements(argv[2], maze);

#ifdef GRAPHICS
			SDL_Quit();
#endif
			return 0;
		}
	}
else {
	cout << "ERROR: Numero de argumentos incorrectos. Se esperaban 2" << endl;
	return 1;
}

}
