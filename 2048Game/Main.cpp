#include <iostream>
#include "./GameGrid.h"
using namespace std;

bool TryToMove(GameGrid *game);

int main()
{
	bool IsMoveSuccessful, Quit=false;
	GameGrid game = GameGrid();
	cout << "Game Started"<<endl;
	cout << "Use wasd to move" <<endl;
	game.GetValues();
	do
	{
		IsMoveSuccessful = TryToMove(&game,&Quit);
		if (Quit) break;
		
		if (IsMoveSuccessful)
			game.GetValues();

	} while (!game.HasWon);
	
	if (Quit)
		cout << "Quitting";
	else if (game.HasWon)
		cout << "You have won the game.";
	else 
		cout << "You have lost the game.";
	

	return 0;
}
bool TryToMove(GameGrid *Game,bool* QuitTheGame)
{
	char key;
	cin >> key;
	switch (key)
	{
	case 'w':
	case 'W':
		Game->MoveUp();
		return true;
	case 'a':
	case 'A':
		Game->MoveLeft();
		return true;
	case 's':
	case 'S':
		Game->MoveDown();
		return true;
	case 'd':
	case 'D':
		Game->MoveRight();
		return true;
	case 'q':
	case 'Q':
		*QuitTheGame = true;
		return false;
	default:
		//cout << "error";
		return false;
	}
}