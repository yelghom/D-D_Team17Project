//! @file HealthBox.cpp
//! @brief Concrete implementation of the HealthBox class
//! @author Venelin Koulaxazov, 26982425

#include "HealthBox.h"
#include <iostream>

using namespace std;

//! Default constructor creating the value for the health boost
HealthBox::HealthBox()
{
	healthValue = 1 + rand() % 6;
}

//! Destructor
HealthBox::~HealthBox()
{
}

//! Gets the health value in this box
//! @return int value, the health value
int HealthBox::getHealthValue() const 
{ 
	cout << "Your character has been replenished " << healthValue << " extra hit points!" << endl;
	return healthValue; 
}