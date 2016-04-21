#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
#include <map>

#include "Atts.h"

enum itemType {Weapon, Helmet, Shoulder, Greaves, Ring, Amulet, Boots, Gloves, Cuirass};

class Item {
   std::string name;
   int value;
   bool isEquipped;
   
   int precision;
   int power;
   int dmgRange[2];
   
   int def;
   int vitality;
   int armor;
   
   itemType iType;

public:

   void equipCheck(Atts* _temp); // Makes sure the item can be equipped, then calls equip to make it happen
   void equip(Atts* _temp);
   void unEquip(std::string _tag, Atts* _temp);

   void setName(std::string _name);
   void setValue(int val);
   void setType(itemType _type);
   void setDmg(int low, int high);
   void setPower(int _power);
   void setPrecision(int _precision);
   void setDef(int _def);
   void setVitality(int _vitality);
   void setArmor(int _armor);
   
   int getValue();
   std::string getName();
};


class Inventory {
   std::map <std::string, Item> stored;  // Equipped items will still be in this map but will be in some way designated as equipped.
   std::map<std::string, Item>::iterator it;
   Item _tempI;  
public:

   Inventory() {
   }
   std::map<std::string, Item> getMap();
   void viewAll(Atts *temp);
   void seeDetails(Item _temp, Atts *plyr);
   void Obtain(Item _new);
};
