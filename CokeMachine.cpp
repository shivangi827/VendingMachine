/*
Author: Shivangi Vyas
Id: 1001570499\
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include<sstream>
#include "CokeMachine.h"
#include "VendingMachine.h"
	
	CokeMachine:: CokeMachine(std::string  name, int cost, int change, int inventory)
		: CokePrice{cost},inventoryLevel{inventory}
	{
		setMachineName(name);
		incrementChangeLevel(change);
	}
	CokeMachine::  ~CokeMachine() {	}
   const int CokeMachine ::  getInventoryLevel()
	{
		return inventoryLevel;
	}
	 const int CokeMachine ::   getCokePrice()
	{
		return CokePrice;
	}
    bool CokeMachine :: incrementInventory( int amountToAdd)
	{
		if ( (inventoryLevel + amountToAdd ) > maxInventoryCapacity)
		{
			return false;
		}
		else
		{
			inventoryLevel+= amountToAdd;
			return true;
		}
	}
    const int CokeMachine :: getMaxInventoryCapacity()
	{
		return maxInventoryCapacity;		
	}
	 void CokeMachine :: setCokePrice	(int newCokePrice)
	{
		CokePrice=newCokePrice;
	}
	 bool CokeMachine ::  buyACoke(int payment, std::string& change, int& action)
	{
		if(payment<CokePrice)
		{
			action=1; //insufficient funds
			return false;
			
		}
		else if(inventoryLevel<=0)
		{
			action=2; //no inventory
			return false;
		}
		else if((payment-CokePrice)> (getChangeLevel()))
		{
			action=3; //no change
			return false;
		}
		else if (payment == CokePrice)
		{
			action=4; //Exact change
			inventoryLevel--;
			incrementChangeLevel(CokePrice);
			return true;
		}
		else
		{
			action=0;
			incrementChangeLevel((payment-CokePrice));
			incrementChangeLevel(CokePrice);
			inventoryLevel--;
			payment-=CokePrice;
			change=displayMoney(payment);
			return true;
		}
	}
	
	std:: ostream& operator << ( std::ostream& info, CokeMachine& Coke)
	{
		
		info<<"\nMachine Name: "<<Coke.getMachineName()<<"\n\n\nCurrent Inventory Level: " << Coke.getInventoryLevel()<<std:: endl<<"Max Inventory Capacity: "<<  Coke.getMaxInventoryCapacity()<<"\n\nCurrent Change Level: "<< Coke.displayMoney(Coke.getChangeLevel())<<std:: endl<<"Change Capacity: "<<Coke.displayMoney(Coke.getMaxChangeCapacity())<<std:: endl<<"\n\nCurrent Coke price: "<< Coke.displayMoney(Coke.getCokePrice())<<std:: endl<<"\n\n"<<std:: endl;
		return info;
	}
	void CreateCokeOutputLine (std::vector<CokeMachine> &Final, std::string& fileName )
{
	std :: ofstream CokeOutputFile{fileName,std:: ios::out};
	int i=0;
	
	for (i=0 ; i<Final.size() ;i++)
	{		
		CokeOutputFile << (Final.at(i)).getMachineName()<<"|"<<(Final.at(i)).CokePrice<<"|"<<(Final.at(i)).getChangeLevel()<<"|"<<std:: to_string((Final.at(i)).inventoryLevel)<< std:: endl;
	}
	
}
	
	
