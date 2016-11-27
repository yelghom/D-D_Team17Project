#include "Map.h"
#include <iostream>

using namespace std;
int main()
{


	cout << " Creation of a Standard Map" << endl;
	Map *themap = new Map();
	cout << " Printing of the Standard Map" << endl;
	themap->printMap();
	cout << " Making changes to the standars map" << endl;
	themap->wallCellAt(2, 2);
	themap->chestCellAt(4, 7);
	cout << " View changes to the standars map" << endl;
	themap->printMap();
	cout << " Creation of a Customized dimension Map" << endl;
	Map *tmap = new Map(9, 8);
	cout << " Printing of the Customized dimension Map" << endl;
	tmap->printMap();
	cout << " Making changes to the Customized dimension map" << endl;
	tmap->chestCellAt(3, 4);
	cout << "Inputs illegal index to the map" << endl;
	tmap->wallCellAt(10, 4);
	tmap->wallCellAt(3, 3);
	tmap->wallCellAt(4, 3);
	tmap->wallCellAt(6, 3);
	tmap->chestCellAt(5, 4);
	tmap->chestCellAt(2, 4);
	cout << " View changes to the Customized dimension map" << endl;
	tmap->printMap();
	cout << "Saving standard Map to file: myMap.txt" << endl;
	tmap->saveMap("myMap.txt");
	cout << "Saving Customized dimension Map to file: myMap2.txt" << endl;
	themap->saveMap("myMap2.txt");

	cout << "Load map standard map from file it was saved on" << endl;
	Map *lmap = new Map("myMap.txt");
	lmap->loadMap("myMap.txt");
	cout << " Displaying of the loaded Map" << endl;
	lmap->printMap();
	cout << "Load map Customized dimension Map from file it was saved on" << endl;
	Map *kmap = new Map("myMap2.txt");

	kmap->loadMap("myMap2.txt");
	cout << " Displaying of the loaded Map" << endl;
	kmap->printMap();
	system("pause");
	return 0;
}