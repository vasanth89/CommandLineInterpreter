//Implementation of the CLI functions mentioned in CLI.h
#include "CLI.h"
#include <afx.h>
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#define BEGIN 1
#define END 2

//Default Constructor to set the home directory
CLI::CLI(){
	currentDirectory="C:\\\*.\*";
}

//Method to set the current directory
void CLI::setCurrentDirectory(string directory){
currentDirectory=directory;
}

//Method to fetch the current directory information
string CLI::getCurrentDirectory(){
return currentDirectory;
}

//Method to list the directory contents ('ls' function)
void CLI::listShort(){
	cout<<"Inside the method list Short"<<endl;
	
	//print the time before execution starts to measure performance
	printSystemTime(BEGIN);

	//Use the Microsoft Foundation Class library for performing Windows API calls
	CFileFind finder;
	wstring directoryPathChanged;
	directoryPathChanged.assign(currentDirectory.begin(),currentDirectory.end());
	BOOL bWorking = finder.FindFile(directoryPathChanged.c_str());
	//Loop through the directory file by file
	while (bWorking)
	{
     bWorking = finder.FindNextFile();
     if (finder.IsDots()) continue;
	 //Condition to handle if the file is a directory
     if (finder.IsDirectory())
         {
		 wcout<<(LPCTSTR)finder.GetFileName().GetString()<<" - Directory"<<endl;
         continue;
      }
	 wcout<<(LPCTSTR)finder.GetFileName().GetString()<<endl;
	}
	finder.Close();

	//print the time after completion to measure performance
	printSystemTime(END);
}

//Method to list the directory contents in detail ('ls -l' function)
void CLI::listLong(){
	cout<<"Inside the method list Long"<<endl;

	//print the time before execution starts to measure performance
	printSystemTime(BEGIN);
	
	CTime timeStamp;
	CString timeString;
	CFileFind finder;
	wstring directoryPathChanged;
	
	directoryPathChanged.assign(currentDirectory.begin(),currentDirectory.end());
	BOOL bWorking = finder.FindFile(directoryPathChanged.c_str());
	//Loop through the directory file by file
	while (bWorking)
	{
     bWorking = finder.FindNextFile();
     if (finder.IsDots()) continue;
	 if(finder.GetLastAccessTime(timeStamp)){
		 timeString = timeStamp.Format("%c");
	 } else {
		 timeString = "unavailable";
	 }
	 //Condition to handle if the file is a directory
     if (finder.IsDirectory())
         {
		 wcout<<(LPCTSTR)finder.GetFileName().GetString()<<" - Directory"<<"\t"<<timeString.GetString()<<endl;
         continue;
      }
	 wcout<<(LPCTSTR)finder.GetFileName().GetString()<<"\t"<<(ULONGLONG)finder.GetLength()<<"byte(s)"<<"\t"<<timeString.GetString()<<endl;
	}
	finder.Close();

	//print the time after completion to measure performance
	printSystemTime(END);
}

//Method to change the directory ('cd' function)
void CLI::changeDirectory(){
	cout<<"Inside the method change Directory"<<endl;

	//print the time before execution starts to measure performance
	printSystemTime(BEGIN);
	string newDirectory="";

	cout<<"Enter the new directory path : "<<endl;
	cin.ignore();
	getline(cin,newDirectory);
	//Format the directory entered by user
	if(!newDirectory.empty()){
		char lastChar=*newDirectory.rbegin();
		if (lastChar == '\\')
			newDirectory.append("\*.\*");
		else
			newDirectory.append("\\\*.\*");
	}
	CFileFind finder;
	wstring directoryPathChanged;
	directoryPathChanged.assign(newDirectory.begin(),newDirectory.end());
	BOOL bWorking = finder.FindFile(directoryPathChanged.c_str());
	//Check if directory exists
	if(bWorking)
		currentDirectory=newDirectory;
	else
		cout<<"Check the directory path provided !!"<<endl;

	//print the time after completion to measure performance
	printSystemTime(END);
}

//Method to print the system time to measure performance of the various command line operations
void CLI::printSystemTime(int flag){
	SYSTEMTIME st;

    GetSystemTime(&st);
	if (flag == 1)
		printf("The begin time is: %02d:%02d:%02d:%03d\n", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	else if(flag == 2)
		printf("The end time is: %02d:%02d:%02d:%03d\n", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
}