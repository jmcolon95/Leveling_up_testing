// Leveling_System_For_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <random>

using namespace std;

class Unit
{
private:
	string name;

	// Level system
	int level;
	int currentEXP;
	int maxLevel;

	// Stats
	int maxHp;
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
	int luck;

	// Growth rates (%)
	int strengthGrowth;
	int dexterityGrowth;
	int constitutionGrowth;
	int intelligenceGrowth;
	int wisdomGrowth;
	int charismaGrowth;
	int luckGrowth;

	// Random number gen
	mt19937 rng;


public:
	Unit(string unitName)
		: name(unitName),

		//level
		level(1),
		currentEXP(0),
		maxLevel(20), // Temp max lvl

		//stats
		strength(5),
		dexterity(5),
		constitution(5),
		intelligence(5),
		wisdom(5),
		charisma(5),
		luck(5),

		//growth
		strengthGrowth(50),
		dexterityGrowth(50),
		constitutionGrowth(50),
		intelligenceGrowth(50),
		wisdomGrowth(50),
		charismaGrowth(50),
		luckGrowth(50),

		rng(random_device{}())
	{
		//max hp due to constitution
		maxHp = (constitution * 4) + level;

	}

	void GainEXP(int amount)
	{
		if (level >= maxLevel)
		{
			cout << name << " is already max level!\n";
			return;
		}

		currentEXP += amount;

		cout << name << " gained " << amount << " EXP!\n";

		// Handle multiple level ups if needed
		while (currentEXP >= 100)
		{
			currentEXP -= 100;
			LevelUp();
		}
	}

	void LevelUp()
	{
		level++;

		uniform_int_distribution<int> roll(0, 100);

		cout << "\n=========================\n";
		cout << "\n" << name << " leveled up!\n";
		cout << "Now Level: " << level << "\n";
		cout << "\n=========================\n";

		// Strength Growth
		if (roll(rng) < strengthGrowth)
		{
			strength++;
			cout << "Strength +1\n";
		}

		// Dex growth
		if (roll(rng) < dexterityGrowth)
		{
			dexterity++;
			cout << "Dexterity +1\n";
		}

		// Con growth
		if (roll(rng) < constitutionGrowth)
		{
			constitution++;
			maxHp = (constitution * 4) + level;

			cout << "Constitution +1\n";
			cout << "Hp is now " << maxHp << "\n";
		}
		else {
			maxHp = (constitution * 4) + level;

			cout << "Hp is now " << maxHp << "\n";
		}

		// Int growth
		if (roll(rng) < intelligenceGrowth)
		{
			intelligence++;
			cout << "Intelligence +1\n";
		}

		// Wis growth
		if (roll(rng) < wisdomGrowth)
		{
			wisdom++;
			cout << "Wisdom +1\n";
		}

		// Cha growth
		if (roll(rng) < charismaGrowth)
		{
			charisma++;
			cout << "Charisma +1\n";
		}

		// Luck growth
		if (roll(rng) < luckGrowth)
		{
			luck++;
			cout << "Luck +1\n";
		}

		cout << endl;

	}

	void DisplayStats()
	{
		cout << "\n===== " << name << " =====\n";

		cout << "Level: " << level << endl;
		cout << "EXP: " << currentEXP << "/100\n";

		cout << "Hp: " << maxHp << endl;
		cout << "Strength: " << strength << endl;
		cout << "Dexterity: " << dexterity << endl;
		cout << "Constitution: " << constitution << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Wisdom: " << wisdom << endl;
		cout << "Charisma: " << charisma << endl;
		cout << "Luck: " << luck << endl;
	}

};

int main()
{
	srand(time(0));

	Unit hero("Aiden");

	hero.DisplayStats();

	hero.GainEXP(40);
	
	hero.GainEXP(70);

	hero.DisplayStats();

	hero.GainEXP(90);

	hero.DisplayStats();

	return 0;
}