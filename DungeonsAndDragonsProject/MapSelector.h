//! @file MapSelector.h
//! @brief Header file for the MapSelector class
//! @author Venelin Koulaxazov, 26982425

#pragma once

#include "Map.h"
#include <string>
#include <iostream>

using namespace std;

class MapSelector
{
public:
	void selectMap();
private:
	void standardMap(int choice);
	void createCustomMap(char cellChoice);
};