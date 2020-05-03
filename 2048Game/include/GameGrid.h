#pragma once
#include "Number.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class GameGrid
{
	public:
		bool HasWon;
		bool MoveUp();
		bool MoveDown();
		bool MoveRight();
		bool MoveLeft();
		GameGrid();
		GameGrid(unsigned short Height, unsigned short Width, size_t MaxNumber);
		void GetValues();//temporary until I'll come up with a better solution

	private:
		size_t MaxNumber;
		unsigned short Height, Width;
		std::vector<Number> GameBoard;
		void CheckForMaxNumber();
		void SpawnNewNumber();
		void GetValue(size_t val);
		//temporary until I'll come up with a better solution
		void StartGame();
		void Move(size_t vals[],unsigned short lenght);

		bool IsVerticalMovementPossible();
		bool IsHorizontalMovementPossible();
		bool IsRightCellTheSame(size_t index,int numberToCheck);
		bool IsLowerCellTheSame(size_t index,int numberToCheck);
};