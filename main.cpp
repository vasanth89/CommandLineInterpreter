// main.cpp : Defines the entry point for the console application.

#include <iostream>
#include <cstdio>
#include "CLI.h"
using namespace std;

//Start of program - Accepts input from user to perform various CLI functions in Windows
int main()
{
	int num;
	CLI newObj;
	do{
	cout<<endl<<"Welcome to Vasanth's CLI :"<<endl;
	cout<<"**********************************"<<endl;
	cout<<"Current Directory is:"<<newObj.getCurrentDirectory()<<endl;
	cout<<"Enter one of the following options : "<<endl;
	cout<<"1. List Short"<<endl;
	cout<<"2. List Long"<<endl;
	cout<<"3. Change Directory"<<endl;
	cout<<"4. Exit"<<endl;
	cin>>num;
	switch(num){
	case 1 :
		newObj.listShort();
		break;
	case 2:
		newObj.listLong();
		break;
	case 3:
		newObj.changeDirectory();
		break;
	case 4:
		cout<<"See you later"<<endl;
		break;
	default:
		cout<<"Invalid Selection";
		break;
	}
}while(num!=4);
return 0;
}
