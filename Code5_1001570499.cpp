/*
Author: Shivangi Vyas
Id: 1001570499\
*/

#include <iostream>
#include  <gtkmm.h>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "CokeLib.h"
#include "CokeMachine.h"
#include "VendingMachine.h"


using namespace std;
void  get_command_line_params ( int argc , char *argv[], string& inputFile, string& outputFile)
	{
		int i;
		bool flag1 =true;
		bool flag2 =true;
		string cla;
	
	for (i = 1; i < argc; i++)
	{
		 string cla = argv[i];
		

		if (cla.substr(0, cla.find("=")) == "INPUTFILENAME")
		{
			 inputFile =cla.substr(cla.find("=")+1, cla.length());
			flag1 = false;
			
		}
		else if (cla.substr(0, cla.find("=")) == "OUTPUTFILENAME")
		{
			 outputFile =cla.substr(cla.find("=")+1, cla.length());
			flag2=false;
		}
		
	}
	if(flag1 || flag2)
	{
		
		throw invalid_argument("Missing command line parameters – - Usage : INPUTFILENAME= OUTPUTFILENAME= \n");

	}
		
		
	}
int Menu()
{
	Gtk::Dialog *ThisDialog = new Gtk::Dialog();
	ThisDialog->set_title("Question");
	
	std::vector<std::string> buttons = {"Walk away","Buy a Coke","Restock Machine","Add change","Display Machine Info","Update Machine Name","Update Coke Price"};
	
	for (int i = 0; i < buttons.size(); i++)
	ThisDialog->add_button(buttons[i], i);
	ThisDialog->set_default_response(0);
	
	Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("Please pick an option!"));
	ThisDialog->get_vbox()->pack_start(*MyLabel);
	MyLabel->show();
	
	/*Gtk::Image *MyImage = Gtk::manage(new Gtk::Image{"COKE.jpg"});
	MyImage->show();
	ThisDialog->get_vbox()->pack_start(*MyImage);
*/
	int what=ThisDialog->run();;
	ThisDialog->close();
	delete ThisDialog;
	return what;
}
int Payment()
{
	
	Gtk::Dialog *MyDialog = new Gtk::Dialog();
			MyDialog->set_title("How much money you got?");
			std::vector<std::string> buttons = {"Cancel", "OK"};
			
			Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
			MyEntry->set_text("Insert Payment");
			MyEntry->set_max_length(50);
			MyEntry->show();
			MyDialog->get_vbox()->pack_start(*MyEntry);
			
			for (int i = 0; i < buttons.size(); i++)
			MyDialog->add_button(buttons[i], i);
			MyDialog->set_default_response(1);
			
			Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("Enter the amount in cents:"));
			MyDialog->get_vbox()->pack_start(*MyLabel);
			MyLabel->show();
	
			int gotIt = MyDialog->run();
			int MOney=stoi(MyEntry->get_text());
			MyDialog->close();
			delete MyDialog;
	return MOney;
}
int RestockValue()
{
	
	Gtk::Dialog *MyDialog = new Gtk::Dialog();
			MyDialog->set_title("How much coke you got?");
			std::vector<std::string> buttons = {"Cancel", "OK"};
			
			Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
			MyEntry->set_text("Insert the number of coke");
			MyEntry->set_max_length(50);
			MyEntry->show();
			MyDialog->get_vbox()->pack_start(*MyEntry);
			
			for (int i = 0; i < buttons.size(); i++)
			MyDialog->add_button(buttons[i], i);
			MyDialog->set_default_response(1);
			
			Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("Enter the amount you are adding:"));
			MyDialog->get_vbox()->pack_start(*MyLabel);
			MyLabel->show();
			
			int gotIt = MyDialog->run();
			int Coke=stoi(MyEntry->get_text());
			MyDialog->close();
			delete MyDialog;
	return Coke;
}
int AddChange()
{
	
	Gtk::Dialog *MyDialog = new Gtk::Dialog();
			MyDialog->set_title("How much money you got?");
			std::vector<std::string> buttons = {"Cancel", "OK"};
			
			Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
			MyEntry->set_text("Insert the ampunt of change you are adding");
			MyEntry->set_max_length(50);
			MyEntry->show();
			MyDialog->get_vbox()->pack_start(*MyEntry);
			
			for (int i = 0; i < buttons.size(); i++)
			MyDialog->add_button(buttons[i], i);
			MyDialog->set_default_response(1);
			
			Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("Enter the amount you are adding in cents:"));
			MyDialog->get_vbox()->pack_start(*MyLabel);
			MyLabel->show();
			
			int gotIt = MyDialog->run();
			int addChange=stoi(MyEntry->get_text());
			MyDialog->close();
			delete MyDialog;
	return addChange;
}
int UpdateCokePrice()
{
	
	Gtk::Dialog *MyDialog = new Gtk::Dialog();
			MyDialog->set_title("How much money you got?");
			std::vector<std::string> buttons = {"Cancel", "OK"};
			
			Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
			MyEntry->set_text("Insert new price for coke");
			MyEntry->set_max_length(50);
			MyEntry->show();
			MyDialog->get_vbox()->pack_start(*MyEntry);
			
			for (int i = 0; i < buttons.size(); i++)
			MyDialog->add_button(buttons[i], i);
			MyDialog->set_default_response(1);
			
			Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("Enter the new price in cents"));
			MyDialog->get_vbox()->pack_start(*MyLabel);
			MyLabel->show();
			
			int gotIt = MyDialog->run();
			int newPrice=stoi(MyEntry->get_text());
			MyDialog->close();
			delete MyDialog;
	return newPrice;
}
string UpdateMachineName()
{
	
	Gtk::Dialog *MyDialog = new Gtk::Dialog();
			MyDialog->set_title("Show me some creativity");
			std::vector<std::string> buttons = {"Cancel", "OK"};
			
			Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
			MyEntry->set_text("Insert new name for your machine");
			MyEntry->set_max_length(50);
			MyEntry->show();
			MyDialog->get_vbox()->pack_start(*MyEntry);
			
			for (int i = 0; i < buttons.size(); i++)
			MyDialog->add_button(buttons[i], i);
			MyDialog->set_default_response(1);
			
			Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("Enter the new name for your machine:"));
			MyDialog->get_vbox()->pack_start(*MyLabel);
			MyLabel->show();
			
			int gotIt = MyDialog->run();
			string MachineName=MyEntry->get_text();
			MyDialog->close();
			delete MyDialog;
	return MachineName;
}
bool Mapit (vector<CokeMachine> &Addthem, int &position,map <string, int>& Receipt)
{
	
	if (position>0)
	{
	if (Receipt.find((Addthem[position-1]).getMachineName()) != Receipt.end())
	{
		Receipt[(Addthem[position-1]).getMachineName()]+=1;
	}
	else
	{
		Receipt[(Addthem[position-1]).getMachineName()]=1;
		
	}
	}
	if (Receipt.size()== 0)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

int MenuOfCokeMachines (vector<CokeMachine>& Name, string& FileName,map <string, int>& receipt)
{
	int i;
	bool flag=true;
	while (flag)
	{
	cout<<"\n\n0. Exit\n";
	int i=0;
	for ( auto printname : Name)
	{
		cout<<i+1 <<". "<<printname.getMachineName()<<endl;
		i++;
	}
	cout<<i+1<<". "<<"Add a new machine"<<endl;
	flag=false;
		
	cout<< "\nEnter Choice\n";
	int choice;
	cin>>choice;
	if(choice>0 && choice<i)
	{
		flag=false;
	return choice;
	
	}
	else if (choice==0)
	{
		
		flag=false;
		CreateCokeOutputLine(Name, FileName);
		if (Mapit(Name,choice,receipt))
		{
			cout<<"\n\n";
			for (auto machines : receipt)
			cout << machines.first<<" : " << machines.second<<endl;
			
		}
		exit(0);
		
	}
	else if(choice==i+1)
	{
		CokeMachine Newone;
		Name.push_back(Newone);
		cout<<"\nNew machine added\n\n";
		flag=true;
	}
	
	}
	
}
int main(int argc , char *argv[])
{
	Gtk::Main kit(argc, argv); 	
	
	int input;
	string change;
	int action=0;
	int newCokePrice;
	string newMachineName;
	string inputFileName;
	string outputFileName;
	string CokeMachineLine;
	vector <CokeMachine> SetOfCokeMachines;
	vector <string> ConstructorValues(4);
	map <string, int> FinalReceipt;
	try
	{
		get_command_line_params (argc,argv,inputFileName,outputFileName );
	}
	catch ( invalid_argument& say )
	
	{
		cerr << "\nAn exception occurred: "<<say.what() <<endl;
		return 0;
		
	}
	ifstream CokeInputFile{inputFileName};
	
	
if (CokeInputFile.is_open())
{
	while (getline(CokeInputFile, CokeMachineLine))
	{
		if(ParseCokeLine(CokeMachineLine, ConstructorValues))
		{
			string tempName{ConstructorValues.at(0)};
			int tempCost{stoi(ConstructorValues.at(1))};
			int tempChange{stoi(ConstructorValues.at(2))};
			int tempInventory{stoi(ConstructorValues.at(3))};
			CokeMachine temp(tempName,tempCost,tempChange,tempInventory);
			SetOfCokeMachines.push_back(temp);
		}
	}
	 input=MenuOfCokeMachines(SetOfCokeMachines, outputFileName,FinalReceipt);
	 
	int pickoption;
	pickoption=Menu();
	while( input!=0 )								//Runs until you hit 0
	{
		
		switch(pickoption)								//MENU
		{
			
		case 1:
		{
			int money=Payment();
			
				if((SetOfCokeMachines[input-1]).buyACoke(money,change,action))
				{
					Mapit(SetOfCokeMachines,input,FinalReceipt);
					if(action)
					{
						std::string message{"Here's your coke\nThanks for exact change"};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
						
					}
					else
					{
						std::string message{"Here's your coke and you change "+change};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
					}
				}
				else
				{
					switch(action)
					{
					case 1:
					{
						std::string message{"Insufficent payment...returning your payment\n"};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
					}
					break;
					case 2:
					{
						std::string message{"Sorry. We are out of coke...returning your payment\n"};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
					}
					break;
					case 3:
						{
						std::string message{"Unable to give change at this time...returning your payment\n"};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
					}
						
					break;
					}
				}
		}
		break;
		case 2:
		{
		int product=RestockValue();
			
			if ( (SetOfCokeMachines.at(input-1)).incrementInventory(product))
			{				
				std::string message{"Your machine has been restocked\n"};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
			}
			else
			{
				std::string message{"You have exceeded your machine's max capacity\n"};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
			}
			std::string message{"Your inventory level is now " + to_string((SetOfCokeMachines.at(input-1)).getInventoryLevel())};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
			
		}
		break;
		case 3:
		{
		int add=AddChange();
		
			if((SetOfCokeMachines.at(input-1)).incrementChangeLevel(add))
			{
				std::string message{"Your change has been updated "};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
			}
			else
			{
				std::string message{"You have exceeded your machine's max change capacity\n"};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
				
			}
			string message="Your change level is now " + (SetOfCokeMachines.at(input-1)).displayMoney((SetOfCokeMachines.at(input-1)).getChangeLevel());
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
		}
			//cout<<"\n\nYour change level is now "<<(SetOfCokeMachines.at(input-1)).displayMoney((SetOfCokeMachines.at(input-1)).getChangeLevel())<<endl;		//)/100+"."+(cents.size() == 1 ? "0" : "") + cents<<endl;
		break;
		case 4: 
		{
				ostringstream INFO;
				INFO<<(SetOfCokeMachines.at(input-1))<<endl;
				std::string message = INFO.str();
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
				
		}
		break;
		default: cout << "\n\nPlease provide a valid input\n" <<endl;
		break;
		case 5:
		{
				newMachineName=UpdateMachineName();
				(SetOfCokeMachines.at(input-1)).setMachineName(newMachineName);
				std::string message{"Machine name has been updated"};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
				
		}
		break;
		case 6:
		{
				 newCokePrice=UpdateCokePrice();
				(SetOfCokeMachines.at(input-1)).setCokePrice(newCokePrice);
				std::string message{"Coke Price has been updated"};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
		}
		break;	
	  case 0:
			input=MenuOfCokeMachines(SetOfCokeMachines, outputFileName,FinalReceipt);
			cout<<"\n\n\n" << (SetOfCokeMachines.at(input-1)).getMachineName();
			pickoption=Menu();
			continue;
		break;
			
	}	
	    cout<< "\n\n" <<(SetOfCokeMachines.at(input-1)).getMachineName()<<endl;;
		 pickoption=Menu();
}
					std::string message{"Are you really walking away from me :("};
						Gtk::MessageDialog *MyMessageDialog =
						new Gtk::MessageDialog{message, true,Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
						MyMessageDialog->run();
						MyMessageDialog->close();
						delete MyMessageDialog;
}
else
{
cout << "Unable to open the file" << endl;
return 0;
}
	return 0;
}
