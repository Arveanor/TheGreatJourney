

#include "healer.h"

void Healer :: interaction(){
	std::cout << std::string(100, '\n');
	printHeader();
	pause();
}

void Healer :: printHeader(){
	
	cout << '+' << setw(78) << setfill('-') << '+' << endl;
	cout << "|You see a small building with cloth draped      " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|over the entrance. As you enter thick scented   " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|smoke induces a dizzying feeling. You lay down  " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|on the cot provided. A man with a wrinkled face " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|approaches. \"You seem pretty banged up, Let me  " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|take a look.\"                                   " << setw(30) << setfill(' ') << '|' << endl;
	cout << '+' << setw(78) << setfill('-') << '+' << endl;
	
}

void Healer :: pause(){
	cin.ignore();
   cin.ignore();
}





