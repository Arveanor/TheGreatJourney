//--------------------------------------------------------------------------
//
//
//
//
//
//
//--------------------------------------------------------------------------

#include "sanctuary.h"

Sanctuary :: Sanctuary(){
	
}

Sanctuary :: ~Sanctuary(){

}

void Sanctuary :: interaction(){
	int userChoice = -1;
	
	while(userChoice != 2){
		std::cout << std::string (100, '\n');
		printHeader();
		printMenu();
		std::cin >> userChoice;

		if(userChoice == 1){
			touchStoneEvents.interaction();
		}
	}
}

void Sanctuary :: printMenu(){
	std::cout << "|Touch the stone." << std::endl;
	std::cout << "|Leave the stone." << std::endl;
	std::cout << "|Action: ";
}

void Sanctuary :: printHeader(){
	std::cout << '+' << std::setw(78) << setfill('-') << '+' << std::endl;
	std::cout << "|You come upon a large cathedral. There is no one" << std::setw(30) << std::setfill(' ') << '|' << std::endl;
	std::cout << "|inside, but you are intrigued by a stone column " << std::setw(30) << std::setfill(' ') << '|' << std::endl;
	std::cout << "|with a strange symbol inscribed into the top." << std::setw(33)  << std::setfill(' ') << '|' << std::endl;
	std::cout << '+' << std::setw(78) << std::setfill('-') << '+' << std::endl;
	std::cout <<	"|What do you do?" << std::endl;
}
