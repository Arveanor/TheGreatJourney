//--------------------------------------------------------------------------
//
// Author: Andrew Lindstrom, Peter Keyser
// Project: Great Journey 
// File: Sanctuary.h
// Date: 4/19/2013
//
//--------------------------------------------------------------------------

#ifndef _H_SANCTUARY_
#define _H_SANCTUARY_

#include "touchStone.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

class Sanctuary{
    private:
		TouchStone touchStoneEvents;

    public:
		Sanctuary();
		~Sanctuary();

		// Utilitiy(s)
		void printMenu();
		void printHeader();
		void interaction();
};
#endif

