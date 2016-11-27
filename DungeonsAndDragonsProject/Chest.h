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
	~Chest();

	// getters

	string openChest();

	//! Gives the type of the item in the chest.
	//! @return string value, the type of item in the chest
	string chestItemType() const { return itemType; }

	//! Increments the chest item counter.
	//! @return int value, the chest item counter
	static int nextChestItem() { return chestItem++; }
	
private:
	static int chestItem;
	string item;
	string itemType;
};