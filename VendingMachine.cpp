#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include<sstream>
#include "VendingMachine.h"

	const std::string VendingMachine :: getMachineName ()
	{
		return machineName; 
	}
	 void VendingMachine :: setMachineName	(std :: string newMachineName)
	{
		machineName=newMachineName;
	}
	const int VendingMachine ::  getChangeLevel()
	{
		return changeLevel;
	}
	 bool VendingMachine ::  incrementChangeLevel( int amountToAdd)
	{
		if ( (changeLevel+amountToAdd) > maxChangeCapacity)
		{
			return false;
		}
		else
		{
			changeLevel+=amountToAdd;
			return true;
		}
	}
	std::string VendingMachine ::  displayMoney(int amount)
	{
		return  ("$"+std::to_string(amount/100))+ "." +(std::to_string(amount%100))+ ((std::to_string(amount%100)).size() == 1 ? "0" : "");
	}
	 bool VendingMachine :: incrementInventory( int amountToAdd)
	{
	}
	const int VendingMachine :: getMaxInventoryCapacity()
	{
	}
	const int VendingMachine ::  getInventoryLevel()
	{
	}
    
	 const int VendingMachine ::  getMaxChangeCapacity()
	{
		return maxChangeCapacity;
	}
	