/*
    Test Code for Abilities Class
	- Creation (1)
	- PRINT (1)
	- printToFile (1)
	- setters (3)
	- getters (3)
	
	Test Code for Roles Class
	- Creation (2)
	- Deletion (1)
	- PRINT (1)
	- addPower (2)
	- removePower (2)
	- printPowers (1)
	- printToFile (1)
	- Resize (1) ?
	- setters (2)
	- getters (5)
	
    Total: 27 Test
*/

#include "../../Functions.h"

int main()
{
	LinkedList<Roles*>* Classes  = new LinkedList<Roles*>();
	LinkedList<Abilities*>* Powers  = new LinkedList<Abilities*>();
	
	int numAbilities = 0;
	Abilities** pows;
	Abilities* ability = new Abilities("Stab", 1, 52);
    Abilities staticAbility("FireBlast", 0, 78);
    
    staticAbility.PRINT();
	ability->PRINT();
	
    ofstream kfile;
    kfile.open("Fireblast.txt");
    ability->printToFile(kfile);
    kfile.close();

	Powers->appendNode(ability);
	

    for(int i = 1; i <= Powers->getLength();i++)
        Powers->getNodeValue(i)->PRINT();

	
	Roles* Mage = new Roles("Mage", 1, 2);
	Roles* Warrior = new Roles("Warrior", 2, 1);
	Roles* Thief = new Roles();
	
	Mage->addPower(Powers->getNodeValue(1));
	Mage->addPower();
    Mage->addPower();

    Warrior->addPower();

    Thief->setRoleName("Thief");
    Thief->setArmorType(0);
    Thief->addPower(ability);

    Warrior->PRINT();

    Mage->PRINT();
    Mage->removePower();

    cout << Thief->getRoleName() << endl;
    cout << Thief->getArmorTypeName() << " " << Thief->getArmorType() << endl;
    cout << Thief->getNumPowers() << " Powers" << endl;

    /* Isssue with LinkedList and print Thief, 
    pows = Mage->getPowers();
    for(int i = 0; i < Mage->getNumPowers(); i++)
        Powers->appendNode(pows[i]);

    pows = Warrior->getPowers();
    for(int i = 0; i < Warrior->getNumPowers(); i++)
        Powers->appendNode(pows[i]);

    pows = Thief->getPowers();
    for(int i = 0; i < Thief->getNumPowers(); i++)
        Powers->appendNode(pows[i]);

    Classes->appendNode(Mage);
    Classes->appendNode(Warrior);
    Classes->appendNode(Thief);
    
    for(int i = 1; i <= Classes->getLength(); i++)
        Classes->getNodeValue(i)->PRINT();
	*/
    const char* PowerFile = "../_TestFiles/PowersTest.txt";
    const char* RolesFile = "../_TestFiles/RolesTest.txt";

    ofstream file;
    file.open(RolesFile);
    Mage->printToFile(file);
    Warrior->printToFile(file);
    file.close();

    //Test issue with printing ability out to file
    ofstream nfile;
    nfile.open("Ability.txt");
    ability->printToFile(file);
    nfile.close();
/*  
    file.open(PowerFile);
    for(int i = 1; i <= Powers->getLength(); i++)
    {
        Powers->getNodeValue(i)->printToFile(file);
        file << endl;
    }
    file.close();

    file.open(RolesFile);
    for(int i = 1; i <= Classes->getLength(); i++)
    {
        Classes->getNodeValue(i)->printToFile(file);
        file << endl;
    }
    file.close(); 
*/
    
	delete ability;
	delete Mage;
	delete Warrior;
	delete Thief;
	delete Classes;
	delete Powers;

    cout << "Done" << endl;
    return 0;	
}