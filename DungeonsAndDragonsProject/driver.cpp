//using this class just to test out the map methods

#include "map.h"
#include <iostream>

using namespace std;
int main()
{

	
	
	//map *themap = new Map();
	//themap->printMap();
	//themap->wallCellAt(2, 2);
	//themap-> chestCellAt(4, 7);
	Map *tmap = new Map(9, 8);
	tmap->printMap();
	tmap->chestCellAt(3, 4);
	tmap->wallCellAt(4, 4);
	tmap->wallCellAt(3, 3);
	tmap->wallCellAt(4, 3);
	tmap->wallCellAt(6, 3);
	tmap->chestCellAt(5, 4);
	tmap->chestCellAt(2, 4);
	tmap->saveMap();

	Map *lmap = new Map("myMap.txt");
	lmap->loadMap("myMap.txt");
	lmap->printMap();
	system("pause");
	return 0;
}