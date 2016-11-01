//! @file CharacterObserver.h
//! @brief Header file for the Observable class.
//! @author Venelin Koulaxazov, 26982425
#pragma once

#include "Observer.h"
#include <vector>
using namespace std;

class Observable
{
public:
	Observable();
	~Observable();
	void attachObserver(Observer* observer);
	void detachObserver(Observer* observer);
	void notify();
private:
	vector<Observer*> observers;
};