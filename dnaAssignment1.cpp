#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char **argv)
{
	//check to make sure that the file name has been entered in the command prompt
	if (argc = 1)
	{
		cout << "please enter the name of the file you wish to open in the command prompt" << endl;
	}
	else
	{
		//open the file
		ifstream DNAtestFile(argv[1]);
		//TESTING TO SEE IF FILE IS OPEN -- REMOVE BEFORE TURN IN
		if (DNAtestFile.is_open() && DNAtestFile.good()) {
			cout << "File is now open!\nContains:\n";
			string line = "";
			while (getline(DNAtestFile, line)) {
				cout << line << '\n';
			}
		}
	}
	//always return 0
	return 0;
}

/*int sum()
{

}
 
int mean()
{

}

int variance()
{

}

int stdDeviation()
{

}
*/