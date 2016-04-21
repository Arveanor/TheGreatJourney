//#include "list.h"
#include <time.h>
#include <iomanip>
#include "Ability.h"


class Cmbt {
   //List *Enemies; // Will be implemented with parser/xml tags
   Atts Enemies[2]; // Will be replaced by List *Enemies;
   Ability* allAbilities;
   
   Atts *Player;
public:
   Cmbt() 
   { 
      srand((unsigned)time(NULL));
      
   };
   void loadEnemies();
   void loadPlayer(Atts *plyr);
   Atts *Enemy();
   float critChance(float atkPrc, float defrPrc); 
   void CmbtLoop();
   void Effects(Atts *p1, Atts *p2);
   void npcTurn(Atts *enmyAtts); // Will decide npc course of action.
   void pcTurn(Atts *enmyAtts); // Player's decision input.
   int Attack(float atkPwr, int defrDef, float atkPrc, float defrPrc, int dmgRange[2]); //Returns the damage dealt in a round.
};