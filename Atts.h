#ifndef ATTS_H_INCLUDED
#define ATTS_H_INCLUDED



#endif // ATTS_H_INCLUDED
/*
 * Atts.h
 *
 *  Created on: Nov 7, 2012
 *      Author: peter
 */

#ifndef ATTS_H_
#define ATTS_H_
#include <string>
#include <vector>

class Atts{
	int level;
	int exp;
	std::string Name;
	float Pwr;
	float Prc;
	float Def;
	float Vit;
	
   float baseCrit; // Just useful to have this as a separate stat for buffs/debuffs
   
	int maxHP;
	int currHP;
	
	int Attunement; 
	int Attune_Diff; //Difference between the player's attunement stat and the item's attunement stat.
	int isEquipped[9]; //Helm, Chest, Shoulder, Glove, Pants, Boots, Weapon, Ring, Amulet. 0 = unequipped, 1 = 1 equipped, 2 = 2 equipped.
   int knwnAbts[1]; // Amnesia
	
	int dmgRange[2];
	
   int isStunned; //0 means not stunned, any higher number is the number of turns the character is stunned for.
   int offBalance[2]; // element 0 is duration and element 1 is the num of points of defense missing
   int Ruthless[2]; // element 0 is duration and element 1 is the % chance increase in crit chance
   
   int armor; //derived from gear and "Def" this stat reduces all incoming damage
	int magRes; //Based on armor values, this stat reduces incoming magic damage
	int meleeRes; //Based on armor values, this stat reduces incoming melee damage
	int rangedRes; //Based on armor values, this stat reduces incoming ranged damage
public :
	
	Atts();	
	
	void Create();
	void Upgrade(int iS_pts);
   
   void DoT();
   void powerDown();
   void precisionDown();
   void defenseDown();
   void vitalityDown();
   void powerUp();
   void precisionUp();
   void defenseUp();
   void vitalityUp();
	
	void setLevel(int _level);
	void setExp(int _exp);
	void setName(std::string _name);
	void setPwr(int _pwr);
	void setPrc(int _prc);
	void setVit(int _vit);
	void setDef(int _def);
	void setMaxHp(int _maxhp);
	void setCurrHp(int _currhp);
	void setDmgRange(int _low, int _high);
	void setOffBalance(int _duration, int severity);	
	void setRuthless(int _duration, int severity);
	void setStunned(int _duration);
	void setEquipped(short slot, short B);
	void setArmor(int _armor);


	std::string getName();
	int getLevel();
	int getExp();
	int getPwr();
	int getPrc();
	int getVit();
	int getDef();
	int getArmor();
	int getMaxHp();
	int getCurrHp();
	int *getDmgRange();
	int *getOffBalance();
	float getBaseCrit();
	int *getRuthless();
	int getStunned();
	int *getEquipped();

};

#endif /* ATTS_H_ */
