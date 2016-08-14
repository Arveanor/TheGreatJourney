#include "Ability.h"


void Ability::heal(Atts *caster) {
   caster->setCurrHp(caster->getCurrHp() + magnitude);
   if(caster->getCurrHp() > caster->getMaxHp()) {
      caster->setCurrHp(caster->getMaxHp());
   }
}

void Ability::damage() {
   
}

void Ability::DoT(int turns) {
   
}

void Ability::power() {
   
}

void Ability::precision() {
   
}

void Ability::vitality() {
   
}

void Ability::defense() {
   
}

void Ability::stun(Atts *caster, int turns) {
   caster->setStunned(turns);
}

void Ability::Amnesia(Atts* caster) {
   srand((unsigned)time(NULL));
   int turns = rand()%2 + 1;
   magnitude = caster->getVit() * 3;
   heal(caster);
   stun(caster, turns);
}

void Ability::feint(Atts* caster, Atts* target) {
   /* TODO
   ** ADD SCALING TO DURATION AND INTENSITY
   */
   
   target->setOffBalance(2, 3); // duration
   target->setDef(target->getDef() - 3);
}

void Ability::Ruthless(Atts* caster) {

   caster->setRuthless(2, 1); //[0] = 2;
   //caster->Ruthless[1] = 1 * caster->baseCrit;
   //caster->baseCrit += caster->Ruthless[1];
}
