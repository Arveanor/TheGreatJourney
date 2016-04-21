#ifndef _H_SHOP_
#define _H_SHOP_

#include <iostream> 
#include <iomanip>
#include <cstdlib>

using namespace std;

class Shop{
	private:
		//Tree* shopInventory;
		int money;
	public:
		Shop();
		// Accessor(s)
		//void getItem();
		//void getMoney();
		
		// Mutator(s)
		//void setItem();
		//void setMoney();
		
		// Utility(s)
		void printMenu();
		void printHeader();
		//void showInventory();
		void interaction();
		void buy();
		void sell();
		
};

#endif