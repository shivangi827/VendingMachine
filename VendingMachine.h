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
//include guard
#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H


class VendingMachine
{
public:

	const std::string  getMachineName ();
	void setMachineName	(std :: string newMachineName);
	const int  getChangeLevel();
	bool incrementChangeLevel( int amountToAdd);
	const int  getMaxChangeCapacity();
	std::string  displayMoney(int amount);
	virtual const	int getMaxInventoryCapacity()=0;
	virtual bool incrementInventory( int amountToAdd)=0;
	virtual	const int getInventoryLevel()=0;

private:
	std::string machineName;
	int changeLevel=0;
	int maxChangeCapacity= 5000;

};
#endif