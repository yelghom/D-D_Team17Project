//! @file Map.h
//! @brief Header file for the Map class
//! @author Yousra El Ghomari, 26855873
//! @author Venelin Koulaxazov, 26982425
#pragma once

#include "Cell.h"

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Map{

public:

	// Constructors
	Map();
	Map(int x, int y);
	Map(string s);

	//! Destructor
	~Map();

	Cell getCellAt(int x, int y);

	void initializeMap();
	void printMap();
	void updatemap();
	
	void WallCellAt(int x, int y);
	void ChestCellAt(int x, int y);
	void EmptyCellAt(int x, int y);
	void CharacterCellAt(int x, int y);
	void ExitMapCellAt(int x, int y);

	void saveMap();

private:
	unsigned int gridLengthX;
	unsigned int gridWidthY;
	const char player = '@';
	Cell **mapGrid;
};
