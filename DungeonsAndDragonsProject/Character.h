//! @file Character.h
//! @brief Header file for the Character class
//! @author Venelin Koulaxazov, 26982425
#pragma once

#include "Observable.h"
#include <string>
#include <vector>

using namespace std;

class Character : public Observable
{
public:

	//! Constructors
	Character();
	Character(int str, int dex, int con, int intel, int wis, int cha);

	//! Destructor
	virtual ~Character();

	// getters

	//! Gets the name of the Character.
	//! @return string value, the name of the Character.
	string getName() const { return name; }

	//! Gets the strength ability score of the Character.
	//! @return int value, the strength ability score.
	int getStrength() const { return abilityScores[0]; }

	//! Gets the strength ability modifier of the Character.
	//! @return int value, the strength modifier.
	int getStrengthModifier() const { return abilityModifiers[0]; }

	//! Gets the dexterity ability score of the Character.
	//! @return int value, the dextrity ability score.
	int getDexterity() const { return abilityScores[1]; }

	//! Gets the dexterity ability modifier of the Character.
	//! @return int value, the dexterity modifier.
	int getDexterityModifier() const { return abilityModifiers[1]; }

	//! Gets the constitution ability score of the Character.
	//! @return int value, the constitution ability score.
	int getConstitution() const { return abilityScores[2]; }

	//! Gets the constitution ability modifier of the Character.
	//! @return int value, the constitution modifier.
	int getConstitutionModifier() const { return abilityModifiers[2]; }

	//! Gets the intelligence ability score of the Character.
	//! @return int value, the intelligence ability score.
	int getIntelligence() const { return abilityScores[3]; }

	//! Gets the intelligence ability modifier of the Character.
	//! @return int value, the intelligence modifier.
	int getIntelligenceModifier() const { return abilityModifiers[3]; }

	//! Gets the wisdom ability score of the Character.
	//! @return int value, the wisdom ability score.
	int getWisdom() const { return abilityScores[4]; }

	//! Gets the wisdom ability modifier of the Character.
	//! @return int value, the wisdom modifier.
	int getWisdomModifier() const { return abilityModifiers[4]; }

	//! Gets the charisma ability score of the Character.
	//! @return int value, the charisma ability score.
	int getCharisma() const { return abilityScores[5]; }

	//! Gets the charisma ability modifier of the Character.
	//! @return int value, the charisma modifier.
	int getCharismaModifier() const { return abilityModifiers[5]; }

	//! Gets the hit points of the Character.
	//! @return int value, the hit points.
	int getHitPoints() const { return hitPoints; }

	//! Gets the maximum hit points of the Character.
	//! @return int value, the maximum hit points.
	int getMaxHitPoints() const { return maxHitPoints; }

	//! Gets the current level of the Character.
	//! @return int value, the level.
	int getLevel() const { return level; }

	//! Gets the x coordinate of the Character on the map.
	//! @return int value, the x coordinate.
	int getXCoordinate() const { return xCoordinate; }

	//! Gets the y coordinate of the Character on the map.
	//! @return int value, the y coordinate.
	int getYCoordinate() const { return yCoordinate; }

	int getAttackBonus();
	int getDamageBonus();
	int getArmorClass();

	// setters
	void setName(string name);
	void setStrength(int str);
	void setDexterity(int dex);
	void setConstitution(int con);
	void setIntelligence(int intel);
	void setWisdom(int wis);
	void setCharisma(int cha);
	void setLevel(int level);
	void setXCoordinate(int xCoordinate);
	void setYCoordinate(int yCoordinate);

	// custom methods
	string equipArmor(string armor);
	string equipShield(string shield);
	string equipWeapon(string weapon);
	string equipBoots(string boots);
	string equipRing(string ring);
	string equipHelmet(string helmet);

	void unequipArmor();
	void unequipShield();
	void unequipWeapon();
	void unequipBoots();
	void unequipRing();
	void unequipHelmet();

	bool validateNewCharacter();
	void hit(int hitPoints);
	void replenishHitPoints(int hitPoints);

	void addToArmorInventory(string armor);
	void addToShieldInventory(string shield);
	void addToWeaponInventory(string weapon);
	void addToBootsInventory(string boots);
	void addToRingInventory(string ring);
	void addToHelmetInventory(string helmet);

	void displayInventory();

private:
	vector<int> abilityScores;
	vector<int> abilityModifiers;
	vector<string> armorInventory;
	vector<string> shieldInventory;
	vector<string> weaponInventory;
	vector<string> bootsInventory;
	vector<string> ringInventory;
	vector<string>helmetInventory;
	int hitPoints;
	int maxHitPoints;
	int level;
	int attackBonus;
	int damageBonus;
	int armorClass;
	int xCoordinate;
	int yCoordinate;
	string name;
	// type is to be changed from string to Item for intermediate project delivery
	string equipment[6];

	void setHitPoints(int hitPoints);
	void setMaxHitPoints(int maxHitPoints);
	void setAttackBonus(int attack);
	void setDamageBonus(int damage);
	void setArmorClass(int armor);

	int calculateModifier(int abilityScore);
	void calculateHitPoints();
	int calculateArmorClass();
	int calculateAttackBonus();
	int calculateDamageBonus();
	void displayArmorInventory();
	void displayShieldInventory();
	void displayWeaponInventory();
	void displayBootsInventory();
	void displayRingInventory();
	void displayHelmetInventory();
};