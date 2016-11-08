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
	
private:
	string item;
	int static chestItem;
};