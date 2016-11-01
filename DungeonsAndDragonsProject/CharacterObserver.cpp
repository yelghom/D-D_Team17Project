//! @file CharacterObserver.cpp
//! @brief Concrete implementation of the CharacterObserver 
//! class which displays the updated state of the Character class.
//! @author Venelin Koulaxazov, 26982425

#include "CharacterObserver.h"
#include "Character.h"
#include <iostream>
using namespace std;

//! Default constructor
CharacterObserver::CharacterObserver()
{
}

//! Constructor attaching the current instance of the class to the observable Character class.
CharacterObserver::CharacterObserver(Character* character)
{
	this->character = character;
	this->character->attachObserver(this);
}

//! Destructor detaching the current instance of the class from the observable Character class.
CharacterObserver::~CharacterObserver()
{
	this->character->detachObserver(this);
}

//! Handles the operation when the state of the observable class has changed.
void CharacterObserver::update()
{
	displayCharacter();
}

//! Displays the Character class instance and its current state.
void CharacterObserver::displayCharacter()
{
	cout << "Class: Fighter" << endl;
	cout << "Level: " << character->getLevel() << endl;
	cout << "Hit Points: " << character->getHitPoints() << endl;
	cout << "Armor Class: " << character->getArmorClass() << endl;
	cout << "Attack Bonus: " << character->getAttackBonus() << endl;
	cout << "Damage Bonus: " << character->getDamageBonus() << endl;
	cout << "Ability scores and modifiers:" << endl;
	cout << "\t Strength: " << character->getStrength() << ", " << character->getStrengthModifier() << endl;
	cout << "\t Dexterity: " << character->getDexterity() << ", " << character->getDexterityModifier() << endl;
	cout << "\t Constitution: " << character->getConstitution() << ", " << character->getConstitutionModifier() << endl;
	cout << "\t Intelligence: " << character->getIntelligence() << ", " << character->getIntelligenceModifier() << endl;
	cout << "\t Wisdom: " << character->getWisdom() << ", " << character->getWisdomModifier() << endl;
	cout << "\t Charisma: " << character->getCharisma() << ", " << character->getCharismaModifier() << endl << endl;
}