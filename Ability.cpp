#include "Ability.h"


void Ability::heal(Atts *caster) {
   caster->currHP += magnitude;
   if(caster->currHP > caster->maxHP) {
      caster->currHP = caster->maxHP;
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
   caster->isStunned = turns;
}

void Ability::Amnesia(Atts* caster) {
   srand((unsigned)time(NULL));
   int turns = rand()%2 + 1;
   magnitude = caster->Vit * 3;
   heal(caster);
   stun(caster, turns);
}

void Ability::feint(Atts* caster, Atts* target) {
   /* TODO
   ** ADD SCALING TO DURATION AND INTENSITY
   */
   
   target->offBalance[0] = 2; // duration
   target->offBalance[1] = 3; // intensity 
   target->Def -= 3;
}

void Ability::Ruthless(Atts* caster) {

   caster->Ruthless[0] = 2;
   caster->Ruthless[1] = 1 * caster->baseCrit;
   caster->baseCrit += caster->Ruthless[1];


}