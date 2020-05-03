#include "GameGrid.h"

bool GameGrid::IsVerticalMovementPossible(){
	//Let's go through the whole board
	for (size_t boardIndex = 0; boardIndex < Height*Width; boardIndex++)
	{
		int numberToCheck = this->GameBoard.at(boardIndex).GetNumber();
		//if there is a 0 on the board movement is possible.
		if (numberToCheck==0) return true;
		else{
			if (IsLowerCellTheSame(boardIndex,numberToCheck)) return true;
		}
	}
	return false; //There are no 0's and no numbers in column cells are the same. Movement Up Is not possible
}
bool GameGrid::IsLowerCellTheSame(size_t index,int numberToCheck){
	//Since we are trying to access a lower cell that might not exist we're using a try catch
	try{
		int numberOnLowerRow = this->GameBoard.at(index+Width).GetNumber();
		if (numberOnLowerRow==numberToCheck) return true; // Since there are the same number movement is possible.
	}
	catch (std::out_of_range){} // this is expected.
}
bool GameGrid::IsHorizontalMovementPossible(){
	for (size_t boardIndex = 0; boardIndex < Height*Width; boardIndex++)
	{
		int numberToCheck = this->GameBoard.at(boardIndex).GetNumber();
		//if there is a 0 on the board movement is possible.
		if (numberToCheck==0) return true;
		else{
			if (IsRightCellTheSame(boardIndex,numberToCheck)) return true;
		}
	}
	return false;
}
bool GameGrid::IsRightCellTheSame(size_t index,int numberToCheck){
	if (index%Width==0) return false; //if index is diviable by width we are at a boundary, so no right cell exist.
	int numberOnRightColumn = this->GameBoard.at(index+1).GetNumber();
	if (numberToCheck == numberOnRightColumn)
	{
		return true;
	}
	return false;
}

//move the board up.
//Returns false when movement is not possible and has not happened.
bool GameGrid::MoveUp()
{
	if (!IsVerticalMovementPossible()) return false;
	for (size_t index = 0; index < Height*Width; index++)
	{
		try {
		Number Main = this->GameBoard.at(index);
		Number NextNumber = this->GameBoard.at(index+Width);
		Main.Join(NextNumber);
		}
		catch (std::out_of_range){}//expected.
	}
	return true;
	CheckForMaxNumber();
	SpawnNewNumber();
}

bool GameGrid::MoveDown()
{
	if (!IsVerticalMovementPossible()) return false;
	for (size_t index = Height*Width-1; index >= 0; index--)
	{
		try {
		Number Main = this->GameBoard.at(index);
		Number NextNumber = this->GameBoard.at(index-Width);
		Main.Join(NextNumber);
		}
		catch (std::out_of_range){}//expected.
	}
	return true;
	CheckForMaxNumber();
	SpawnNewNumber();
}

bool GameGrid::MoveRight()
{
	if (!IsHorizontalMovementPossible()) return false;
	for (size_t index = 0; index < Width*Height; index++)
	{
		if (index+1%4==0) continue; //if we are at the border we cannot join.
		Number Main = this->GameBoard.at(index);
		Number NextNumber = this->GameBoard.at(index+1);
		Main.Join(NextNumber);
	}
	CheckForMaxNumber();
	SpawnNewNumber();
	return true;
}

bool GameGrid::MoveLeft()
{
	
	if (!IsHorizontalMovementPossible()) return false;
	for (size_t index = Width*Height-1; index >= 0; index--)
	{
		if (index%4==0) continue; // if we are at the border we cannot join.
		Number Main = this->GameBoard.at(index);
		Number NextNumber = this->GameBoard.at(index-1);
		Main.Join(NextNumber);
	}
	CheckForMaxNumber();
	SpawnNewNumber();
	return true;
}
//Default 4x4 game setting.
GameGrid::GameGrid()
{
	Height = 4;
	Width = 4;
	this->GameBoard.resize(Height * Width);
	this->HasWon = false;
	this->MaxNumber = 2048;
	StartGame();
}
//Create new game
GameGrid::GameGrid(unsigned short Height, unsigned short Width, size_t MaxNumber)
{
	this->Height = Height;
	this->Width = Width;
	this->MaxNumber = MaxNumber;
	this->GameBoard.resize(Height * Width);
	this->HasWon = false;
	StartGame();
}

//displays numbers in the console
void GameGrid::GetValues()
{
	unsigned short y = 0;
	for (auto& i : GameBoard)
	{
		std::cout << i.GetNumber() << '\t';
		y++;
		if (y == Width)
		{
			y = 0;
			std::cout << std::endl;
		}
	}

}
//generates 3 numbers
void GameGrid::StartGame()
{
	for (size_t i = 0; i < 3; i++)
	{
		SpawnNewNumber();
	}
}

void GameGrid::CheckForMaxNumber()
{
	std::vector<Number>::iterator iterator;
	iterator = std::find(GameBoard.begin(), GameBoard.end(), MaxNumber);
	std::for_each(GameBoard.begin(),GameBoard.end(),&Reset);
	if (iterator != GameBoard.end())
	{
		this->HasWon = true;
	}
}
static void Reset(Number number){
	number.ResetTurn();
}
void GameGrid::SpawnNewNumber()
{
	bool isValue = true;
	size_t tmp = 0;
	do
	{
		tmp = std::rand() % (Height * Width);
		if (GameBoard.at(tmp).GetNumber() == 0) isValue = false;
	} while (isValue);
	if (std::rand() % 2 == 0)
	{
		GameBoard.at(tmp).SetNumber(2);
	}
	else
	{
		GameBoard.at(tmp).SetNumber(4);
	}
}