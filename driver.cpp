#include "Map.h"
#include <string>
#include <iostream>

Map* setupMap();
Map * chooseMap();
void standardMap(int y);
void createCustomMap(char cellChoice);

using namespace std;

int main(int argc, char* argv[])
{
	
	cout << "Welcome to the Map Selector" << endl;
	cout << "Menu \n 1. Choose a Standard Map\n 2. Create Custom Map\n 3.Upload saved Map from file" << endl;
	int mapType;
	int mapChoice=0;
	int width, length;
	char cellChoice='e';
	int indexX, indexY;
	string filename;
	cin >> mapType;
	switch (mapType)
	{
	case 1:
	{ 
		standardMap(mapChoice);
		cout << "Map saved to gameMap.txt" << endl;
		break;
	}
	case 2:
	{
		createCustomMap(cellChoice);
		break;
	}
	case 3:
	{
		cout << "Enter String name of the file of your saved Map" << endl;
		cin >> filename;
		Map *savedMap = new Map(filename);
		savedMap->loadMap(filename);
		cout << "your saved Map" << endl;
		savedMap->printMap();
		savedMap->saveMap("gameMap.txt");
		//save map to gameMap.txt and load it at the beginning of the game
		break;
	}
	default:
		cout << "standard Map will be used" << endl;
		Map * sMap1 = new Map("standardMap1.txt");
		sMap1->loadMap("standardMap1.txt");
		sMap1->saveMap("gameMap.txt");
			
	

	}
	//!testing for invalid maps 
	//! First incorrect map
	Map *incorrect = new Map("incorrectMap1.txt");
	 incorrect->loadMap("incorrectMap1.txt");
     incorrect->verifyMap1();
	 //! Second incorrect map
	 Map *incorrect2 = new Map("incorrectMap2.txt");
	 incorrect2->loadMap("incorrectMap2.txt");
	 incorrect2->verifyMap2();
	 //! third incorrect map
	 Map *incorrect3 = new Map("incorrectMap3.txt");
	 incorrect3->loadMap("incorrectMap3.txt");
	 incorrect3->verifyMap3();
		// hello->printMap();
		// hello->verifyMap3();
		//hello->verifyMap();
		// hello->verifyMap2();
	
		system("pause");
		return 0;
	
}
void standardMap(int Choice){

	//standard Map function
	Map * sMap1 = new Map("standardMap1.txt");
	sMap1->loadMap("standardMap1.txt");
	Map * sMap2 = new Map("standardMap2.txt");
	sMap2->loadMap("standardMap2.txt");
	Map * sMap3 = new Map("standardMap3.txt");
	sMap3->loadMap("standardMap3.txt");


	cout << "Choose one of the following standard map" << endl;
	//print standard maps
	cout << "Below are the three standard maps available in our game" << endl;
	cout << "\n 1:" << endl;
	sMap1->printMap();
	cout << "\n 2:" << endl;
	sMap2->printMap();
	cout << "\n 3:" << endl;
	sMap3->printMap();
	cout << "Choose standard Map 1,2 or3" << endl;
	cin >> Choice;
	switch (Choice)
	{
	case 1:
		sMap1->printMap();
		//return sMap1;
		sMap1->saveMap("gameMap.txt");
		//save map to gamemap.txt used.
		break;
	case 2:
		sMap2->printMap();
		sMap2->saveMap("gameMap.txt");
		//return sMap2;
		break;
	case 3:
		sMap3->printMap();
		sMap3->saveMap("gameMap.txt");
		//return sMap3;
		break;


	}
	

}

void createCustomMap(char cellChoice){

	int width, length;
	int indexX, indexY;
	cout << "Creating a custom Map, Please enter the width and length of the new Map" << endl;
	cin >> width;
	cin >> length;
	Map *customMap = new Map(length, width);
	cout << "Custom Map outline" << endl;
	customMap->printMap();
	cout << "Add Walls(w), Chest(c), and Oponents(o) in your custom map or (e) to end edit" << endl;
	cout << "follow choice with index of the map " << endl;
	cin >> cellChoice;
	while (cellChoice == 'w' || cellChoice == 'c' || cellChoice == 'o' || cellChoice == 'e')
	{

		switch (cellChoice)
		{
		case 'w':
			cout << "Index:" << endl;
			cin >> indexX;
			cin >> indexY;
			customMap->wallCellAt(indexX, indexY);
			break;
		case 'c':
			cout << "Index:" << endl;
			cin >> indexX;
			cin >> indexY;
			customMap->chestCellAt(indexX, indexY);
			break;
		case 'o':
			//add oponent cell here
			break;
		case 'e':

			break;

		}

		cout << "Add Walls(w), Chest(c), and Oponents(o) in your custom map or (e) to end edit" << endl;
		cin >> cellChoice;



	}
	cout << "Your Customized Map:" << endl;
	customMap->printMap();
	//cout << "Do you wish to make any changes call the function again" << endl;
	customMap->saveMap("gameMap.txt");


}