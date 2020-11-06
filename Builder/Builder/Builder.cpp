#include <iostream>

struct Weapon
{
	int mPower;
};

struct Armor
{
	int mDefence;
};

class Character
{
public:
	Weapon* mWeapon;
	Armor* mArmor;

	void DisplayParts()
	{
		std::cout << mWeapon->mPower << std::endl;
		std::cout << mArmor->mDefence << std::endl;
	}
};

class CharacterBuilder
{
public:
	virtual Weapon* CreateWeapon() = 0;
	virtual Armor* CreateArmor() = 0;
};

class CharacterDirector
{
	CharacterBuilder* mBuilder;

public:
	void SetBuilder(CharacterBuilder* newBuilder)
	{
		mBuilder = newBuilder;
	}

	Character* CreateCharacter()
	{
		Character* character = new Character();
		
		character->mWeapon = mBuilder->CreateWeapon();
		character->mArmor = mBuilder->CreateArmor();

		return character;
	}
};

class ArcherBuilder : public CharacterBuilder
{
public:
	Weapon* CreateWeapon()
	{
		Weapon* weapon = new Weapon();
		weapon->mPower = 200;
		return weapon;
	}

	Armor* CreateArmor()
	{
		Armor* armor = new Armor();
		armor->mDefence = 50;
		return armor;
	}
};

class WarriorBuilder : public CharacterBuilder 
{ 
public: 
	Weapon* CreateWeapon() 
	{ 
		Weapon* weapon = new Weapon(); 
		weapon->mPower = 50; 
		return weapon; 
	} 
	Armor* CreateArmor() 
	{ 
		Armor* armor = new Armor(); 
		armor->mDefence = 200; 
		return armor; 
	} 
};

int main()
{
	Character* character;
	
	CharacterDirector director;

	ArcherBuilder archer;
	director.SetBuilder(&archer);
	character = director.CreateCharacter();
	character->DisplayParts();

	WarriorBuilder warrior;
	director.SetBuilder(&warrior);
	character = director.CreateCharacter();
	character->DisplayParts();

	std::cout<< "hi" << std:endl;
	return 0;
}