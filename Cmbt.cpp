		  #include <iostream>
		  #include <math.h>
		  #include <cstdlib>

		  #include "Cmbt.h"

		  /*
		  ** Combat Loop should really just handle sending turns back and forth from PC to NPC, and ending battles when someone dies
		  ** Combat Loop should be called by a story function, and should lose its loop about whether to fight or train, as this will be 
		  ** handled in story.cpp(name?)
		  ** All of the vital statistics of the various NPC opponents should also be removed to Atts.cpp, or perhaps some other file.
		  */ 

		  /*
		  ** Going to need a total overhaul of loadEnemies to utilize the parser/list
		  */
		  void Cmbt::loadEnemies() {
			  Atts RdrAtts;
			  Atts HLndrAtts;

			  
			  HLndrAtts.setPwr(7);
			  HLndrAtts.setPrc(7);
			  HLndrAtts.setDef(9);
			  HLndrAtts.setVit(7);
			  HLndrAtts.setMaxHp(HLndrAtts.getVit() * 5);
			  HLndrAtts.setCurrHp(HLndrAtts.getMaxHp());
			  HLndrAtts.setName("Highlander");
			  HLndrAtts.setDmgRange(3, 7);
           HLndrAtts.setOffBalance(0, 3);

			  RdrAtts.setPwr(6);
			  RdrAtts.setPrc(11);
			  RdrAtts.setDef(6);
			  RdrAtts.setVit(6);
			  RdrAtts.setMaxHp(RdrAtts.getVit() * 5);
			  RdrAtts.setCurrHp(RdrAtts.getMaxHp());
			  RdrAtts.setName("Raider");  
           RdrAtts.setDmgRange(2, 9);
           HLndrAtts.setOffBalance(0, 3);
			  
			  Enemies[0] = HLndrAtts;
			  Enemies[1] = RdrAtts;
			  
		  }

		  void Cmbt::loadPlayer(Atts *plyr) {
			  Player = plyr;
		  }


		  Atts* Cmbt::Enemy() {
			  int type = 0;
			  type = rand() % 2;
			  return &Enemies[type];
		  }

void Cmbt::Effects(Atts *p1, Atts *p2) {
//not actually a loop. poorly named... w/e
// just keep adding if statements... it is really that simple.  Oh and Atts *p2 is probably pointless. oops.
	if(p1->getOffBalance()[0] >= 0) {
		if(p1->getOffBalance()[0] == 1) {
			  p1->setDef(p1->getDef() + p1->getOffBalance()[1]); // returns defense stat to its base
		}
		std::cout << p1->getName() << " is off balance for " << p1->getOffBalance()[0] << " turns" << std::endl;
		p1->setOffBalance(p1->getOffBalance()[0] - 1, p1->getOffBalance()[1]);
   }
   if(p1->getRuthless()[0] >= 0) {
      if(p1->getOffBalance()[0] == 1) {
         p1->setRuthless(p1->getBaseCrit() - p1->getRuthless()[1], p1->getRuthless()[1]);
      }
      p1->setRuthless(p1->getRuthless()[1] - 1, p1->getRuthless()[1]); 
   }
}

void Cmbt::CmbtLoop() { 
	std::cout << std::string(100, '\n');
   int i = 1;
   loadEnemies();
   allAbilities = new Ability;
   Atts *enmyAtts = Enemy();
   
	std::cout << std::string(100, '\n');
   
	int first = 0;
   first = (rand() % 2) + 1; // 1 = player first.  2 = npc first.
   //std::cout << "Before while loop" << std::endl;
   //std::cout << "First = " << first << std::endl;
   while(Player->getCurrHp() > 0 && enmyAtts->getCurrHp() > 0) {
      std::cout << "Battle Turn " << i << "\n" << std::endl;
      i++;
      
      std::cout << Player->getName() << "'s health: " << Player->getCurrHp() << " / " << Player->getMaxHp();
      std::cout << "\t" << enmyAtts->getName() << "'s health: " << enmyAtts->getCurrHp() << " / " << enmyAtts->getMaxHp() << std::endl;
      
      Effects(Player, enmyAtts); // checks all buffs / debuffs and does related tasks
      Effects(enmyAtts, Player);
      
      if(first == 1) {
         std::cout << "\n1: Attack" << "\n2: Amnesia" << "\n3: Feint" << std::endl;
         pcTurn(enmyAtts);
         first = 2;
      }
      else if(first == 2) {
         npcTurn(enmyAtts);
         first = 1;
      }
   }
}


/* 
** Combat Options will be called by Combat loop, and will contain the player's UI for making decision's in battle and receiving
** vital feedback.  
** I think it looks mostly good right now in terms of functionality, but the UI needs cleaned up a ton.
*/


void Cmbt::pcTurn(Atts *EnmyAtts) {

   if(Player->getStunned() > 0) {
      std::cout << "Player is stunned for " << Player->getStunned() << " more turns, and cannot make any actions until the stun duration has ended." << std::endl;
      Player->setStunned(Player->getStunned() - 1);
      return;
   }

	float randDmg = ((rand()%25)+1)*.01;

	int optNum = 0;
   
	/*std::cout << "Player health = " << Player->currHP << "/" << Player->maxHP << "\t" << EnmyAtts->getName()
			<< "'s health = " << EnmyAtts->currHP << "/" << EnmyAtts->maxHP << "\n"
			<< "Your enemy is upon you, what will you do?" << std::endl;

		std::cout << "1: Attack \n" << "2: Amnesia\n" << "3: Feint" << std::endl;
   */
		std::cin >> optNum;
		if(optNum == 1) {
			EnmyAtts->setCurrHp(EnmyAtts->getCurrHp() - Attack(Player->getPwr(), EnmyAtts->getDef(), Player->getBaseCrit(), EnmyAtts->getPrc(), Player->getDmgRange()));
	   } else if (optNum == 2) {
         allAbilities->Amnesia(Player);
      } else if (optNum == 3) {
         allAbilities->feint(Player, EnmyAtts);
      }

	//std::cout << EnmyAtts->getName() << "'s health = " << EnmyAtts->currHP << "/" << EnmyAtts->maxHP << "\n\n";
         
   //system("cls");
//	if(EnmyAtts->currHP > 0) {
//		std::cout << "Opponent's turn! \n";
//		Player->currHP = npcTurn(EnmyAtts);
//	}

}


/*
** NPC turn is basically the npc version of Combat Options.  It obviously contains no UI, but will allow the computer to determine
** what to do at each stage of a fight, and call the appropriate attack and ability functions.
*/

void Cmbt::npcTurn(Atts* EnmyAtts) {

/*
** just get me a fucking UI in this place.
** something weird is happening in the combat loop but i'll need some more info off of this function
** before I feel like troubleshooting it.
*/

	srand((unsigned)time(NULL));
	float randDmg = ((rand()%25)+1)*.01;

	Player->setCurrHp(Player->getCurrHp() - Attack(EnmyAtts->getPwr(), Player->getDef(), EnmyAtts->getBaseCrit(), Player->getPrc(), EnmyAtts->getDmgRange()));

	std::cout << "\nPlayer health = " << Player->getCurrHp() << "/" << Player->getMaxHp() << std::endl;
}


/*
** Please sir, rewrite this whole stupid function.
**		No idea if this still applies as of 3-9-15. will look into it.
*/

float Cmbt::critChance(float atkCrit, float defrPrc) {

   float chance = (atkCrit / (1 + .5 * defrPrc));
   std::cout << "crit chance = " << chance << "%" << std::endl;
   
   int roll = (rand()%100) + 1;
   
	if(roll < chance) {
		return (1.5);
	}
	else {
		return 1;
	}
   
}


/*
** Attack goes both ways.  It's just a basic formula for determining the affects of an attack. May or may not handle some other abilities as well.
** (This will depend on if abilities similar to basic attacks are incorporated).
*/

int Cmbt::Attack(float atkPwr, int defrDef, float atkCrit, float defrPrc, int dmgRange[2]) {
   //std::cout << "dmgRange --> " << dmgRange[0] << "-" << dmgRange[1] << std::endl;
	float CritMult = 1;
   int rngDiff = dmgRange[1] - dmgRange[0];
   float baseDmg = (rand()%(rngDiff + 1) + dmgRange[0]);
   //std::cout << "Base Damage --> " << baseDmg << std::endl;
	CritMult = critChance(atkCrit, defrPrc);
	if(CritMult > 1){
		std::cout << "\nCritical Hit!\n";
	}

return ((.8*atkPwr+(baseDmg))*CritMult - defrDef);

}
