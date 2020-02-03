#include "GameGrid.h"
#include <algorithm>
#include <iostream>

void GameGrid::MoveUp()
{
	size_t* pValuesToCheck;
	size_t indicator = 0;
	pValuesToCheck = new size_t[Height];
	for (size_t i = 0; i < Width; i++)
	{
		for (size_t j = 0; j < Height; j++)
		{
			indicator = i + j * Width;
			*(pValuesToCheck + j) = Grid.at(indicator);
		}
		std::reverse(pValuesToCheck, pValuesToCheck + Height);
		this->Move(pValuesToCheck, Height);
		std::reverse(pValuesToCheck, pValuesToCheck + Height);
		for (size_t j = 0; j < Height; j++)
		{
			indicator = i + j * Width;
			Grid.at(indicator) = *(pValuesToCheck + j);
		}
	}
	CheckForMaxNumber();
	SpawnNewNumber();
}

void GameGrid::MoveDown()
{
	size_t* pValuesToCheck;
	size_t indicator = 0;
	pValuesToCheck = new size_t[Height];
	for (size_t i = 0; i < Width; i++)
	{
		for (size_t j = 0; j < Height; j++)
		{
			indicator = i + j * Width;
			*(pValuesToCheck + j) = Grid.at(indicator);
		}
		this->Move(pValuesToCheck, Height);
		for (size_t j = 0; j < Height; j++)
		{
			indicator = i + j * Width;
			Grid.at(indicator) = *(pValuesToCheck + j);
		}
	}
	CheckForMaxNumber();
	SpawnNewNumber();
}

void GameGrid::MoveRight()
{
	size_t* pValuesToCheck;
	size_t indicator = 0;
	pValuesToCheck = new size_t[Width];
	for (size_t i = 0; i < Height; i++)
	{
		for (size_t j = 0; j < Width; j++)
		{
			indicator = i *Width+j;
			*(pValuesToCheck + j) = Grid.at(indicator);
		}
		this->Move(pValuesToCheck, Width);
		for (size_t j = 0; j < Height; j++)
		{
			indicator = i * Width + j;
			Grid.at(indicator) = *(pValuesToCheck + j);
		}
	}
	CheckForMaxNumber();
	SpawnNewNumber();
}

void GameGrid::MoveLeft()
{
	size_t* pValuesToCheck;
	size_t indicator = 0;
	pValuesToCheck = new size_t[Width];
	for (size_t i = 0; i < Height; i++)
	{
		for (size_t j = 0; j < Width; j++)
		{
			indicator = i * Width + j;
			*(pValuesToCheck + j) = Grid.at(indicator);
		}
		std::reverse(pValuesToCheck, pValuesToCheck + Width);
		this->Move(pValuesToCheck, Width);
		std::reverse(pValuesToCheck, pValuesToCheck + Width);
		for (size_t j = 0; j < Height; j++)
		{
			indicator = i * Width + j;
			Grid.at(indicator) = *(pValuesToCheck + j);
		}
	}
	CheckForMaxNumber();
	SpawnNewNumber();
}

GameGrid::GameGrid()
{
	Height = 4;
	Width = 4;
	this->Grid.resize(Height * Width);
	this->HasWon = false;
	this->MaxNumber = 2048;
	StartGame();
}
GameGrid::GameGrid(unsigned short Height, unsigned short Width, size_t MaxNumber)
{
	this->Height = Height;
	this->Width = Width;
	this->MaxNumber = MaxNumber;
	this->Grid.resize(Height * Width);
	this->HasWon = false;
	StartGame();
}
void GameGrid::GetValues()
{

	unsigned short y = 0;
	for (auto& i : Grid)
	{
		std::cout << i << " ";
		y++;
		if (y == Width)
		{
			y = 0;
			std::cout << std::endl;
		}
	}

}
void GameGrid::GetValue(size_t val)
{
	std::cout << val << " ";
}
void GameGrid::StartGame()
{
	for (size_t i = 0; i < 3; i++)
	{
		SpawnNewNumber();
	}
}
void GameGrid::CheckForMaxNumber()
{
	std::vector<size_t>::iterator iterator;
	iterator = std::find(Grid.begin(), Grid.end(), MaxNumber);
	if (iterator != Grid.end())
	{
		this->HasWon = true;
	}
}
void GameGrid::SpawnNewNumber()
{
	bool isValue = true;
	size_t tmp = 0;
	do
	{
		tmp = std::rand() % (Height * Width);
		if (Grid.at(tmp) == 0) isValue = false;
	} while (isValue);
	if (std::rand() % 2 == 0)
	{
		Grid.at(tmp) = 2;
	}
	else
	{
		Grid.at(tmp) = 4;
	}
}

///Move given array
void GameGrid::Move(size_t vals[],unsigned short lenght)
{
	bool hasChanged;
	do
	{
		hasChanged = false;
		for (size_t i = 0; i < lenght - 1; i++)
		{
			if (vals[i] == 0) continue;
			else // value is not 0
			{
				if (vals[i + 1] == 0)
				{
					vals[i + 1] = vals[i];
					vals[i] = 0;
					hasChanged = true;
				}
				else if (vals[i + 1] == vals[i])
				{
					vals[i + 1] *= 2;
					vals[i] = 0;
					hasChanged = true;
				}
				
			}
		}
	} while (hasChanged);
}