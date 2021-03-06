#ifndef ABILITIES_H
#define ABILITIES_H

#include <iostream>
#include <fstream>
using namespace std;

class Abilities
{
	private: 
		string abilityName;
		int abilityType;
		/*
				Class Types
					0 - Magical
					1 - Physical
		*/
		int damageEffect; //Damage of attack on enemy
	public:
		Abilities(string n, int aT, int aD)
		{
			abilityName = n;
			abilityType = aT;
			damageEffect = aD;
		}
		Abilities()
		{
			abilityName = "New Ability";
			abilityType = -1;
			damageEffect = 0;
		}
        Abilities(Abilities* co)
		{
			abilityName = co->abilityName;
			abilityType = co->abilityType;
			damageEffect = co->damageEffect;
		}
		~Abilities()
		{
			cout << "Deleting Ability: " << abilityName << endl;
		}
		void PRINT()
		{
			cout << this->abilityName << endl;
			cout << "- Type: ";

			if(this->abilityType == 0)
				cout << "Magic Attack" << endl;
			else
				cout << "Physical Attack" << endl;

			cout << "- Effect: " << this->damageEffect << endl << endl;
		}
		void setName(string n)
		{
			this->abilityName = n;
		}
		void setAbilityType(int t)
		{
			this->abilityType = t;
		}
		void setDamageEffect(int dE)
		{
			this->damageEffect = dE;
		}
		string getName()
		{
			return abilityName;
		}
		int getAbilityType()
		{
			return abilityType;
		}
		int getDamageEffect()
		{
			return damageEffect;
		}
		void printToFile(ofstream &File)
		{
			cout << "Printing " << this->abilityName << " to file";
			File << this->abilityName << ",";
			cout << ".";
			File << this->abilityType << ",";
			cout << ".";
			File << this->damageEffect << ",";
			cout << ".";
			cout << "Done" << endl << endl;
		}
};
#endif