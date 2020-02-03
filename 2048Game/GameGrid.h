#pragma once
#include <vector>
#include <string>
class GameGrid
{
	public:
		bool HasWon;
		void MoveUp();
		void MoveDown();
		void MoveRight();
		void MoveLeft();
		GameGrid();
		GameGrid(unsigned short Height, unsigned short Width, size_t MaxNumber);
		void GetValues();//temporary until I'll come up with a better solution

	private:
		size_t MaxNumber;
		unsigned short Height, Width;
		std::vector<size_t> Grid;
		void CheckForMaxNumber();
		void SpawnNewNumber();
		void GetValue(size_t val);
		//temporary until I'll come up with a better solution
		void StartGame();
		void Move(size_t vals[],unsigned short lenght);
};

