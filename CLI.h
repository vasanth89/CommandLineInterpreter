#ifndef H_CLI_
#define H_CLI_
#include <string>
using namespace std;

//Class that provides the command line interpreter functions based on user input
class CLI{
public :
	void listShort();
	void listLong();
	void changeDirectory();
	void setCurrentDirectory(string directory);
	string getCurrentDirectory();
	CLI();
private :
	string currentDirectory;
	void printSystemTime(int flag);
};
#endif