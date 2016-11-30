//! @file Character.cpp
//! @brief Concrete implementation of the Character class
//! @author Venelin Koulaxazov, 26982425

#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

//! Default constructor creating randomly generated ability scores and based on the new values, 
//! creates the modifiers for each ability.
Character::Character()
{
	for (int i = 0; i < 6; i++)
	{
		abilityScores.push_back(11 + rand() % 7);
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
	
	// Set the Character's initial coordinates
	xCoordinate = 1;
	yCoordinate = 1;
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

	// Set the Character's initial coordinates
	xCoordinate = 1;
	yCoordinate = 1;
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

//! Sets the x coordinate of the Character.
//! @param xCoordinate, the x coordinate
void Character::setXCoordinate(int xCoordinate)
{
	this->xCoordinate = xCoordinate;
}

//! Sets the y coordinate of the Character.
//! @param yCoordinate, the y coordinate
void Character::setYCoordinate(int yCoordinate)
{
	this->yCoordinate = yCoordinate;
}

// Custom methods

//! Equips the Character with the provided armor
//! @param armor: the armor with which the character is equipped
//! @return string value, the old armor of the character
string Character::equipArmor(string armor)
{
	string oldArmor = equipment[0];
	equipment[0] = armor;
	return oldArmor;
}

//! Equips the Character with the provided shield
//! @param shield: the shield with which the character is equipped
//! @return string value, the old shield of the character
string Character::equipShield(string shield)
{
	string oldShield = equipment[1];
	equipment[1] = shield;
	return oldShield;
}

//! Equips the Character with the provided weapon
//! @param weapon: the weapon with which the character is equipped
//! @return string value, the old weapon of the character
string Character::equipWeapon(string weapon)
{
	string oldWeapon = equipment[2];
	equipment[2] = weapon;
	return oldWeapon;
}

//! Equips the Character with the provided boots
//! @param boots: the boots with which the character is equipped
//! @return string value, the old boots of the character
string Character::equipBoots(string boots)
{
	string oldBoots = equipment[3];
	equipment[3] = boots;
	return oldBoots;
}

//! Equips the Character with the provided ring
//! @param ring: the ring with which the character is equipped
//! @return string value, the old ring of the character
string Character::equipRing(string ring)
{
	string oldRing = equipment[4];
	equipment[4] = ring;
	return oldRing;
}

//! Equips the Character with the provided helmet
//! @param helmet: the helmet with which the character is equipped
//! @return string value, the old helmet of the character
string Character::equipHelmet(string helmet)
{
	string oldHelmet = equipment[5];
	equipment[5] = helmet;
	return oldHelmet;
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

//! Adds the provided armor to the armor inventory of the Character.
//! @param armor: the armor to be added
void Character::addToArmorInventory(string armor)
{
	armorInventory.push_back(armor);
}

//! Adds the provided shield to the shield inventory of the Character.
//! @param shield: the shield to be added
void Character::addToShieldInventory(string shield)
{
	shieldInventory.push_back(shield);
}

//! Adds the provided weapon to the weapon inventory of the Character.
//! @param weapon: the weapon to be added
void Character::addToWeaponInventory(string weapon)
{
	weaponInventory.push_back(weapon);
}

//! Adds the provided boots to the boots inventory of the Character.
//! @param boots: the boots to be added
void Character::addToBootsInventory(string boots)
{
	bootsInventory.push_back(boots);
}

//! Adds the provided ring to the ring inventory of the Character.
//! @param ring: the ring to be added
void Character::addToRingInventory(string ring)
{
	ringInventory.push_back(ring);
}

//! Adds the provided helmet to the helmet inventory of the Character.
//! @param helmet: the helmet to be added
void Character::addToHelmetInventory(string helmet)
{
	helmetInventory.push_back(helmet);
}

//! Displays the entire inventory of the Character and provides a set of options to the user whether to update the Character in play.
void Character::displayInventory()
{
	// display all inventories
	displayArmorInventory();
	displayShieldInventory();
	displayWeaponInventory();
	displayBootsInventory();
	displayRingInventory();
	displayHelmetInventory();

	string userChoice;
	string inventoryChoice;
	int inventoryNumber;
	// give user the choice to equip something
	cout << "Do you wish to equip your character with something else? Yes (y) or No (n): " << flush;
	cin >> userChoice;

	while (userChoice == "y")
	{
		cout << "Which kind of item do you wish to change? " << flush;
		cin >> inventoryChoice;
		cout << "Which item do you wish to equip? " << flush;
		cin >> inventoryNumber;


		if (inventoryChoice == "Armor")
			armorInventory[inventoryNumber] = equipArmor(armorInventory[inventoryNumber]);
		else if (inventoryChoice == "Shield")
			shieldInventory[inventoryNumber] = equipShield(shieldInventory[inventoryNumber]);
		else if (inventoryChoice == "Weapon")
			weaponInventory[inventoryNumber] = equipWeapon(weaponInventory[inventoryNumber]);
		else if (inventoryChoice == "Boots")
			bootsInventory[inventoryNumber] = equipBoots(bootsInventory[inventoryNumber]);
		else if (inventoryChoice == "Ring")
			ringInventory[inventoryNumber] = equipRing(ringInventory[inventoryNumber]);
		else if (inventoryChoice == "Helmet")
			helmetInventory[inventoryNumber] = equipHelmet(helmetInventory[inventoryNumber]);

		cout << "Do you wish to equip your character with something else? " << flush;
		cin >> userChoice;
	}

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

//! Displays the armor inventory of the Character.
void Character::displayArmorInventory(){
	cout << "Armor inventory:" << endl;
	for (unsigned int i = 0; i < armorInventory.size(); i++)
	{
		cout << armorInventory[i] << " (" << i << "), ";
	}
	cout << endl;
}

//! Displays the shield inventory of the Character.
void Character::displayShieldInventory(){
	cout << "Shield inventory:" << endl;
	for (unsigned int i = 0; i < shieldInventory.size(); i++)
	{
		cout << shieldInventory[i] << " (" << i << "), ";
	}
	cout << endl;
}

//! Displays the weapon inventory of the Character.
void Character::displayWeaponInventory(){
	cout << "Weapon inventory:" << endl;
	for (unsigned int i = 0; i < weaponInventory.size(); i++)
	{
		cout << weaponInventory[i] << " (" << i << "), ";
	}
	cout << endl;
}

//! Displays the boots inventory of the Character.
void Character::displayBootsInventory(){
	cout << "Boots inventory:" << endl;
	for (unsigned int i = 0; i < bootsInventory.size(); i++)
	{
		cout << bootsInventory[i] << " (" << i << "), ";
	}
	cout << endl;
}

//! Displays the ring inventory of the Character.
void Character::displayRingInventory(){
	cout << "Ring inventory:" << endl;
	for (unsigned int i = 0; i < ringInventory.size(); i++)
	{
		cout << ringInventory[i] << " (" << i << "), ";
	}
	cout << endl;
}

//! Displays the helmet inventory of the Character.
void Character::displayHelmetInventory(){
	cout << "Helmet inventory:" << endl;
	for (unsigned int i = 0; i < helmetInventory.size(); i++)
	{
		cout << helmetInventory[i] << " (" << i << "), ";
	}
	cout << endl;
}

//! Adds the specified number of hit points to the Character.
void Character::replenishHitPoints(int hitPoints)
{
	this->hitPoints += hitPoints;
}