//! @file Map.cpp
//! @brief Concrete implementation of the Map class
//! @author Yousra El Ghomari, 26855873
//! @author Venelin Koulaxazov, 26982425

#include <cmath>
#include "Map.h"
#include "Cell.h"
#include "WallCell.h"
#include "ChestCell.h"
#include "EmptyCell.h"
#include "CharacterCell.h"
#include "ExitMapCell.h"
#include "EnemyCell.h"
#include "HealthCell.h"

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

//! Constructor that takes in a file name in order to load a map from a file
Map::Map(string s){
	gridLengthX = loadMapLengthX(s);
	gridWidthY = loadMapWidthY(s);
	mapGrid = new Cell*[gridLengthX];
	for (unsigned int i = 0; i < gridLengthX; i++)
		mapGrid[i] = new Cell[gridWidthY];
}

//! Destructor removing pointers in the mapgrid array
Map::~Map()
{
	for (unsigned int i = 0; i < gridWidthY; i++)
		delete[] mapGrid[i];
	delete[] mapGrid;
}

//! Initializes a default map.
void Map::initializeMap()
{
	// populate entire grid
	for (unsigned int i = 0; i < gridLengthX; i++)
		mapGrid[i] = new Cell[gridWidthY];

	for (unsigned int i = 0; i < gridLengthX; i++)
	{
		for (unsigned int j = 0; j < gridWidthY; j++){
			// put wall cells at the extremities of the map
			if (i == 0 || i == gridLengthX - 1 || j == 0 || j == gridWidthY - 1)
				mapGrid[i][j] = *new WallCell();

			else // empty cell for any other cells
				mapGrid[i][j] = *new EmptyCell();
		}
	}

}

//! Creates a default map
void Map::defaultMap(){

	mapGrid[1][10] = *new ChestCell();
	mapGrid[2][3] = *new WallCell();
	mapGrid[2][6] = *new WallCell();
	mapGrid[2][7] = *new WallCell();
	mapGrid[2][14] = *new WallCell();
	mapGrid[3][2] = *new WallCell();
	mapGrid[3][3] = *new WallCell();
	mapGrid[3][4] = *new WallCell();
	mapGrid[3][5] = *new WallCell();
	mapGrid[3][10] = *new WallCell();
	mapGrid[3][12] = *new WallCell();
	mapGrid[4][2] = *new ChestCell();
	mapGrid[4][4] = *new WallCell();
	mapGrid[4][7] = *new ChestCell();
	mapGrid[4][8] = *new WallCell();
	mapGrid[4][11] = *new WallCell();
	mapGrid[5][7] = *new WallCell();
	mapGrid[5][9] = *new ChestCell();
	mapGrid[5][11] = *new ChestCell();
	mapGrid[5][12] = *new WallCell();
	mapGrid[5][13] = *new ChestCell();
	mapGrid[6][9] = *new WallCell();
	mapGrid[1][1] = *new CharacterCell();
}


void Map::faultyMapOne(){

}

//! Saves the default map to a file
void Map::saveDefaultMap(){

	Map *themap = new Map();
	themap->defaultMap();
	themap->saveMap("DefaultMap.txt");
}

//! Runs through the grid and prints out the map.
void Map::printMap()
{

	for (unsigned int i = 0; i < gridLengthX; i++)
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

//! Places a Enemy Cell at the following x and y coordinates.
//! @param x, the x coordinate
//! @param y, the y coordinate

void Map::enemyCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX || y < 0 || y >= gridWidthY)
	{
		cout << "Undefined coordinates, please try again." << endl;
		cin >> x;
		cin >> y;
		enemyCellAt(x, y);
	};

	mapGrid[x][y] = *new EnemyCell();
}

//! Places a Health Cell at the following x and y coordinates.
//! @param x, the x coordinate
//! @param y, the y coordinate

void Map::healthCellAt(int x, int y)
{
	while (x < 0 || x >= gridLengthX || y < 0 || y >= gridWidthY)
	{
		cout << "Undefined coordinates, please try again." << endl;
		cin >> x;
		cin >> y;
		healthCellAt(x, y);
	};

	mapGrid[x][y] = *new HealthCell();
}

//! Saves the current map to a file
void Map::saveMap(string s)
{
	ofstream myfile(s);

	if (myfile.is_open())
	{
		for (unsigned int i = 0; i < gridLengthX; i++)
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
	unsigned int k = 0;
	unsigned int l = 0;

	//loops through the grid and maps the characters of the map to the corresponding object cell
	for (k = 0; k <= gridLengthX; k++)
	for (l = 0; l <= gridWidthY; l++)
	while ((fin >> noskipws >> h))
	{
		if (h == '#')
			mapGrid[k][l] = *new WallCell();
		else if (h == '?')
			mapGrid[k][l] = *new ChestCell();
		else if (h == '-')
			mapGrid[k][l] = *new ExitMapCell();
		else if (h == 'C')
			mapGrid[k][l] = *new CharacterCell();
		else if (h == 'E')
			mapGrid[k][l] = *new EnemyCell();
		else if (h == '+')
			mapGrid[k][l] = *new HealthCell();
		else
			mapGrid[k][l] = *new Cell();

		break;
	}
}

//! Verifies if map is correct
//! Based on the criterion that there shouldn't be a horizontal wall completely blocking the character from reaching the exit cell
//! "incorrectMap1.txt" is the first example of an incorrect map
bool Map::verifyMap1(){

	for (unsigned int i = 1; i < gridLengthX - 1; i++)
	{
		int count = 0;
		for (unsigned int j = 1; j < gridWidthY - 1; j++){
			if (mapGrid[i][j].getType() == '#')
				count++;
		}
		if (count == (gridWidthY - 2))
		{
			cout << "invalid Map" << endl;
			return false;
		}

	}
	cout << "valid Map" << endl;
	return true;
}

//! Verifies if map is correct
//! Based on the criterion that there shouldn't be a vertical wall completely blocking the character from reaching the exit cell
//! "incorrectMap2.txt" is the second example of an incorrect map
bool Map::verifyMap2(){
	for (unsigned int i = 1; i < gridWidthY - 1; i++)
	{
		int count = 0;
		for (unsigned int j = 1; j < gridLengthX - 1; j++){
			if (mapGrid[i][j].getType() == '#')
				count++;
		}
		if (count == (gridWidthY - 2))
		{
			cout << "invalid Map" << endl;
			return false;
		}

	}
	cout << "valid Map" << endl;
	return true;
}

//! Verifies if map is correct
//! Based on the criterion that there exists a wall in front of the exit preventing the character from reaching the exit map
//! "incorrectMap3.txt" is the third example of an incorrect map
bool Map::verifyMap3(){

	if (mapGrid[(gridLengthX - 2)][(gridWidthY - 2)].getType() == '#')
	{
		cout << "invalid map" << endl;
		return false;
	}
	else
	{
		cout << "valid Map" << endl;
		return true;
	}
}

//! Gets the x coordinate of the Character cell
int Map::getCharacterCellXCoordinate()
{
	for (unsigned int i = 0; i < gridLengthX; i++)
	for (unsigned int j = 0; j < gridWidthY; j++)
	if (mapGrid[i][j].getType() == 'C')
		return i;

}

//! Gets the y coordinate of the Character cell
int Map::getCharacterCellYCoordinate()
{
	for (unsigned int i = 0; i < gridLengthX; i++)
	for (unsigned int j = 0; j < gridWidthY; j++)
	if (mapGrid[i][j].getType() == 'C')
		return j;
}