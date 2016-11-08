#include "map1.h"
#include "cell.h"
#include <iostream>

#define DEFAULT_LENGTH_X 8
#define DEFAULT_WIDTH_Y  8

using namespace std;


	map::map(){

	int	gridLengthX = DEFAULT_LENGTH_X;
	int	gridWidthY = DEFAULT_WIDTH_Y;
	cell **mapgrid = new cell*[gridLengthX];
		
		initializeMap(gridLengthX, gridLengthX);
}

	map::map(int customX, int customY){
		gridLengthX = customX;
		gridWidthY = customY;
		cell **mapgrid = new cell*[gridLengthX];
		initializeMap(gridLengthX, gridLengthX);
	}

	void map::initializeMap(int length, int width){
		//Cell **mapgrid = new Cell*[gridLengthX];
		for (int i = 0; i < length; i++){
			mapgrid[i] = new cell[width];

		}

		for (int i = 0; i < length; i++){
			for (int j = 0; j < width; j++){
				if (i == 0 || i == length-1 || j == 0|| j == width-1 ){
					mapgrid[i][j] = *new wallCell();
				}
				
				mapgrid[i][j] = *new emptyCell();
			}
		}

	};

	void map::printmap(){

		for (unsigned int i = 0; i < gridLengthX ; i++){
			
			for (unsigned int j = 0; j < gridWidthY ;j++ ){

				cout << mapgrid[i][j].getType();
			}
			cout << endl;
		}
	}

	void map::updatemap(){
		cell **mapgrid = new cell*[gridLengthX];
		map currentmapgrid = new

		for (int i = 0; i < gridLengthX; i++)
		{
			for (int j = 0; j < gridWidthY; j++)
			{

			}

		}
	}

	/*
	void Map::WallcellAt(int x, int y){
		if (x<0 || x >= gridLengthX) return;
		if (y<0 || y >= gridWidthY) return;

		mapgrid[y][x] = *new wallCell();

		//initializemapafterchnage();
		
	}


	void Map::EntrancecellAt(int x, int y){
		if (x<0 || x >= GridSizeX) return;
		if (y<0 || y >= GridSizeY) return;

		theStart = *new entranceCell();
		theStart.setPositionX(x);
		theStart.setPositionY(y);
		MapGrid[y][x] = theStart;
		
	}

	void Map::ExitBlockAt(int x, int y){
		if (x<0 || x >= GridSizeX) return;
		if (y<0 || y >= GridSizeY) return;
		theEnd = *new ExitBlock();
		theEnd.setPositionX(x);
		theEnd.setPositionY(y);
		MapGrid[y][x] = theEnd;
		NotifyObservers();
	};


	*/

	



	