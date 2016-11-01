//! @file CharacterObserver.h
//! @brief Header file for the CharacterObserver class. Specific observer for the Character class.
//! @author Venelin Koulaxazov, 26982425
#pragma once

#include "Observer.h"
#include "Character.h"

class CharacterObserver : public Observer
{
public:
	CharacterObserver();
	CharacterObserver(Character* character);
	~CharacterObserver();
	void update();
private:
	Character *character;

	void displayCharacter();
};