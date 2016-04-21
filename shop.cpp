

#include "shop.h"

Shop :: Shop(){
	money = 1000;
}

void Shop :: interaction(){
	char userChoice;
	
	while(userChoice != '3'){
		std::cout << std::string(100, '\n');
		printHeader();
		printMenu();
      cin.ignore();
		cin >> userChoice;
		
		if(userChoice == '1'){
			buy();
		}else if(userChoice == '2'){
			if(money > 0){
				sell();
			}else{
				cout << "\" I'm sry i can't do that\"" << endl;
				cin.ignore();
			}
		}
	}
}

void Shop :: printHeader(){
	
	cout << '+' << setw(78) << setfill('-') << '+' << endl;
	cout << "|As you walk down the small avenue that runs     " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|through the center of town, you notice a small  " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|vendor's cart. You approach the cart looking at " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|the delicious fruits that line the it. \"May I   " << setw(30) << setfill(' ') << '|' << endl;
	cout << "|help you ? \" the timid voice of a woman asks.   " << setw(30) << setfill(' ') << '|' << endl;
	cout << '+' << setw(78) << setfill('-') << '+' << endl;
	
}

void Shop :: printMenu(){
	
	cout << "|How do you responde ?" << setw(20) << money << right << " :Shop" << endl;
	cout << "|1: What have you got for sale ?" << endl;
	cout << "|2: I would like to sell somethings." << endl;
	cout << "|3: Leave" << endl;
	cout << "|Responde:  ";

}

void Shop :: buy(){
	money += 100;
	cout << "+----------+" << endl;
	cout << "|  Buying  |" << endl;
	cout << "+----------+" << endl;
	cin.ignore();
}

void Shop :: sell(){
	money -= 100;
	cout << "+-----------+" << endl;
	cout << "|  Selling  |" << endl;
	cout << "+-----------+" << endl;
	cin.ignore();
}








