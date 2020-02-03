#include <iostream>
#include "GameGrid.h"
using namespace std;
void Move(GameGrid *game);
int main()
{
	GameGrid game = GameGrid();
	cout << "Game Started"<<endl;
	cout << "Use wasd to move" <<endl;
	game.GetValues();
	do
	{
		Move(&game);
		
		game.GetValues();

	} while (!game.HasWon);
}
void Move(GameGrid *game)
{
	char key;
	cin >> key;
	switch (key)
	{
	case 'w':
	case 'W':
		game->MoveUp();
		break;
	case 'a':
	case 'A':
		game->MoveLeft();
		break;
	case 's':
	case 'S':
		game->MoveDown();
		break;
	case 'd':
	case 'D':
		game->MoveRight();
		break;
	default:
		cout << "error";
		break;
	}
}