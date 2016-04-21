

#include "smith.h"

Smith :: Smith(){
	money = 1000;
}

void Smith :: interaction(){
	char userChoice;
	
	while(userChoice != '3'){
		std::cout << std::string (100, '\n');
		printHeader();
		printMenu();
		cin >> userChoice;
		
		if(userChoice == '1'){
			buy();
		}else if(userChoice == '2'){
			if(money > 0){
				sell();
			}else{
				cout << "\" Sorry lad i can't do that\"" << endl;
				cin.ignore();
			}
		}
	}
}

void Smith :: printHeader(){
	
	cout << '+' << setw(78) << setfill('-') << '+' << endl;
	cout << "|You see a small shop with smoke billowing from a" << setw(30) << setfill(' ') << '|' << endl;
	cout << "|chimney on the back. When you open the door you " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|are greeted by the sound of a hammer on hot     " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|steal. \"How can i help you ?\" asks a short      " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|stalky man with a gruff voice.                  " << setw(30) << setfill(' ') << '|' << endl;
	cout << '+' << setw(78) << setfill('-') << '+' << endl;
	
}

void Smith :: printMenu(){
	
	cout << "|How do you responde ?" << setw(20) << money << right << " :Smith" << endl;
	cout << "|1: What have you got for sale ?" << endl;
	cout << "|2: I would like to sell somethings." << endl;
	cout << "|3: Leave" << endl;
	cout << "|Responde:  ";

}

void Smith :: buy(){
	money += 100;
	cout << "+----------+" << endl;
	cout << "|  Buying  |" << endl;
	cout << "+----------+" << endl;
	cin.ignore();
}

void Smith :: sell(){
	money -= 100;
	cout << "+-----------+" << endl;
	cout << "|  Selling  |" << endl;
	cout << "+-----------+" << endl;
	cin.ignore();
}








