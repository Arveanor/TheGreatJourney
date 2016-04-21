#include <cstdlib>
#include <iostream>
#include <time.h>

#include "World.h"
#include "Cmbt.h"
#include "sanctuary.h"


void World::EncounterType() {
   srand(time(NULL));
   
   int i;
   int chance;        // Chance for an encounter to be picked, the higher the number, the better.
   int highest[3];    // The 3 highest rolls.  Used to check each roll to make sure it is one of the top 3.
   
   for(i = 0; i < 1; i++) {
      chance = ((rand()%100) + 1) * encounters[i][1];
      encounters[i][2] = chance;
   }
   
   for(i = 0; i < 1; i++) {                      //this for loop populates highest[3] with the 3 highest (weighted) rolls on event types
      if (encounters[i][2] > highest[0]) {
         choices[0] = encounters[i][0];
         highest[0] = encounters[i][2];
      } else if (encounters[i][2] > highest[1]) {
         choices[1] = encounters[i][0];
         highest[0] = encounters[i][2];
      } else if (encounters[i][2] > highest[2]) {
         choices[2] = encounters[i][0];
         highest[2] = encounters[i][2];
      }
   }  
}

void World::runEncounter() {

   int in_num; // the input number from the user to determine which choice is used
   
   
	std::cout << std::string(100, '\n');
   std::cout << "As you make your way across the shadowy plains, you come upon a crossroads, and you know that a great choice lies before you." << std::endl;
   if(choices[0] == 0) {
      std::cout << "\nThe road to the north leads into a war-ravaged valley, where few souls dare to wander.  If you follow this path, \n"
                << "you should be prepared for a fight" << std::endl;
      std::cout << "\nYou see a small path leading off the mainroad, heading into the nearby highlands.  Wherever it leads, something about it "
                << "gives you a very deep sense of calm" << std::endl;
                
   }
   
   std::cout << "What choice will you make? What path will you follow?\n"
             << "1: I will follow the road north, that I might help relieve this land of the darkness that has befallen it.\n"
             << "2: I've been in this wartorn land too long, and need the rest those highlands might offer." << std::endl;
   std::cin >> in_num;
   if(in_num == 1) {
      Cmbt *combat = new Cmbt;
      combat->loadPlayer(pChar);
      combat->CmbtLoop();
   }
   if(in_num == 2) {
      //obviously... you know what goes here, don't make me spell it out.  
   Sanctuary* sanctuaryTest;
	sanctuaryTest -> interaction();   
   }
}

Atts* World::getChar() {
   return pChar;
}
