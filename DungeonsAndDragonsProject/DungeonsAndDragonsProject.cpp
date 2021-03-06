//! @file DungeonsAndDragonsProject.cpp
//! @brief Defines the entry point for the console application. It creates the Character and Map classes to provide some basic functionality for the Dungeons and Dragons game.
//! @author Venelin Koulxazov, 26982425

#include "Character.h"
#include "Chest.h"
#include "Map.h"
#include <iostream>
#include <string>
#include "MapSelector.h"
#include "HealthBox.h"

Character* setupCharacter();
void gameLoop(Character* c, Map* map);
void openChest(Character* c, Chest* chest);
void openHealthBox(Character* c, HealthBox* healthBox);
bool handleBattle(Character* c, Character* e);

int Chest::chestItem = 1;

//! Controls the flow of the entire application.
void main(int argc, char* argv[])
{
	Character *conan = setupCharacter();
	MapSelector *mapSelector = new MapSelector();
	mapSelector->selectMap();
	Map *map = new Map("gameMap.txt");
	map->loadMap("gameMap.txt");
	conan->setXCoordinate(map->getCharacterCellXCoordinate());
	conan->setYCoordinate(map->getCharacterCellYCoordinate());

	gameLoop(conan, map);
}

//! Responsible for the game loop, i.e. takes in the user input that will correspond to where the Character should move.
//! @param c, the character
//! @param map, the map
void gameLoop(Character* c, Map* map)
{
	// print map
	cout << endl << "Game start:" << endl;
	map->printMap();

	// Get the user choice for directions
	char userChoice;
	cout << "Direction of Character (w,a,s,d) or Inventory Panel (i)  or End Game (e): " << flush;
	cin >> userChoice;

	while (userChoice == 'w' || userChoice == 'a' || userChoice == 's' || userChoice == 'd' || userChoice == 'i')
	{
		switch (userChoice)
		{
		case 'w': // user wants to go up
			switch (map->getCellAt(c->getXCoordinate() - 1, c->getYCoordinate()).getType())
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setXCoordinate(c->getXCoordinate() - 1); // empty cell, move character up
				map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case '?':
				map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setXCoordinate(c->getXCoordinate() - 1); // move character up and open chest
				openChest(c, new Chest());
				map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case 'E':
				if (handleBattle(c, new Character()))
				{
					cout << "Your character won this battle with " << c->getHitPoints() << " hit points left!" << endl;
					map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
					c->setXCoordinate(c->getXCoordinate() - 1); // character won battle, move up
					map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				}
				else
					userChoice = 'l'; // character lost battle, end game
				break;
			case '+':
				map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setXCoordinate(c->getXCoordinate() - 1); // move character up and open health box
				openHealthBox(c, new HealthBox());
				map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
			}
			break;
		case 'a': // user wants to go left
			switch (map->getCellAt(c->getXCoordinate(), c->getYCoordinate() - 1).getType())
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setYCoordinate(c->getYCoordinate() - 1); // empty cell move character up
				map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case '?':
				map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setYCoordinate(c->getYCoordinate() - 1); // move character left and open chest
				openChest(c, new Chest());
				map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case 'E':
				if (handleBattle(c, new Character()))
				{
					cout << "Your character won this battle with " << c->getHitPoints() << " hit points left!" << endl;
					map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
					c->setXCoordinate(c->getXCoordinate() - 1); // character won battle, move up
					map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				}
				else
					userChoice = 'l'; // character lost battle, end game
			}
			break;
		case 's': // user wants to go down
			switch (map->getCellAt(c->getXCoordinate() + 1, c->getYCoordinate()).getType())
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setXCoordinate(c->getXCoordinate() + 1); // empty cell move character down
				map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case '?':
				map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setXCoordinate(c->getXCoordinate() + 1); // move character down and open chest
				openChest(c, new Chest());
				map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case 'E':
				if (handleBattle(c, new Character()))
				{
					cout << "Your character won this battle with " << c->getHitPoints() << " hit points left!" << endl;
					map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
					c->setXCoordinate(c->getXCoordinate() - 1); // character won battle, move up
					map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				}
				else
					userChoice = 'l'; // character lost battle, end game
			}
			break;
		case 'd': // user wants to go right
			switch (map->getCellAt(c->getXCoordinate(), c->getYCoordinate() + 1).getType())
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setYCoordinate(c->getYCoordinate() + 1); // empty cell move character down
				map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case '?':
				map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
				c->setYCoordinate(c->getYCoordinate() + 1); // move character down and open chest
				openChest(c, new Chest());
				map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				break;
			case 'E':
				if (handleBattle(c, new Character()))
				{
					cout << "Your character won this battle with " << c->getHitPoints() << " hit points left!" << endl;
					map->emptyCellAt(c->getXCoordinate(), c->getYCoordinate());
					c->setXCoordinate(c->getXCoordinate() - 1); // character won battle, move up
					map->characterCellAt(c->getXCoordinate(), c->getYCoordinate());
				}
				else
					userChoice = 'l'; // character lost battle, end game
			}
			break;
		case 'i':
			c->displayInventory();
		}

		if (userChoice == 'l')
			break;
		// print updated map and ask for future directions
		cout << endl;
		map->printMap();
		cout << "Direction of Character (w,a,s,d) or Inventory Panel (i)  or End Game (e): " << flush;
		cin >> userChoice;
	}

	if (userChoice == 'l')
	{
		cout << "You have lost the battle. Goodbye." << endl;
	}
	else
	{
		cout << "Do you wish to save this map for a later game? Yes (y) or No (n): " << flush;
		cin >> userChoice;

		if (userChoice == 'y')
		{
			map->saveMap("gameMap.txt");
			cout << "Map successfully saved. Goodbye." << endl;
		}
	}
	system("PAUSE");

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
	Character *conan = new Character(18, 18, 18, 18, 18, 18);
	conan->addToArmorInventory("smallArmor");
	conan->addToArmorInventory("bigArmor");
	conan->equipArmor("mediumArmor");

	conan->addToBootsInventory("smallBoots");
	conan->addToBootsInventory("bigBoots");
	conan->equipBoots("mediumBoots");

	return conan;
}

//! Handles a battle between the character and an enemy
//! @return boolean value, whether or not the character won the battle.
bool handleBattle(Character* c, Character* e)
{
	cout << "Your character has engaged into a battle with an enemy. " << endl;
	while (c->getHitPoints() > 0 && e->getHitPoints() > 0)
	{
		c->hit(e->getAttackBonus());
		e->hit(c->getAttackBonus());
	}

	if (c->getHitPoints() > 0)
		return true;
	else
		return false;
}

//! Opens the health box and replenishes hit points of the Character.
//! @param c, the character
//! @param healthBox, the health box to be opened
void openHealthBox(Character* c, HealthBox* healthBox)
{
	c->replenishHitPoints(healthBox->getHealthValue());
}