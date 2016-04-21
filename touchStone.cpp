//--------------------------------------------------------------------------
//
// Author: Andrew Lindstrom, Peter Keyser
// Project: Great Journey 
// File: touchStone.cpp
// Date: 4/19/2013
//
//--------------------------------------------------------------------------

#include "touchStone.h"

void TouchStone :: interaction(){
	
	char userChoice;
	while(userChoice != '5'){
		std::cout << std::string(100, '\n');
		printHeader();
		printMenu();
		cin >> userChoice;
		
		if(userChoice == '1'){
			smithEvent.interaction();
		}else if(userChoice == '2'){
			shopEvent.interaction();
		}else if(userChoice == '3'){
			healerEvent.interaction();
		}else if(userChoice == '4'){
		}
	}
}

void TouchStone :: printHeader(){
	
	cout << '+' << setw(78) << setfill('-') << '+' << endl;
	cout << "|Your armor melts off of your body as the world  " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|around you goes white. Suddenly a falling       " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|sensation rushes through you, and you land on   " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|the cathedral floor. Only, this time its        " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|different. You exit the cathedral and find      " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|yourself in a small village.                    " << setw(30) << setfill(' ') << '|' << endl;
	cout << '+' << setw(78) << setfill('-') << '+' << endl;

}

void TouchStone :: printMenu(){
	
	cout << "|What do you do ?" << endl;
	cout << "|Go to the smith." << endl;
	cout << "|Go to the shop." << endl;
	cout << "|Go to the healer." << endl;
	cout << "|Explore." << endl;
	cout << "|Go back to the Cathedral." << endl;
	cout << "|Action: ";
	
}








