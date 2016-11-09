//! @file DungeonsAndDragonsProject.cpp
//! @brief Defines the entry point for the console application. It creates the Character and Map classes to provide some basic functionality for the Dungeons and Dragons game.
//! @author Venelin Koulxazov, 26982425

#include "Character.h"
#include "Chest.h"
#include "Map.h"
#include <iostream>
#include <string>
Character* setupCharacter();
Map* setupMap(Character* c);
void gameLoop(Character* c, Map* map);
void openChest(Character* c, Chest* chest);

int Chest::chestItem = 1;

//! Controls the flow of the entire application.
void main(int argc, char* argv[])
{
	Character *conan = setupCharacter();
	Map *map = setupMap(conan);

	gameLoop(conan, map);
}

//! Responsible for the game loop, i.e. takes in the user input that will correspond to where the Character should move.
//! @param c, the character
//! @param map, the map
void gameLoop(Character* c, Map* map)
{
	// print map
	map->printMap();

	// Get the user choice for directions
	char userChoice;
	cout << "Direction of Character (w,a,s,d) or Inventory Panel (i)  or End Game (e) " << flush;
	cin >> userChoice;

	while (userChoice == 'w' || userChoice == 'a' || userChoice == 's' || userChoice == 'd' || userChoice == 'i')
	{
		switch (userChoice)
		{
		case 'w': // user wants to go up
			switch (map->getCellAt(c->getXCoordinate() -1, c->getYCoordinate()).getType()) 
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				map->EmptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setXCoordinate(c->getXCoordinate() - 1); // empty cell, move character up
				map->CharacterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case '?':
				map->EmptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setXCoordinate(c->getXCoordinate() - 1); // move character up and open chest
				openChest(c, new Chest());
				map->CharacterCellAt(c->getXCoordinate(), c->getYCoordinate());
			}
			break;
		case 'a': // user wants to go left
			switch (map->getCellAt(c->getXCoordinate(), c->getYCoordinate() - 1).getType())
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				map->EmptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setYCoordinate(c->getYCoordinate() - 1); // empty cell move character up
				map->CharacterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case '?':
				map->EmptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setYCoordinate(c->getYCoordinate() - 1); // move character left and open chest
				openChest(c, new Chest());
				map->CharacterCellAt(c->getXCoordinate(), c->getYCoordinate());
			}
			break;
		case 's': // user wants to go down
			switch (map->getCellAt(c->getXCoordinate() + 1, c->getYCoordinate()).getType())
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				map->EmptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setXCoordinate(c->getXCoordinate() + 1); // empty cell move character down
				map->CharacterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case '?':
				map->EmptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setXCoordinate(c->getXCoordinate() + 1); // move character down and open chest
				openChest(c, new Chest());
				map->CharacterCellAt(c->getXCoordinate(), c->getYCoordinate());
			}
			break;
		case 'd': // user wants to go right
			switch (map->getCellAt(c->getXCoordinate(), c->getYCoordinate() + 1).getType()) 
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				map->EmptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setYCoordinate(c->getYCoordinate() + 1); // empty cell move character down
				map->CharacterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case '?':
				map->EmptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setYCoordinate(c->getYCoordinate() + 1); // move character down and open chest
				openChest(c, new Chest());
				map->CharacterCellAt(c->getXCoordinate(), c->getYCoordinate());
			}			
			break;
		case 'i':
			c->displayInventory();
		}


		// print updated map and ask for future directions
		cout << endl;
		map->printMap();
		cout << "Direction of Character (w,a,s,d) or Inventory Panel (i)  or End Game (e): " << flush;
		cin >> userChoice;
	}

	cout << "Do you wish to save this map for a later game? Yes (y) or No (n): " << flush;
	cin >> userChoice;

	if (userChoice == 'y')
	{
		map->saveMap();

		cout << "Map successfully saved. Goodbye." << flush;
		cin >> userChoice;
	}
}

//! Opens the chest and adds the item to the inventory panel of the Character.
//! @param c, the character
//! @param chest, the chest to be opened
void openChest(Character* c, Chest* chest)
{
	if (chest->chestItemType() == "Armor")
		c->addToArmorInventory(chest->openChest());
	else if (chest->chestItemType() == "Shield")
		c->addToShieldInventory(chest->openChest());
	else if (chest->chestItemType() == "Weapon")
		c->addToWeaponInventory(chest->openChest());
	else if (chest->chestItemType() == "Boots")
		c->addToBootsInventory(chest->openChest());
	else if (chest->chestItemType() == "Ring")
		c->addToRingInventory(chest->openChest());
	else if (chest->chestItemType() == "Helmet")
		c->addToHelmetInventory(chest->openChest());
}

//! Helper method to create a Character with some basic inventory.
//! @return Character object, the newly created Character
Character* setupCharacter()
{
	Character *conan = new Character();
	conan->addToArmorInventory("smallArmor");
	conan->addToArmorInventory("bigArmor");
	conan->equipArmor("mediumArmor");

	conan->addToBootsInventory("smallBoots");
	conan->addToBootsInventory("bigBoots");
	conan->equipBoots("mediumBoots");

	return conan;
}

//! Creates and populates a map with multiple cells to provide a more interactive game.
//! @param c, the Character on the map
Map* setupMap(Character* c)
{
	Map *map = new Map();
	map->CharacterCellAt(c->getXCoordinate(), c->getYCoordinate());

	return map;
}

