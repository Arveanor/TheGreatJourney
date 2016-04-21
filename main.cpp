#include <cstdlib>
#include <iostream>

#include "Ability.h"
#include "Inventory.h"
#include "World.h"


int main() {
   int i = 0;
   int choice;
   
   Item* genBlade = new Item;
   genBlade->setName("General's steel blade");
   genBlade->setValue(650);
   genBlade->setPower(2);
   genBlade->setPrecision(1);
   genBlade->setDef(0);
   genBlade->setVitality(0);
   genBlade->setType(Weapon);
   genBlade->setArmor(0);
   genBlade->setDmg(1, 3);
   
   
   World *mainWorld = new World();
   std::cout << "Weapon slot equipped value: " << mainWorld->getChar()->isEquipped[6] << std::endl;
   Inventory *charInv = new Inventory();
   
   std::cout << "My Lord, one of our master smiths took it upon himself to make this blade for you, to lead the armies into battle."
             << "Perhaps you should take a look at it before you march to war?\n" << std::endl;
   charInv->Obtain(*genBlade);

   while(i == 0) {
   std::cout << "1: Manage equipment     The clothes make the man.\n"
             << "2: March forth          All great men must act.\n"
             << "3: Retire               We always knew it wouldn't last." << std::endl;
   std::cin >> choice;
      if( choice == 1 ) {
         charInv->viewAll(mainWorld->getChar());
      }
      else if( choice == 2) {
         mainWorld->EncounterType();
         mainWorld->runEncounter();
      }
      else if( choice == 3) {
         i = 1;
      }
   }
   
   delete charInv;
   delete mainWorld;
return 0;
}