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
	void initializeMap(int x, int y);
	void printMap();
	void updatemap();
	
	void WallCellAt(int x, int y);
	void ChestCellAt(int x, int y);
	void EntranceCellAt(int x, int y);
	void ExitBlockAt(int x, int y);
	void saveMap();

private:
	unsigned int gridLengthX;
	unsigned int gridWidthY;
	const char player = '@';
	Cell **mapGrid;
};
