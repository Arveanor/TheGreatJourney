#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Atts.h"

// just continue making lots of functions in here.  Will probably give characters an array of status effects so combat loop knows what to do.

class Ability {

float magnitude;

public:
   void heal(Atts *caster);
   void damage();
   void DoT(int turns);
   void power();
   void precision();
   void vitality();
   void defense();
   void stun(Atts *caster, int turns);
   void Amnesia(Atts *caster);
   void feint(Atts *caster, Atts *target); // Baits the target off balance, making them more susceptible to future attacks
   void Ruthless(Atts *caster); // A ruthless killing machine, the caster is prepared to go for a killing blow. Increases crit chance.
};