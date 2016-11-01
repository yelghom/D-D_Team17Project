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

	// custom methods
	void equipArmor(string armor);
	void equipShield(string shield);
	void equipWeapon(string weapon);
	void equipBoots(string boots);
	void equipRing(string ring);
	void equipHelmet(string helmet);

	void unequipArmor();
	void unequipShield();
	void unequipWeapon();
	void unequipBoots();
	void unequipRing();
	void unequipHelmet();

	bool validateNewCharacter();
	void hit(int hitPoints);

private:
	vector<int> abilityScores;
	vector<int> abilityModifiers;
	int hitPoints;
	int maxHitPoints;
	int level;
	int attackBonus;
	int damageBonus;
	int armorClass;
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
};