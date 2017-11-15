#include "maze.h"

maze::maze(){
	save_movements = new Queue<int>;
	bif_position = new Stack<Stack<int>*>;
	home_rute = new Stack<int>;
	total_beers = 0;
	go_home = false;

}
maze::~maze() {
	if (!save_movements->empty()) {
		while (!save_movements->empty()) {
			save_movements->remove();
		}
	}
	delete save_movements;

	while (!bif_position->empty()) {
		while (!bif_position->top()->empty()) {
			bif_position->top()->pop();
		}
		bif_position->pop();
	}
	delete bif_position;

	if (!home_rute->empty()) {
		while (!home_rute->empty()) {
			home_rute->pop();
		}
	}
	delete home_rute;
}

void maze::importMaze(const vector<vector<box>>& matrix, int sizeX, int sizeY)
{
	SIZE_X = sizeX;
	SIZE_Y = sizeY;

	//Knowing that vector have operator equal implemented
	m_matrix = matrix;

}

int maze::lenghtX()
{
	return SIZE_X;
}

int maze::lenghtY()
{
	return SIZE_Y;
}


void maze::incbeers() {
	total_beers++;
}

void maze::incbotbeers() {
	m_pBot.IncBeer();
}

vector<vector<box>> maze::getMatrix()
{
	return m_matrix;
}

void maze::setMatrix(vector<vector<box>> matrix) {
	m_matrix = matrix;
}

Queue<int>* maze::getQueue() {
	return save_movements;
}

bool maze::move() {
	int PosX = m_pBot.getPosX();
	int PosY = m_pBot.getPosY();
	bool move = false;

	if (PosY + 1 < SIZE_Y && PosY + 1 >= 0 && m_pBot.getMoved() != UP)
	{	//do down
		if (m_matrix[PosX][PosY + 1] != wall) {
			m_pBot.move(DOWN);
			m_pBot.setMoved(DOWN);
			update(0,1);
			move = true;
		}
		else if (PosX + 1 < SIZE_X && PosX + 1 >= 0 && m_pBot.getMoved() != LEFT) {
			if (m_matrix[PosX + 1][PosY] != wall) {
				//go right
				m_pBot.move(RIGHT);
				m_pBot.setMoved(RIGHT);
				update(1,0);
				move = true;
			}
			else if (PosY - 1 < SIZE_Y && PosY - 1 >= 0 && m_pBot.getMoved() != DOWN) {
				if (m_matrix[PosX][PosY - 1] != wall) {
					//go up
					m_pBot.move(UP);
					m_pBot.setMoved(UP);
					update(0,-1);
					move = true;
				}
				else if (PosX - 1 < SIZE_X && PosX - 1 >= 0 && m_pBot.getMoved() != RIGHT) {
					if (m_matrix[PosX - 1][PosY] != wall) {
						//go left
						m_pBot.move(LEFT);
						m_pBot.setMoved(LEFT);
						update(-1,0);
						move = true;
					}
				}
			}

		}

	}

	return move;
}

bool maze::move2(Queue<int> &q,Stack<int> &s) {
	int PosX = m_pBot.getPosX();
	int PosY = m_pBot.getPosY();
	int x, y;
	bool move = false;
	if (!q.empty()) {
			y = q.getFirst();
			q.remove();
			x = q.getFirst();
			q.remove();
			cout << x << y << endl;
			m_pBot.move(PosX + x, PosY + y);
			s.push(-1*x);
			s.push(-1*y);
			move = true;
	}else if(!s.empty()) {
			y = s.top();
			s.pop();
			x = s.top();
			s.pop();
			cout << x << y << endl;
			m_pBot.move(PosX + x, PosY + y);
			move = true;

	}
	return move;
}

bool maze::move3() {
	int PosX = m_pBot.getPosX();
	int PosY = m_pBot.getPosY();
	int Pos = PosY * 8 + PosX; //posicio de x,y puesto en un int, como la memoria de un vector en assembly
	bool move = false;
	int possible_rutes = 0;
	int direction = 0;
	Stack<int> rutes;
 

	cout << "moved: " << m_pBot.getMoved()<<endl;
	if (PosY + 1 < SIZE_Y && PosY + 1 >= 0 && m_pBot.getMoved() != UP)
	{
		if (m_matrix[PosX][PosY + 1] != wall) {
			// comprovar si se puede ir abajo
			possible_rutes++;
			rutes.push(DOWN);
			cout << "down ";
			move = true;
		}
	}
	if (PosX + 1 < SIZE_X && PosX + 1 >= 0 && m_pBot.getMoved() != LEFT) {
		if (m_matrix[PosX + 1][PosY] != wall) {
			//comprovar si se puede ir a derecha
			possible_rutes++;
			rutes.push(RIGHT);
			cout << "right ";
			move = true;
		}
	}
	if (PosY - 1 < SIZE_Y && PosY - 1 >= 0 && m_pBot.getMoved() != DOWN) {
		if (m_matrix[PosX][PosY - 1] != wall) {
			//comprovar si se puede ir arribar
			possible_rutes++;
			rutes.push(UP);
			cout << "up ";
			move = true;
		}
	}
	if (PosX - 1 < SIZE_X && PosX - 1 >= 0 && m_pBot.getMoved() != RIGHT) {
		if (m_matrix[PosX - 1][PosY] != wall) {
			//comprovar si se puede ir a izquierda 
			possible_rutes++;
			rutes.push(LEFT);
			cout << "left ";
			move = true;
		}
	}

	cout << endl;
	switch (possible_rutes) {
	case 0: // cuando llegas al final y solo puedes ir de vuelta a la posicion donde vienes   �->|
		cout << "case 0" << "bot beers: "<< m_pBot.getBeers()<<"total beers: "<<total_beers<<endl;
		/*  check if the bot collected all the beers and check if the bot is going to the initial position
			if is true the conditions the program finish here
		*/
		if (m_pBot.getBeers() == total_beers && !go_home) { 
			move = true; 
			go_home = true;
			direction = -1 * m_pBot.getMoved();
			m_pBot.move(direction);
			m_pBot.setMoved(direction);
		}
		else if(go_home) {
			move = false;
		}
		else {
			direction = m_pBot.getMoved();
			m_pBot.move(-1 * direction);
			m_pBot.setMoved(-1 * direction);
			move = true;
		}
		break;
	case 1: //cuando no hay bifurcaci�n
		/*the robot goes to the unique direction*/
		direction = rutes.top();
		rutes.pop();
		m_pBot.move(direction);
		m_pBot.setMoved(direction);
		cout << "case 1 " <<direction<<" "<< endl;
		move = true;
		break;
	case 2: //cuando hay bifurcación
	case 3:
		
		cout << "case 23" << endl;
		Stack<int>* aux=new Stack<int>;
		/*check if the robot is going to the initial position, if is true the condition
		  goes to the direction saved in the "home_rute" 
		*/
		if (go_home) {
			m_pBot.move(home_rute->top());
			home_rute->pop();
		}
		else {/*if doesn't meet the condition*/
			if (!bif_position->empty()) {//when the bif_position stack isn't empty
				if (bif_position->top()->top() == Pos) { /*check the position on bif_position if is equal to the current position
														   it means in the robot was here before, and we get the others directions
														   saved in the stack*/
					Pos = bif_position->top()->top();
					bif_position->top()->pop();

					m_pBot.move(bif_position->top()->top());
					m_pBot.setMoved(bif_position->top()->top());

					cout << "move 01: " << bif_position->top()->top() << endl;

					bif_position->top()->pop();

					if (bif_position->top()->empty()) { bif_position->pop(); home_rute->pop(); }
					else { bif_position->top()->push(PosY * 8 + PosX); }
					move = true;

				}
				else {
					aux->push(-1 * m_pBot.getMoved());
					home_rute->push(-1 * m_pBot.getMoved());
					m_pBot.move(rutes.top());
					m_pBot.setMoved(rutes.top());

					cout << "move 02: " << rutes.top() << endl;

					rutes.pop();
					for (int i = 0; i < possible_rutes - 1; i++) {
						direction = rutes.top();
						rutes.pop();
						aux->push(direction);
					}
					aux->push(PosY * 8 + PosX);
					bif_position->push(aux);
					move = true;
				}
			}
			else {
				aux->push(-1 * m_pBot.getMoved());
				home_rute->push(-1 * m_pBot.getMoved());
				m_pBot.move(rutes.top());
				m_pBot.setMoved(rutes.top());

				cout << "move 03: " << rutes.top() << endl;

				rutes.pop();
				for (int i = 0; i < possible_rutes - 1; i++) {
					direction = rutes.top();
					rutes.pop();
					aux->push(direction);
				}
				aux->push(PosY * 8 + PosX);
				bif_position->push(aux);
				move = true;
			}
		}
		break;
	}
	if (!rutes.empty()) {
		cout << "rutes sense buidar" << endl;
		while (!rutes.empty()) {
			cout << rutes.top() << " ";
			rutes.pop();
		}
	}
	else { cout << "rutes buides" << endl; }

	cout << "rutes buides" << endl;
	update(PosY, PosX);
	return move;
}

bool maze::movehome() {
	bool move = false;

	return move;
}



bot& maze::getBot() {
	return m_pBot;
}

//put the movements in a txt
void maze::update(int x,int y) {
	save_movements->add(x);
	save_movements->add(y);
}






