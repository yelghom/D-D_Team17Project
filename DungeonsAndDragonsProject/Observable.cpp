//! @file Observable.cpp
//! @brief Concrete implementation for the Observable class
//! @author Venelin Koulaxazov, 26982425
#include "Observable.h"
#include <vector>
using namespace std;

//! Default constructor creating the list of observers and the current number of registerd observers
Observable::Observable()
{
}

//! Destructor
Observable::~Observable()
{
}

//! Attaches an observer to the list of observers for the instance.
void Observable::attachObserver(Observer* observer)
{
	// verify if the observer already exists in the collection
	for (unsigned int i = 0; i < observers.size(); i++)
	{
		if (observers[i] == observer)
			return;
	}

	// observer is not in collection so it can be added
	observers.push_back(observer);
}

//! Deatches the observer from the list of observers.
void Observable::detachObserver(Observer* observer)
{
	for (unsigned int i = 0; i < observers.size(); i++)
	{
		// delete observer only if it exists in the collection already
		if (observers[i] == observer)
			observers.erase(observers.begin() + i);
	}
}

//! Calls the update method of all observers that observe this instance.
void Observable::notify()
{
	for each (class Observer* observer in observers)
	{
		observer->update();
	}
}
