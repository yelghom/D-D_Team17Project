//! @file DungeonsAndDragonsProject.cpp
//! @brief Defines the entry point for the console application. It creates the Character and Map classes to provide some basic functionality for the Dungeons and Dragons game.
//! @author Venelin Koulxazov, 26982425

#include "Character.h"
#include "Chest.h"
#include <iostream>
#include <string>

//! Controls the flow of the entire application.
void main(int argc, char* argv[])
{
	Character *conan = setupCharacter();

	gameLoop();
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

//! Responsible for the game loop, i.e. takes in the user input that will correspond to where the Character should move.
//! @param c, the character
//! @param map, the map
void gameLoop(Character* c)
{
	// print map

	char userChoice;
	cout << "Direction of Character (w,a,s,d) " << flush;
	cin >> userChoice;

	while (userChoice == 'w' || userChoice == 'a' || userChoice == 's' || userChoice == 'd')
	{
		switch (userChoice)
		{
		case 'w': // user wants to go up
			switch (userChoice) // stub for now should be    map[c->getXCoordinate()][c->getYCoordinate() - 1]
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				c->setYCoordinate(c->getYCoordinate - 1); // empty cell, move character up
				break;
			case '?':
				c->setYCoordinate(c->getYCoordinate - 1); // move character up and open chest
				openChest(c, new Chest());
			}
			break;
		case 'a': // user wants to go left
			switch (userChoice) // stub for now should be    map[c->getXCoordinate() - 1][c->getYCoordinate()])
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				c->setXCoordinate(c->getXCoordinate - 1); // empty cell move character up
				break;
			case '?':
				c->setXCoordinate(c->getXCoordinate - 1); // move character left and open chest
				openChest(c, new Chest());
			}
			break;
		case 's': // user wants to go down
			switch (userChoice) // stub for now should be    map[c->getXCoordinate()][c->getYCoordinate() + 1])
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				c->setYCoordinate(c->getYCoordinate + 1); // empty cell move character down
				break;
			case '?':
				c->setYCoordinate(c->getYCoordinate + 1); // move character down and open chest
				openChest(c, new Chest());
			}
			break;
		case 'd': // user wants to go right
			switch (userChoice) // stub for now should be    map[c->getXCoordinate() + 1][c->getYCoordinate()])
			{
			case '#':
				break; // cannot move past a wall
			case ' ':
				c->setXCoordinate(c->getXCoordinate + 1); // empty cell move character down
				break;
			case '?':
				c->setXCoordinate(c->getXCoordinate + 1); // move character down and open chest
				openChest(c, new Chest());
			}			
		}


		// print map
		cout << "Direction of Character (w,a,s,d) " << flush;
		cin >> userChoice;
	}
}

//! Opens the chest and adds the item to the inventory panel of the Character.
//! @param c, the character
//! @param chest, the chest to be opened
void openChest(Character* c, Chest* chest) 
{
	if (chest->chestItemType() == "Armor")
		c->addToArmorInventory(chest->openChest);
	else if (chest->chestItemType() == "Shield")
		c->addToShieldInventory(chest->openChest);
	else if (chest->chestItemType() == "Weapon")
		c->addToWeaponInventory(chest->openChest);
	else if (chest->chestItemType() == "Boots")
		c->addToBootsInventory(chest->openChest);
	else if (chest->chestItemType() == "Ring")
		c->addToRingInventory(chest->openChest);
	else if (chest->chestItemType() == "Helmet")
		c->addToHelmetInventory(chest->openChest);
}

