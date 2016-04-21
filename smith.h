#ifndef _H_SMITH_
#define _H_SMITH_

#include <iostream> 
#include <iomanip>
#include <cstdlib>

using namespace std;

class Smith{
	private:
		//Tree * smithInventory;
		int money;
	public:
		Smith();
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