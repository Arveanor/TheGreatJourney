//--------------------------------------------------------------------------
//
// Author: Andrew Lindstrom, Peter Keyser
// Project: Great Journey 
// File: touchStone.h
// Date: 4/19/2013
//
//--------------------------------------------------------------------------

#ifndef _H_TOUCHSTONE_
#define _H_TOUCHSTONE_

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "smith.h"
#include "shop.h"
#include "healer.h"
//#include "memory.h"

using namespace std;

class TouchStone{
	private:
		Smith smithEvent;
		Shop shopEvent;
		Healer healerEvent;
		//Memory memoryEvent;
	public:
		
		// Utility(s)
		void interaction();
		void printHeader();
		void printMenu();
};


#endif









