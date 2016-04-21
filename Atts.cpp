#include <iostream>
#include <string>
#include <cstdlib>
#include "Atts.h"
#include "Utils.h"
//#include "arm.h"

Atts::Atts() {
	Name = "";
}

void Atts::Create() {
	std::string strNum;

   offBalance[0] = 0;
   offBalance[1] = 3;
   isStunned = 0;

   dmgRange[0] = 2;
   dmgRange[1] = 4;
	Pwr = 5;
	Prc = 5;
	Def = 5;
	Vit = 5;
	maxHP = Vit * 5;
	currHP = maxHP;
   
   baseCrit = (15 + (.8 * Prc));
   
   int i = 0;
   for(i = 0; i < 9; i++) {
      isEquipped[i] = 0;
   }      
	std::cout << std::string(100, '\n');
	std::cout << "Welcome to Aite! \nThe tyrant, Lord Scyoklis, has ruled over us for too long now, will you help us defeat him?" << std::endl;
   std::cout << "1: I'll gladly help defeat Scyoklis. \n2: I suppose I can lend a hand.\n" << std::endl;
   getline(std::cin, strNum);
	i = StoN(strNum);
   if(i == 1) {
      std::cout << "Glad to hear it, stranger, now what's your name, anyway?" << std::endl;
		getline(std::cin, Name);
      //std::cin >> Name;
	}
   else if(i == 2) {
      std::cout << "Well we've certainly had more... enthusiastic recruits, but we won't turn you\ndown.  So you got a name, stranger?" << std::endl;
	   getline(std::cin, Name);
   }
	std::cout <<"\nOk, " << Name << " we've got ten hours to train with you before we need to send you\nout, what shall we work on first?"
			<<std::endl;
         
	this->Upgrade(10);
}

void Atts::Upgrade(int iS_pts) {
	std::string strNum;
	int opNum;

	while(iS_pts > 0){
		std::cout << "\n\nYou have " << iS_pts << " hours left to train \n1: Power \n2: Precision \n3: Defense \n4: Vitality \n5: View Current stats" << std::endl;
		getline(std::cin, strNum);
		opNum = StoN(strNum);

		if(opNum == 1) {
			Pwr ++;
		}
		else if(opNum == 2) {
			Prc ++;
         baseCrit = (15 + ( .8 * Prc));
		}
		else if(opNum == 3) {
			Def ++;
		}
		else if(opNum == 4) {
			Vit ++;
			maxHP += 5;
			currHP += 5;
		}
		else if(opNum == 5) {
			std::cout << "Power = " << Pwr << "\nPrecision = " << Prc
					<< "\nDefense = " << Def << "\nVitality = " << Vit;
			iS_pts ++;
		}
		iS_pts --;
	}
}

// Status Effects; Buffs and Debuffs

void Atts::DoT() {
   
}
void Atts::powerDown() {
   
}
void Atts::precisionDown() {
   
}
void Atts::defenseDown() {
   
}
void Atts::vitalityDown() {
   
}
void Atts::powerUp() {
  
}
void Atts::precisionUp() {
   
}
void Atts::defenseUp() {
   
}
void Atts::vitalityUp() {
   
}
void Atts::setStunned(int _dur) {
	isStunned = _dur;
}
void Atts::setPwr(int _pwr) {
	Pwr = _pwr;
}
void Atts::setPrc(int _prc) {
	Prc = _prc;
}
void Atts::setDef(int _def) {
	Def = _def;
}
void Atts::setVit(int _vit) {
	Vit = _vit;
}
void Atts::setArmor(int _armor) {
	armor = _armor;
}
void Atts::setMaxHp(int _max) {
	maxHP = _max;
}
void Atts::setCurrHp(int _cur) {
	currHP = _cur;
}
void Atts::setLevel(int _level) {
	level = _level;
}
void Atts::setExp(int _exp) {
	exp = _exp;
}
void Atts::setOffBalance(int dur, int sev) {
	offBalance[0] = dur;
	offBalance[1] = sev;
}
void Atts::setDmgRange(int low, int high) {
	dmgRange[0] = low; 
	dmgRange[1] = high;
}
void Atts::setRuthless(int dur, int sev) {
	Ruthless[0] = dur;
	Ruthless[1] = sev;
}
void Atts::setEquipped(short slot, short num) {
	isEquipped[slot] = num;
}
void Atts::setName(std::string _name) {
	Name = _name;
}
std::string Atts::getName() {
	return Name;
}
int Atts::getPwr() {
	return Pwr;
}
int Atts::getPrc() {
	return Prc;
}
int Atts::getDef() {
	return Def;
}
int Atts::getVit() {
	return Vit;
}
int Atts::getExp() {
	return exp;
}
int Atts::getLevel() {
	return level;
}
int Atts::getMaxHp() {
	return maxHP;
}
int Atts::getCurrHp() {
	return currHP;
}
float Atts::getBaseCrit() {
	return baseCrit;
}
int Atts::getArmor() {
	return armor;
}
int Atts::getStunned() {
	return isStunned;
}
int *Atts::getOffBalance() {
	return offBalance;
}
int *Atts::getDmgRange() {
	return dmgRange;
}
int *Atts::getRuthless() {
	return Ruthless;
}
int *Atts::getEquipped() {
	return isEquipped;
}
