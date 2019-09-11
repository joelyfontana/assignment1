#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//declare the thousands of variables we need
int t;
int a;
int c;
int g;
int tt;
int ta;
int tc;
int tg;
int at;
int aa;
int ac;
int ag;
int ct;
int ca;
int cc;
int cg;
int gt;
int ga;
int gc;
int gg;
int total = 0;
string line;
int lineNum = 0;
string fileInfo;
int mean;

//create a method to compute the sum, mean, variance, and standard deviation
int computeMath(string fileInfo)
{

	//print out the total length of the file
	cout << "File length: " << fileInfo.length() << endl;

	//calculate the sum and print it out to the command prompt
	for (char i = 0; i < fileInfo.length(); i++)
	{
		//need if statements because sum keeps including the \n
		if (fileInfo[i] == 'A')
		{
			total++;
		}
		if (fileInfo[i] == 'C')
		{
			total++;
		}
		if (fileInfo[i] == 'T')
		{
			total++;
		}
		if (fileInfo[i] == 'G')
		{
			total++;
		}
	}
	cout << "the sum is: " << total << endl;

	//calculate the mean  WHY DONT YOU WORK
	while (getline(fileInfo, line))
	{
		if (line.size > 0) 
		{
			lineNum++;
		}
	}
	mean = total / line;
	cout << "the mean is: " << mean << endl;
}

int main(int argc, char **argv)
{
	//check to make sure that the file name has been entered in the command prompt
	if (argc != 2)
	{
		//this part works fantasic because it tells me EVERY FREAKING TIME I FORGET
		cout << "please enter the name of the file you wish to open in the command prompt" << endl;
	}
	else
	{
		//open the file
		ifstream DNAtestFile(argv[1]);
		//sees if the file is open and then takes the contents of the file and puts it in a string
		if (DNAtestFile.is_open()) {
			cout << "File is open\n" << argv[1] << " contains:\n" << endl;
			string line;
			while (getline(DNAtestFile, line)) {
				fileInfo += line;
				cout << fileInfo << '\n';
			}
			//make the string lower case
		//	for(i)
			///fileInfo = tolower(fileInfo);
		}
		computeMath(fileInfo);
	}

	//always return 0
	return 0;
}


