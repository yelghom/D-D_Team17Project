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
		item = "armor" + ++chestItem;
		break;
	case 2:
		item = "shield" + ++chestItem;
		break;
	case 3:
		item = "weapon" + ++chestItem;
		break;
	case 4:
		item = "boots" + ++chestItem;
		break;
	case 5:
		item = "ring" + ++chestItem;
		break;
	case 6:
		item = "helmet" + ++chestItem;
	}
}

//! Destructor
Chest::~Chest()
{
}