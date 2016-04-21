#include "Inventory.h"
#include <stdio.h>

void Inventory::viewAll(Atts *temp) {
   int  choice = -1; //just for cin for options
   int  pageNum = 0; // used to differentiate between pressing '1' on page 3 or 8 of your inventory. 
   int  itemNum = 0; // 
   int  i = 1;
   int _i = 0;
   while(choice != 0){
   
      std::cout << std::endl << std::endl << "Character's Inventory\t (Use number keys to see details and equip)\n\n" << "Item Name" << std::endl;
      if(stored.empty()) {
         std::cout << "You look inside your pack for something of use, but alas, your pack is empty." << std::endl;
      }else{
         
         for(it = stored.begin(); it != stored.end() && i <= 5; ++it) {
           while(_i < (pageNum * 5)) {
               if(it != stored.end()) {
						it++;
               	_i++;
            	}
					if(_i % 5 == 0) {
						std::cout << "No gear to show on this page, returning to page " << pageNum - 1 << "." << std::endl;
						pageNum--;
					}
				}
            std::cout << i << ": " << it->first << std::endl;
            i++;
         } 
      }
      std::cout << "\n6: View More \t 0: Return to Aite" << std::endl;
      std::cin >> choice;
      if(choice >= 1 && choice <= 5) {
         itemNum = choice + (5 * pageNum);
         //std::cout << "before stored.begin" << std::endl;
         it = stored.begin();
         //std::cout << "after stored.begin" << itemNum << std::endl;
         //i = _i;
         
         
         while(i < itemNum){
            //std::cout << "in while loop" << std::endl;
            it++;
            i++;
         }

         _tempI = it->second;
         seeDetails(_tempI, temp);
         std::cin.ignore();
         std::cin.ignore();
			std::cout << std::string(100, '\n');
         i = 1;
      }else if(choice == 6){
         pageNum ++; 
      }
   }
}


void Inventory::seeDetails(Item _temp, Atts* plyr) {
   std::string temp;
	std::cout << std::string(100, '\n');
   std::cout  << std::setw(25) << std::setfill('~') << std::left << _tempI.getName() << std::right << _tempI.getValue() <<  std::endl;
   std::cout << "\n1: Equip item\t2: Return to inventory" << std::endl;
   
   std::cin >> temp;
   if(temp == "1") {
      _temp.equipCheck(plyr);
      std::cout << _temp.getName() << " equipped" << std::endl;
   }  
}

void Item::equipCheck(Atts* _temp) {

   if(iType == Helmet && _temp->getEquipped()[0] == 0) {
      _temp->setEquipped(0, 1);
      equip(_temp);
   }
   if(iType == Cuirass && _temp->getEquipped()[1] == 0) {
      _temp->setEquipped(1, 1);
      equip(_temp);      
   }
   if(iType == Shoulder && _temp->getEquipped()[2] == 0) {
      _temp->setEquipped(2, 1);
      equip(_temp);
   }
   if(iType == Gloves && _temp->getEquipped()[3] == 0) {
      _temp->setEquipped(3, 1);
      equip(_temp);
   }
   if(iType == Greaves && _temp->getEquipped()[4] == 0) {
      _temp->setEquipped(4, 1);
      equip(_temp);
   }
   if(iType == Boots && _temp->getEquipped()[5] == 0) {
      _temp->setEquipped(5, 1);
      equip(_temp);
   }
   if(iType == 0) {
      _temp->setEquipped(6, 1);
      equip(_temp);
   }
   /*if(iType == Weapon && _temp->getEquipped()[6] == 0) {
      _temp->setEquipped(6, 1);
      equip(_temp);
   }*/
   if(iType == Ring && _temp->getEquipped()[7] == 0) {
      _temp->setEquipped(7, 1);
      equip(_temp);
   }
   if(iType == Amulet && _temp->getEquipped()[8] == 0) {
      _temp->setEquipped(8, 1);
      equip(_temp);
   } else {
		std::cerr << "sorry, failed to identify item " << iType << std::endl;	
	}
}

std::map<std::string, Item> Inventory::getMap() {
   return stored;
}

void Item::equip(Atts* _temp) {
	_temp->setPwr(_temp->getPwr() + power);
   _temp->setPrc(_temp->getPrc() + precision);
   _temp->setDef(_temp->getDef() + def);
   _temp->setVit(_temp->getVit() + vitality);
   _temp->setArmor(_temp->getArmor() + armor);
   _temp->setDmgRange(0, _temp->getDmgRange()[0] + dmgRange[0]);
	_temp->setDmgRange(1, _temp->getDmgRange()[1] + dmgRange[1]);
   //_temp->dmgRange[1] += dmgRange[1];
   isEquipped = true;
}

void Item::unEquip(std::string _tag, Atts* _temp) {
/*   if (isEquipped == true) {
      _temp->Pwr -= power;
      _temp->Prc -= precision;
      _temp->Vit -= vitality;
      _temp->Def -= def;
      _temp->armor -= armor;
      _temp->dmgRange[0] -= dmgRange[0];
      _temp->dmgRange[1] -= dmgRange[1];
   } */
	fprintf(stderr, "unEquip currently disabled, sorry\n");
}

void Inventory::Obtain(Item _new) { 
   std::string _tag = _new.getName();
   stored[_tag] = _new;  
}

std::string Item::getName() {
   return name;
}

int Item::getValue() {
   return value;
}

void Item::setName(std::string _name) {
   name = _name;
}

void Item::setValue(int val) {
   value = val;
}

void Item::setType(itemType _type) {
   iType = _type;
}

 void Item::setDmg(int low, int high) {
   dmgRange[0] = low; dmgRange[1] = high;
}
void Item::setPower(int _power) {
   power = _power;
}

void Item::setPrecision(int _precision) {
   precision = _precision;
}

void Item::setDef(int _def) {
   def = _def;
}

void Item::setVitality(int _vitality) {
   vitality = _vitality;
}

void Item::setArmor(int _armor) {
   armor = _armor;
}
