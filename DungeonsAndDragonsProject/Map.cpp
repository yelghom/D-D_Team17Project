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

#include <fstream>
#include <iostream>
using namespace std;

#define DEFAULT_LENGTH_X 8
#define DEFAULT_WIDTH_Y  8

using namespace std;


Map::Map(){

	gridLengthX = DEFAULT_LENGTH_X;
	gridWidthY = DEFAULT_WIDTH_Y;
	cout << "hello world" << endl;

	mapGrid = new Cell*[gridLengthX];

	initializeMap(gridLengthX, gridWidthY);
	cout << "length is" << gridLengthX << endl;
	cout << "width is" << gridWidthY << endl;
	cout << "hello world" << endl;
}

Map::Map(string s){


}

Map::Map(int customX, int customY){
	gridLengthX = customX;
	gridWidthY = customY;
	mapGrid = new Cell*[gridLengthX];
	initializeMap(gridLengthX, gridWidthY);
	cout << "length is" << gridLengthX << endl;
	cout << "width is" << gridWidthY << endl;
}

//! Destructor removing pointers in the mapgrid array
Map::~Map()
{
	for (int i = 0; i < gridWidthY; i++)
		delete[] mapGrid[i];
	delete[] mapGrid;
}

void Map::initializeMap(int length, int width){
	cout << "length issss" << length << endl;
	cout << "width issss" << width << endl;
	//system("pause");
	//Cell **mapgrid = new Cell*[gridLengthX];
	for (int i = 0; i < length; i++){

		mapGrid[i] = new Cell[width];

	}

	for (int i = 0; i < length; i++){

		for (int j = 0; j < width; j++){
			//	cout << "int j" << j << endl;
			if (i == 0 || i == length - 1 || j == 0 || j == width - 1){
				mapGrid[i][j] = *new WallCell();
			}
			else
			{
				//mapgrid[i][j] = *new cell();
				mapGrid[i][j] = *new Cell();
			}
			//	mapgrid[i][j] = *new emptyCell();
		}
	}

};

void Map::printMap(){

	cout << "Just went into print" << endl;

	cout << "length is" << gridLengthX << endl;
	cout << "width is" << gridWidthY << endl;

	for (int i = 0; i < gridLengthX; i++){
		//cout << "First for loop" << i << "gridWidth is" << gridWidthY<<endl;

		for (unsigned int j = 0; j < gridWidthY; j++){
			//cout << "Second for loop" << j << endl;

			cout << mapGrid[i][j].getType();
		}

		cout << endl;
	}
	cout << "Going out" << endl;

}

void Map::updatemap(){
	Cell **mapgrid = new Cell*[gridLengthX];
	//map currentmapgrid = new

	for (unsigned int i = 0; i < gridLengthX; i++)
	{
		for (unsigned int j = 0; j < gridWidthY; j++)
		{

		}

	}
}


void Map::WallCellAt(int x, int y){
	while (x < 0 || x >= gridLengthX - 1 || y < 0 || y >= gridWidthY - 1) {

		cout << "undefined index please try again" << endl;
		cin >> x;
		cin >> y;
		WallCellAt(x, y);

	};

	mapGrid[x][y] = *new WallCell();
	printMap();

}

void Map::ChestCellAt(int x, int y){
	while (x<0 || x >= gridLengthX - 1 || y<0 || y >= gridWidthY - 1) {

		cout << "undefined index please try again" << endl;
		cin >> x;
		cin >> y;
		ChestCellAt(x, y);

	};

	mapGrid[x][y] = *new ChestCell();
	printMap();
}

void Map::EntranceCellAt(int x, int y){
	while (x<0 || x >= gridLengthX - 1 || y<0 || y >= gridWidthY - 1) {

		cout << "undefined index please try again" << endl;
		cin >> x;
		cin >> y;
		EntranceCellAt(x, y);

	};

	//mapgrid[x][y] = *new EntrancecellAt();
	printMap();

}

void Map::ExitBlockAt(int x, int y){
	while (x<0 || x >= gridLengthX || y<0 || y >= gridWidthY) {

		cout << "undefined index please try again" << endl;
		cin >> x;
		cin >> y;
		ExitBlockAt(x, y);

	};

	//mapgrid[x][y] = *new ExitBlockAt();
	printMap();

};

void Map::saveMap(){
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