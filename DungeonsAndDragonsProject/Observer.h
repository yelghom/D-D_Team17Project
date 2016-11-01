//! @file Observer.h
//! @brief Header file for the Observer class. Setting the structure for the Observer pattern.
//! @author Venelin Koulaxazov, 26982425
#pragma once

class Observer
{
public:
	virtual ~Observer();
	virtual void update() = 0;

protected:
	Observer();
};