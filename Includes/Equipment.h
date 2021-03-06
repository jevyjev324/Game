/*
	Programmer: Jevin Evans
	Date: 7/19/2019
	Program: Equipment Class
	Description: The Equipment class allows for creation of objects in the game to be used by characters and placed inside of the armor or in other holders/storage containers inside of the game 
 */

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <fstream>
using namespace std;

class Equipment
{
	private:
		string name;				//Item Name
		int IT;						//Item Types: 0 - Weapon, 1 - Helmet, 2 - Chest, 3 - Pants,
		int AT;						//Armor Types: 0 - Light, 1 - Medium, 2 - Heavy
		int WT;						//Weapon Types: 0 - NULL, 1 - Wand, 2 - Sword, 3 - Knief
		int level;					//Item Level
		string desc;				//Description of Item
		int abilityPts;				//The amount of protection or damage a item can cause
	
	public:
/*
	Function:		Constructor
	Parameters:		NULL
	Description: 	This method creates a new blank object that is customizable through the setter functions
*/
		Equipment()				
		{
			name = "NULL";
			IT = -1;
			AT = -1;
			WT = -1;
			level = -1;
			desc = "NULL";
			abilityPts = -1;
		}

/*
	Function:		Constructor
	Parameters:		string name, int item type, int armor type, int weapon type, int level, string description, int ability points
	Description: 	This method creates a new blank object that is customizable through the setter functions
*/	
		Equipment(string na, int it, int at, int wt, int le, string de, int aP)
		{
			name = na;
			IT = validate(it);
			AT = validate(at);
			WT = validate(wt);
			level = le;
			desc = de;
			abilityPts = aP;
		}
		
/*
	Function:		PRINT
	Parameters:		NULL
	Description: 	This method prints out a formatted version of the information for the item including name, type, level, description , and ability points
*/		
		void PRINT()
		{
			cout << "\n" << getName();
			cout << "\n------------------------ ";
			cout << "\n Type: ";
			getItemType();
			cout << "\n Level: " << getLevel();
			cout << "\n Description: " << getDescription();
			cout << "\n Ability Points: " << getAbilityPts();
			
			if(IT == 0)
				cout << " ATK" << endl << endl;
			else
			cout << " DEF" << endl << endl;
		}

/*
	Function:		getItemType
	Parameters:		NULL
	Description: 	This method returns a description string for the item type
*/

		void getItemType()
		{
			string item ="";
			switch(IT)
			{
				case 0:
					switch(WT)
					{
						case 1:
							item += "Wand";
							break;
						case 2:
							item += "Sword";
							break;
						case 3:
							item += "Knief";
							break;
						default:
							item += "";
							break;
					}
					break;
				case 1:
					item += "Helmet";
					break;
				case 2:
					item += "Chestplate";
					break;
				case 3:
					item += "Pants";
					break;
				default:
					item = "";
					break;
			}
			if( IT != 0)
			{
				switch(AT)
				{
					case 0:
						item = "Light " + item;
						break;
					case 1:
						item = "Medium " + item;
						break;
					case 2:
						item = "Heavy " + item;
						break;
				}
			}
			if(item.compare(""))
				cout << "Broken Item";
			cout << item;
		}

/*
	Function:		printToFile
	Parameters:		Ofstream (aka Output File)
	Description: 	To print the data of a equipment object to a file that is passed in.
*/
		void printToFile(ofstream &File)
		{
			File << name << ",";
			File << IT << ",";
			File << AT << ",";
			File << WT << ",";
			File << level << ",";
			File << desc << ",";
			File << abilityPts << "," << endl;
			cout << "Printed " << this->name << endl;
		}	

/*
	Function:		validate
	Parameters:		int (AT, IT, or WT)
	Description: 	Checks input of AT/IT/WT to make sure that it is within range or returns 
*/
		int validate(int num)
		{
			if(num < 0 || num > 3)
				return 0;
			else
				return num;
		}		
/*
	Function:		Setters
	Parameters:		The type of value being changed 
	Description:	These allow for the code to change some of the values or update values for the object.
*/
		void setName(string n){name = n;}
		void setIT(int i)
		{
			IT = validate(i);
		}
		void setAT(int a)
		{
			AT = validate(a);
		}
		void setWT(int w)
		{
			WT = validate(w);
		}
		void setLevel(int l){level = l;}
		void setDescription(string d){desc = d;}
		void setAbilityPts(int a){abilityPts = a;}

/*
	Function:		Getters
	Parameters:		NULL
	Description:	These allow for the code to return some of the values for the object.
*/
		string getName() const {return name;}
		int getIT() const{return IT;}
		int getAT() const {return AT;}
		int getWT() const {return WT;}
		int getLevel() const {return level;}
		string getDescription() const {return desc;}
		int getAbilityPts() const {return abilityPts;}
	
	
	
	
};


#endif