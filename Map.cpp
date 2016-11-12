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

#define DEFAULT_LENGTH_X 8
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

//! Constructor that takes custom length and width of the map that is to be created
Map::Map(int x, int y)
{
	gridLengthX = x;
	gridWidthY = y;
	mapGrid = new Cell*[gridLengthX];
	initializeMap();
}

Map::Map(string s){
	gridLengthX = loadMapLengthX(s);
	gridWidthY = loadMapWidthY(s);
	mapGrid = new Cell*[gridLengthX];
	for (int i = 0; i < gridLengthX; i++){

		mapGrid[i] = new Cell[gridWidthY];
	}


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
void Map::wallCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX - 1 || y < 0 || y >= gridWidthY - 1)
	{
		cout << "Undefined coordinates, please try again." << endl;
		cin >> x;
		cin >> y;
		wallCellAt(x, y);
	};

	mapGrid[x][y] = *new WallCell();
}

//! Places a Chest Cell at the following x and y coordiantes.
//! @param x, the x coordinate
//! @param y, the y coordinate
void Map::chestCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX - 1 || y < 0 || y >= gridWidthY - 1)
	{
		cout << "Undefined coordinates, please try again." << endl;
		cin >> x;
		cin >> y;
		chestCellAt(x, y);
	};

	mapGrid[x][y] = *new ChestCell();
}

//! Places a Empty Cell at the following x and y coordinates.
//! @param x, the x coordinate
//! @param y, the y coordinate
void Map::emptyCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX || y < 0 || y >= gridWidthY)
	{
		cout << "Undefined coordinates, please try again." << endl;
		cin >> x;
		cin >> y;
		emptyCellAt(x, y);
	};

	mapGrid[x][y] = *new EmptyCell();
}

//! Places a Character Cell at the following x and y coordinates.
//! @param x, the x coordinate
//! @param y, the y coordinate

void Map::characterCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX || y < 0 || y >= gridWidthY)
	{
		cout << "Undefined coordinates, please try again." << endl;
		cin >> x;
		cin >> y;
		characterCellAt(x, y);
	};

	mapGrid[x][y] = *new CharacterCell();
}

//! Places a Exit Map Cell at the following x and y coordinates.
//! @param x, the x coordinate
//! @param y, the y coordinate

void Map::exitMapCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX || y < 0 || y >= gridWidthY)
	{
		cout << "Undefined coordinates, please try again." << endl;
		cin >> x;
		cin >> y;
		exitMapCellAt(x, y);
	};

	mapGrid[x][y] = *new ExitMapCell();
}

//! Saves the current map to a file
void Map::saveMap(string s)
{
	ofstream myfile(s);

	if (myfile.is_open())
	{
		for (int i = 0; i < gridLengthX; i++)
		{
			for (unsigned int j = 0; j < gridWidthY; j++)
				myfile << mapGrid[i][j].getType();
			myfile << endl;
		}
		myfile.close();
	}
	else
		cout << "Unable to open file";
}

//! Returns the loaded map's length.
//! @param s, the file that contains the map
//! @return int value, the length of the map
int Map::loadMapLengthX(string s){

	ifstream file(s);
	char input[100];
	int i = 0;

	while (file.getline(input, sizeof(input)))
		i++;

	return i;
}
//! Returns the loaded map's width.
//! @param s, the file that contains the map
//! @return int value, the width of the map
int Map::loadMapWidthY(string s){

	int j = 0;
	char ch;
	fstream fin(s, fstream::in);
	while (fin >> noskipws >> ch)
	{
		if (ch == '\n')
			break;
		j++;
	}
	return j;
}

//! Loads the map from a file.
//! @param s, the file where the map is stored
void Map::loadMap(string s){
	fstream fin(s, fstream::in);
	char h;
	int k = 0;
	int l = 0;

	//loops through the grid and maps the characters of the map to the corresponding object cell
	for (k = 0; k <= gridLengthX; k++)
		for (l = 0; l <= gridWidthY; l++)
			while ((fin >> noskipws >> h))
			{
		if (h == '#')
			mapGrid[k][l] = *new WallCell();
		else if (h == '?')
			mapGrid[k][l] = *new ChestCell();
		//else if (h == '-')
			//mapGrid[k][l] = *new ExitMapCell();
		else
			mapGrid[k][l] = *new Cell();

		break;
			}
}