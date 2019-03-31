/*
Author: Shivangi Vyas
Id: 1001570499\
*/
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include<sstream>
#include "VendingMachine.h"
//include guard
#ifndef COKE_MACHINE_H
#define COKE_MACHINE_H
class CokeMachine : public VendingMachine
{
	friend std:: ostream& operator << (std::ostream& info, CokeMachine& Coke);
	friend void CreateCokeOutputLine (std::vector<CokeMachine> &Final,std:: string& fileName);
	
	public:
	CokeMachine(std::string  name="Machine Name", int cost=50, int change=500, int inventory=100);
	~CokeMachine();
	const int getInventoryLevel();
	const	int getMaxInventoryCapacity();
	bool incrementInventory( int amountToAdd);
	const int  getCokePrice();
	bool buyACoke(int payment, std::string& change, int& action);
	void setCokePrice	(int newCokePrice);
	
	private:
	int CokePrice;
	int inventoryLevel;
	int maxInventoryCapacity=100;
	
};
#endif
