//! @file Chest.cpp
//! @brief Concrete implementation of the Chest class
//! @author Venelin Koulaxazov, 26982425

#include "Chest.h"
#include <string>

using namespace std;

//! Default constructor creating the item contained in the chest.
Chest::Chest()
{
	switch (rand() % 6)
	{
	case 0:
		item = "armor" + to_string(nextChestItem());
		itemType = "Armor";
		break;
	case 1:
		item = "shield" + to_string(nextChestItem());
		itemType = "Shield";
		break;
	case 2:
		item = "weapon" + to_string(nextChestItem());
		itemType = "Weapon";
		break;
	case 3:
		item = "boots" + to_string(nextChestItem());
		itemType = "Boots";
		break;
	case 4:
		item = "ring" + to_string(nextChestItem());
		itemType = "Ring";
		break;
	case 5:
		item = "helmet" + to_string(nextChestItem());
		itemType = "Helmet";
	}
}

//! Destructor
Chest::~Chest()
{
}