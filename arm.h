#ifndef ARM_H_INCLUDED
#define ARM_H_INCLUDED



#endif // ARM_H_INCLUDED
#include <iostream>

using namespace std;
class Item{

string getName();

public:
    string itemName[20];
    int sellFor;
    //virtual void getItem(Item *); //I really don't think this function is necessary
};

class Arm : public Item {
public:
	int id; //gives the identification of the item type **probably unnecessary
	int strength; // effect of the item based on its type
	int spec_id;  // special effect id
	int spec_str; // strength of the spec_eff based on the id.

	//virtual void equipArm() = 0;  //used to update player stats based on equpment
    //void getItem(Item *myItem); //used to retrieve information about equipped items.
};

class Weapon : public Arm {
public:
    int lowDmg; //lowest damage of a weapon. if damage is 10-15, lowDmg would be 10.
    int highDmg; //highest damage of a weapon. if damage is 10-15, highDmg would be 15.
    float critRange; // % chance of a critical hit with this weapon. % chance of a crit is also based on a characters precision
};

class Blade : public Weapon {
public:
    float sharp; //How sharp the blade is. probably useless.
	int speed; //In situations where to blade types meet.  Speed could be used to spice things up... somehow.

};

class Armor : public Arm {
public:
    int defense;
    int magicResist;
	int meleeResist;
	int rangedResist;

}

class Helm : public Armor {
public:
    float Impairment; //Helmets reduce the 5 senses, so "Impairment" will have some detrimental effect on combat.

}

class Cuirass : public Armor {
public:

    int Attunement; //Attunement relates to the characters Attunement, to increase damage output, if it is close to char's attunement.    

}