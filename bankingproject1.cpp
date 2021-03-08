// Banking Project Part 1
// Xavier Hammond 
// Due 3/7/2021

#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;

class Bank // The bank of variables and values 
{
		char name[30];
		char username[20];
		char acctype[20];
		float ibalance;
		float depos;
		float with;
		string pass;
		
	public:
		void menu(void);
		void getdata(void);
		void deposit(void);
		void info(void);
};
	void Bank::menu() // The program's menu 
	{
		int num;
	cout<<"\n\n\n\t********************************";
	cout<<"\n\t   Welcome to your Bank!\n"<<endl;
	cout<<"\t     1.Create Account\n";
	cout<<"\t     2.Deposit\n";
	cout<<"\t     3.View Account Information\n";
	cout<<"\t     4.End";
	cout<<"\n\t********************************";
	cout<<"\t\n\t";cin>>num;
	switch(num)
	{
		case 1:
			getdata();
			break;
			
		case 2:
			deposit();
			break;
		
		case 3:
			info();
			break;
			
		default:
			break;
	}
	
	}
	
	void Bank::getdata() // This is the section that'll let the user create an account 
	{
		int go;
		cout<<"\n\t\tEnter the Name of Customer:";
		cin>>name;
		cout<<"\n\t\tChoose an username:";
		cin>>username;
		cout<<"\n\t\tWhat type of account would you like to create?\n";
		cout<<"\t\t\tSaving\n";
		cout<<"\t\t\tChecking\n";
		cout<<"\t\n\t";cin>>acctype;	
			cout<<"\n\t\tDeposit the Initial Balance: $";
			cin>>ibalance;
			cout<<"\n\t\tChoose your password:";
			cin>>pass;
			cout<<"\n\n\t\tYour account has been successfully created\n\n";   
		cout<<"\n\t\tHit \'0\' To go to the Main Menu:";
			cin>>go;
			if(go==0)
			{
				menu();
			}
	}
	
	void Bank::deposit() //Where the money is deposited 
	{
		int go;
		cout<<"\n\t\tEnter Amount Deposited: $";
		cin>>depos;
		depos+=ibalance;
		cout<<"\n\n\t\tYour balance has been successfully deposited.\n\n";
	
	cout<<"\n\t\tHit \'0\' To go to the Main Menu:";
			cin>>go;
			if(go==0)
			{
				menu();
			}
	}
	
	
	void Bank::info() // This is the where the program will display all values
	{
		string passcode;
		cout<<"\n\t\tEnter your Account's Password: ";
		cin>>passcode;
		if(pass==passcode)
		{
		int go;
		cout<<"\n\t\tAll Information is Listed Below:\n";
		cout<<"\t\t\tName of the Depositer:"<<name<<"\n";
		cout<<"\t\t\tUsername:"<<username<<"\n";
		cout<<"\t\t\tType of the Account:"<<acctype<<"\n";
		cout<<"\t\t\tYour Current Amount:$"<<depos<<"\n";
		cout<<"\n\t\tHit \'0\' To go to the Main Menu:";
			cin>>go;
			if(go==0)
			{
				menu();
			}
		}
		else
			cout<<"\n\t\tWrong password, try again";
	}
	

int main()
{
	Bank Obj,ob1;
	fstream inout("Bank.txt",ios::in|ios::out);
    Obj.menu();
    inout.write((char *)&Obj,sizeof(Obj));
    inout.seekg(0,ios::beg);
    inout.read((char *)&ob1,sizeof(ob1));
    ob1.menu();
	getch();
	return 0;
}
