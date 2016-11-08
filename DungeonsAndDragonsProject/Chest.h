//! @file Chest.h
//! @brief Header file for the Chest class
//! @author Venelin Koulaxazov, 26982425
#pragma once

#include <string>

using namespace std;

class Chest
{
public:
	
	//! Constructor.
	Chest();

	//! Destructor.
	virtual ~Chest();

	// getters

	//! Opens the chest and gets the item contained in the chest.
	//! @return string value, the item contained in the chest
	string openChest() const { return item; }

	//! Gives the type of the item in the chest.
	//! @return string value, the type of item in the chest
	string chestItemType() const { return itemType; }
	
private:
	string item;
	string itemType;
	int static chestItem;
};