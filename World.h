/*
** encounters is used to hold the types of encounters as well as the likelihood that they are chosen.
** the first element in each array are all sequential integers, used simply as a sort of 'code' to identify what type of encounter it goes too.
**   1 = Combat
**   2 = Sanctuary
**   3 = Shop
**   4 = Smith
**   5 = Healer
**   6 = Sundered
**   7 = Memory
**   8 = Old ruins
**
** the second element in each array is the weighting on the chance this encounter will be chosen.  The weighting is increased every time this encounter is
** *not* chosen so as to make sure everything gets chosen fairly evenly.  
**
** the third element in each array is the actual temporary value of an encounter for getting picked.  This is after the weighting from above is factored in, 
** and it is the third elements that will be directly compared to decide what encounters will be available.
**
*/
#include "Atts.h"
#include "loader.h"
#include <new>

class World {
Atts *pChar;
std::vector<Atts> Enemies;
Loader *ldr;
public:
   World() {
      pChar = new Atts();
      pChar->Create();
		ldr = new Loader();
		ldr->loadEnemies(Enemies);
   }
   ~World() {
      delete pChar;
   }
   float Weight;  // this is probably a derpy old piece of legacy code... we'll see.
   int encounters[8][2];  
   int choices[3]; // choices are the 3 top options drawn from 'encounters' for the player to pick from
   
   
   //list_t * enctrs;
   void EncounterType();
   void runEncounter();
   Atts *getChar();
};

/* So there was a time when most of halo combat evolved's ai was a bunch of comments with plans in them.  In the spirit of Bungie's excellence
** (and because thinking while sick is more difficults) I am going to do something similar right now.
** 
** So encounter type is going to be responsible for giving a single, or perhaps all three, possible outcomes of any given step in the player's journey
** Going along with this will be a list of all of the possible encounters.  
** 
** I cant think well enough to say for sure, but either EncounterType or some other function will iterate through the list and find the encounters to 
** be given.... Yeah I think that should just be Encounter Type.
** 
** Now that *that* is out of the way, to use this mess, a for loop should be run (for i = 0; i < 3; i++).  Inside the loop will be a giant (yes, its large)
** call to EncounterType which, as should be apparent, will be called three times, and stored in an array[3].  Then each one of these will be presented to 
** the player through a yet un-created UI as three (unique) encounter options.  UI interactions will then be used to choose an opttion, and the necessary 
** functions (i.e. combat, sanctuary) will be called upon to serve.
*/
