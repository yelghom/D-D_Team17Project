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
	case 1:
		item = "armor" + nextChestItem();
		itemType = "Armor";
		break;
	case 2:
		item = "shield" + nextChestItem();
		itemType = "Shield";
		break;
	case 3:
		item = "weapon" + nextChestItem();
		itemType = "Weapon";
		break;
	case 4:
		item = "boots" + nextChestItem();
		itemType = "Boots";
		break;
	case 5:
		item = "ring" + nextChestItem();
		itemType = "Ring";
		break;
	case 6:
		item = "helmet" + nextChestItem();
		itemType = "Helmet";
	}
}

//! Destructor
Chest::~Chest()
{
}