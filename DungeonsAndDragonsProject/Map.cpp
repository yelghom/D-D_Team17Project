//! @file Map.cpp
//! @brief Concrete implementation of the Map class
//! @author Yousra El Ghomari, 26855873
//! @author Venelin Koulaxazov, 26982425

#include "Map.h"
#include "Cell.h"
#include "WallCell.h"
#include "ChestCell.h"
#include "EmptyCell.h"
#include "CharacterCell.h"
#include "ExitMapCell.h"

#include <fstream>
#include <iostream>
using namespace std;

#define DEFAULT_LENGTH_X 16
#define DEFAULT_WIDTH_Y  16

using namespace std;

//! Default constructor creating a map with predefined settings.
Map::Map()
{

	gridLengthX = DEFAULT_LENGTH_X;
	gridWidthY = DEFAULT_WIDTH_Y;

	mapGrid = new Cell*[gridLengthX];

	initializeMap();
}

Map::Map(string s)
{


}

//! Constructor that takes custom length and width of the map that is to be created
Map::Map(int x, int y)
{
	gridLengthX = x;
	gridWidthY = y;
	mapGrid = new Cell*[gridLengthX];
	initializeMap();
}

//! Destructor removing pointers in the mapgrid array
Map::~Map()
{
	for (int i = 0; i < gridWidthY; i++)
		delete[] mapGrid[i];
	delete[] mapGrid;
}

//! Initializes a default map.
void Map::initializeMap()
{
	// populate entire grid
	for (int i = 0; i < gridLengthX; i++)
		mapGrid[i] = new Cell[gridWidthY];

	for (int i = 0; i < gridLengthX; i++)
	{
		for (int j = 0; j < gridWidthY; j++){
			// put wall cells at the extremities of the map
			if (i == 0 || i == gridLengthX - 1 || j == 0 || j == gridWidthY - 1)
				mapGrid[i][j] = *new WallCell();
			else // empty cell for any other cells
				mapGrid[i][j] = *new EmptyCell();
		}
	}

}

//! Runs through the grid and prints out the map.
void Map::printMap()
{

	for (int i = 0; i < gridLengthX; i++)
	{
		for (unsigned int j = 0; j < gridWidthY; j++)
			cout << mapGrid[i][j].getType();
		cout << endl;
	}
}

void Map::updatemap()
{
	Cell **mapgrid = new Cell*[gridLengthX];
	//map currentmapgrid = new

	for (unsigned int i = 0; i < gridLengthX; i++)
	{
		for (unsigned int j = 0; j < gridWidthY; j++)
		{

		}

	}
}

//! Gets the Cell at the specified x and y coordinates.
//! @param x, the x coordinate
//! @param y, the y coordinate
//! @return Cell object, the Cell located at the x and y coordinates of the map
Cell Map::getCellAt(int x, int y)
{
	return mapGrid[x][y];
}

//! Places a Wall Cell at the following x and y coordiantes.
//! @param x, the x coordinate
//! @param y, the y coordinate
void Map::WallCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX - 1 || y < 0 || y >= gridWidthY - 1)
	{
		cout << "undefined index please try again" << endl;
		cin >> x;
		cin >> y;
		WallCellAt(x, y);

	};

	mapGrid[x][y] = *new WallCell();

}

//! Places a Chest Cell at the following x and y coordiantes.
//! @param x, the x coordinate
//! @param y, the y coordinate
void Map::ChestCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX - 1 || y < 0 || y >= gridWidthY - 1) 
	{
		cout << "undefined index please try again" << endl;
		cin >> x;
		cin >> y;
		ChestCellAt(x, y);

	};

	mapGrid[x][y] = *new ChestCell();
}

//! Places a Empty Cell at the following x and y coordinates.
//! @param x, the x coordinate
//! @param y, the y coordinate
void Map::EmptyCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX || y < 0 || y >= gridWidthY) 
	{
		cout << "undefined index please try again" << endl;
		cin >> x;
		cin >> y;
		ExitMapCellAt(x, y);

	};

	mapGrid[x][y] = *new EmptyCell();
}

//! Places a Character Cell at the following x and y coordinates.
//! @param x, the x coordinate
//! @param y, the y coordinate
void Map::CharacterCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX || y < 0 || y >= gridWidthY) 
	{

		cout << "undefined index please try again" << endl;
		cin >> x;
		cin >> y;
		ExitMapCellAt(x, y);

	};

	mapGrid[x][y] = *new CharacterCell();
}

//! Places a Exit Map Cell at the following x and y coordinates.
//! @param x, the x coordinate
//! @param y, the y coordinate
void Map::ExitMapCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX || y < 0 || y >= gridWidthY)
	{
		cout << "undefined index please try again" << endl;
		cin >> x;
		cin >> y;
		ExitMapCellAt(x, y);

	};

	mapGrid[x][y] = *new ExitMapCell();
}

void Map::saveMap()
{
	ofstream myfile("myMap.txt");

	if (myfile.is_open())
	{

		for (int i = 0; i < gridLengthX; i++){

			for (unsigned int j = 0; j < gridWidthY; j++){

				myfile << mapGrid[i][j].getType();
			}

			myfile << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";

}