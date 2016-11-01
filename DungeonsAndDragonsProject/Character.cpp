//! @file Character.cpp
//! @brief Concrete implementation of the Character class
//! @author Venelin Koulaxazov, 26982425
#pragma once

#include "Character.h"

using namespace std;

//! Default constructor creating randomly generated ability scores and based on the new values, 
//! creates the modifiers for each ability.
Character::Character()
{
	// loop through the ability scores array and assign random values between the range of 3-18.
	for (int i = 0; i < 6; i++)
	{
		abilityScores.push_back(3 + rand() % 15);
	}

	//Set ability modifiers
	for (unsigned int i = 0; i < abilityScores.size(); i++)
	{
		abilityModifiers.push_back(calculateModifier(abilityScores[i]));
	}

	// Set the rest of the attributes of the Character
	level = 1;
	calculateHitPoints();
	armorClass = calculateArmorClass();
	attackBonus = calculateAttackBonus();
	damageBonus = calculateDamageBonus();
}

//! Constructor setting the members to the user preferences
Character::Character(int str, int dex, int con, int intel, int wis, int cha)
{
	abilityScores.push_back(str);
	abilityScores.push_back(dex);
	abilityScores.push_back(con);
	abilityScores.push_back(intel);
	abilityScores.push_back(wis);
	abilityScores.push_back(cha);

	//Set ability modifiers
	for (unsigned int i = 0; i < abilityScores.size(); i++)
	{
		abilityModifiers.push_back(calculateModifier(abilityScores[i]));
	}

	// Set the rest of the attributes of the Character
	level = 1;
	calculateHitPoints();
	armorClass = calculateArmorClass();
	attackBonus = calculateAttackBonus();
	damageBonus = calculateDamageBonus();
}

//! Destructor
Character::~Character()
{
}

// Standard setters for the members of the Character class.

//! Gets the attack bonus of the Character.
//! @return int value, the attack bonus.
int Character::getAttackBonus()
{
	return calculateAttackBonus();
}

//! Gets the damage bonus of the Character.
//! @return int value, the damage bonus.
int Character::getDamageBonus()
{
	return calculateDamageBonus();
}

//! Gets the armor class of the Character.
//! @return string value, the armor class of the Character.
int Character::getArmorClass()
{
	return calculateArmorClass();
}

// Standard setters for the members of the Character class.

//! Sets the name of the Character.
//! @param name, the name of the Character.
void Character::setName(string name)
{
	this->name = name;
}

//! Sets the strength score and modifier of the Character.
//! @param str, the strength ability score.
void Character::setStrength(int str)
{
	abilityScores[0] = str;
	abilityModifiers[0] = calculateModifier(str);

	// notify all observers
	notify();
}

//! Sets the dexterity score and modifier of the Character.
//! @param dex, the dexterity ability score.
void Character::setDexterity(int dex)
{
	abilityScores[1] = dex;
	abilityModifiers[1] = calculateModifier(dex);

	// notify all observers
	notify();
}

//! Sets the constitution score and modifier of the Character.
//! @param con, the constitution ability score.
void Character::setConstitution(int con)
{
	abilityScores[2] = con;
	abilityModifiers[2] = calculateModifier(con);

	// notify all observers
	notify();
}

//! Sets the intelligence score and modifier of the Character.
//! @param intel, the intelligence ability score.
void Character::setIntelligence(int intel)
{
	abilityScores[3] = intel;
	abilityModifiers[3] = calculateModifier(intel);

	// notify all observers
	notify();
}

//! Sets the wisdom of the Character.
//! @param wis, the wisdom ability score.
void Character::setWisdom(int wis)
{
	abilityScores[4] = wis;
	abilityModifiers[4] = calculateModifier(wis);

	// notify all observers
	notify();
}

//! Sets the charisma of the Character.
//! @param cha, the charisma ability score.
void Character::setCharisma(int cha)
{
	abilityScores[5] = cha;
	abilityModifiers[5] = calculateModifier(cha);

	// notify all observers
	notify();
}

//! Sets the hit points of the Character.
//! @param hitPoints, the hit points.
void Character::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}

//! Sets the level of the Character.
//! @param level, the level.
void Character::setLevel(int level)
{
	this->level = level;

	// notify all observers
	notify();
}

//! Sets the attack bonus of the Character.
//! @param attack, the attack bonus.
void Character::setAttackBonus(int attack)
{
	this->attackBonus = attack;
}

//! Sets the damage  bonus of the Character.
//! @param damage, the damage bonus.
void Character::setDamageBonus(int damage)
{
	this->damageBonus = damage;
}

// Custom methods

//! Equips the Character with the provided armor
//! @param armor: the armor with which the character is equipped
void Character::equipArmor(string armor)
{
	equipment[0] = armor;
}

//! Equips the Character with the provided shield
//! @param shield: the shield with which the character is equipped
void Character::equipShield(string shield)
{
	equipment[1] = shield;
}

//! Equips the Character with the provided weapon
//! @param weapon: the weapon with which the character is equipped
void Character::equipWeapon(string weapon)
{
	equipment[2] = weapon;
}

//! Equips the Character with the provided boots
//! @param boots: the boots with which the character is equipped
void Character::equipBoots(string boots)
{
	equipment[3] = boots;
}

//! Equips the Character with the provided ring
//! @param ring: the ring with which the character is equipped
void Character::equipRing(string ring)
{
	equipment[4] = ring;
}

//! Equips the Character with the provided helmet
//! @param helmet: the helmet with which the character is equipped
void Character::equipHelmet(string helmet)
{
	equipment[5] = helmet;
}

//! Removes the armor of the character.
void Character::unequipArmor()
{
	equipment[1] = "";
}

//! Removes the shield of the character.
void Character::unequipShield()
{
	equipment[2] = "";
}

//! Removes the weapon of the character.
void Character::unequipWeapon()
{
	equipment[3] = "";
}

//! Removes the boots of the character.
void Character::unequipBoots()
{
	equipment[4] = "";
}

//! Removes the ring of the character.
void Character::unequipRing()
{
	equipment[4] = "";
}

//! Removes the helmet of the character.
void Character::unequipHelmet()
{
	equipment[5] = "";
}

//! Verifies whether or not the newly created Character has valid ability scores.
//! @return bool value, true if the character is valid i.e. his ability scores are between 3-18; false otherwise
bool Character::validateNewCharacter()
{
	for (unsigned int i = 0; i < abilityScores.size(); i++)
	{
		if (abilityScores[i] < 3 || abilityScores[i] > 18)
			return false;
	}
	// if execution is still here, character is valid
	return true;
}

//! Administers damage to the Character.
//! @param hitPoints: the amount of points the player is losing after the attack.
void Character::hit(int hitPoints)
{
	this->hitPoints -= hitPoints;;

	//notify all observers
	notify();
}

//! Calculates a modifier value based on the provided ability score.
//! @param abilityScore: the value which will be used to calculate the modifier
//! @return int value, the calculated modifier value
int Character::calculateModifier(int abilityScore)
{
	int modifierValue;

	if (abilityScore <= 1)
		modifierValue = -5;
	else if (abilityScore <= 3)
		modifierValue = -4;
	else if (abilityScore <= 5)
		modifierValue = -3;
	else if (abilityScore <= 7)
		modifierValue = -2;
	else if (abilityScore <= 9)
		modifierValue = -1;
	else if (abilityScore <= 11)
		modifierValue = 0;
	else if (abilityScore <= 13)
		modifierValue = 1;
	else if (abilityScore <= 15)
		modifierValue = 2;
	else if (abilityScore <= 17)
		modifierValue = 3;
	else if (abilityScore <= 19)
		modifierValue = 4;
	else
		modifierValue = 5;

	return modifierValue;
}

//! Calculates the hit points which are based on the constitution modifier and level of the Character.
void Character::calculateHitPoints()
{
	hitPoints = getConstitutionModifier() + getLevel();
	maxHitPoints = getConstitutionModifier() + getLevel();
}

//! Calcuates the armor class which is based on the dexterity modifier of the Character.
//! @return int value, the armor class of the Character
int Character::calculateArmorClass()
{
	return (getDexterityModifier() + 10);
}

//! Calculates the attack bonus which is based on the strength modifier and level of the Charater.
//! @return int value, the attack bonus of the Character
int Character::calculateAttackBonus()
{
	return (getStrengthModifier() + getLevel());
}

//! Calculates the damage bonus which is based on the strength modifier of the Character.
//! @return int value, the damage bonus of the Character
int Character::calculateDamageBonus()
{
	return getStrengthModifier();
}
