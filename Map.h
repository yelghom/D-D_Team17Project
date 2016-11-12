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

	void wallCellAt(int x, int y);
	void chestCellAt(int x, int y);
	void emptyCellAt(int x, int y);
	void characterCellAt(int x, int y);
	void exitMapCellAt(int x, int y);

	void saveMap(string s);
	void loadMap(string s);
	int loadMapLengthX(string s);
	int loadMapWidthY(string s);

private:
	unsigned int gridLengthX;
	unsigned int gridWidthY;
	Cell **mapGrid;
};