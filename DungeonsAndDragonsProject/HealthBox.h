//! @file HealthBox.h
//! @brief Header file for the HealthBox class
//! @author Venelin Koulaxazov, 26982425
#pragma once

#include <string>

using namespace std;

class HealthBox
{
public:

	//! Constructor.
	HealthBox();

	//! Destructor.
	~HealthBox();

	// getters

	int getHealthValue() const;

private:
	int healthValue;
};