#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
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
float total;
string line;
int lineNum = 0;
string fileInfo;
int mean;
int var;
int sDev;
int newSum;
int num;
char answer = 'y';


//create a method to compute the sum, mean, variance, and standard deviation
int computeMath(string fileInfo)
{
	//reopen file
	ofstream newFile;
	newFile.open("joelyfontana.txt", ofstream::app);

	//print out the total length of the file
	//cout << "File length: " << fileInfo.length() << endl;

	//calculate the sum and print it out to the command prompt
	for (char i = 0; i < fileInfo.length(); i++)
	{
		//need to seperate into if statements because sum keeps including the \n
		
		//A nucleotide
		if (fileInfo[i] == 'a')
		{
			a++;
			total++;
			//calculate the bigrams
			if (fileInfo[i + 1] == 'c')
			{
				ac++;
			}
			else if (fileInfo[i + 1] == 'g')
			{
				ag++;
			}
			else if (fileInfo[i + 1] == 't')
			{
				at++;
			}
			else if (fileInfo[i + 1] == 'a')
			{
				aa++;
			}

		}
		//C Nucleotide and bigrams
		if (fileInfo[i] == 'c')
		{
			c++;
			total++;
			if (fileInfo[i + 1] == 'c')
			{
				cc++;
			}
			else if (fileInfo[i + 1] == 'g')
			{
				cg++;
			}
			else if (fileInfo[i + 1] == 't')
			{
				ct++;
			}
			else if (fileInfo[i + 1] == 'a')
			{
				ca++;
			}
		}
		//T nucleotide and bigrams
		if (fileInfo[i] == 't')
		{
			t++;
			total++;
			if (fileInfo[i + 1] == 'c')
			{
				tc++;
			}
			else if (fileInfo[i + 1] == 'g')
			{
				tg++;
			}
			else if (fileInfo[i + 1] == 't')
			{
				tt++;
			}
			else if (fileInfo[i + 1] == 'a')
			{
				ta++;
			}
		}
		//G Nucleotide and its bigrams
		if (fileInfo[i] == 'g')
		{
			g++;
			total++;
			if (fileInfo[i + 1] == 'c')
			{
				gc++;
			}
			else if (fileInfo[i + 1] == 'g')
			{
				gg++;
			}
			else if (fileInfo[i + 1] == 't')
			{
				gt++;
			}
			else if (fileInfo[i + 1] == 'a')
			{
				ga++;
			}
		}
	}
}

//calculate the variance
int variance()
{
	float varTwo = 0;
	ifstream newFile;
	newFile.open("joelyfontana.txt", ofstream::app);

	//calculate the variance 
	while (getline(newFile, line))
	{
		int newSum = pow((int)(line.length() - mean), 2);
		varTwo += newSum;
	}
	
	var = (float)varTwo / (float)(lineNum - 1);
	//calculate the standard deviation UGHHHHHH i SUCK AT MATH
	sDev = sqrt(var);
}

int calcGaussian()
{
	//randomizes the numbers 
	float a = (float) rand() / (float)RAND_MAX;
	float b =(float) rand() / (float) RAND_MAX;
	float c = sqrt(-2 * log(a)) * cosf(2 * M_PI * b);
	float d = sqrt(var) * c + mean;
	return d;
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	while (answer = 'y')
	{
		//check to make sure that the file name has been entered in the command prompt
		if (argc != 2)
		{
			//this part works fantasic because it tells me EVERY FREAKING TIME I FORGET THE FILE
			cout << "please enter the name of the file you wish to open in the command prompt" << endl;
		}
		else
		{
			//open the file
			ifstream DNAtestFile(argv[1]);

			//sees if the file is open and then takes the contents of the file and puts it in a string
			//structure gotten from a source (in readme) but changed and modified to work for my code and purpose
			if (DNAtestFile.is_open()) {
				cout << "File " << argv[1] << " is open" << endl;
				string line;
				while (getline(DNAtestFile, line)) {
					fileInfo += line;
					//cout << fileInfo << '\n';
					lineNum++;
				}

				//make the string lower case

				string fileInfoLow;
				for (int i = 0; i < fileInfo.length(); i++)
				{
					fileInfoLow += tolower(fileInfo[i]);
				}

				DNAtestFile.close();
				fileInfo = fileInfoLow;
			}

			//write out to a new file
			ofstream newFile;
			newFile.open("joelyfontana.txt", ofstream::app);

			//declare the sum function
			computeMath(fileInfo);

			//stuff to write to the top of the file
			newFile << "Joely Fontana\n" << "2313535\n" << "Data Structures\n" << "Section 1\n" << "Programming Assignment 1\n" << endl;
			//calculate the mean and print
			mean = total / lineNum;
			newFile << "The mean is: " << mean << endl;
			//call the variance and standard deviation
			variance();
			newFile << "The variance is: " << var << endl;
			newFile << "The standard deviation is: " << sDev << endl;
			newFile << "The sum is: " << total << endl;

			//probability of neucleotides
			newFile << "The probability of 'A' is : " << a / total * 100 << "%" << endl;
			newFile << "The probability of 'C' is : " << c / total * 100 << "%" << endl;
			newFile << "The probability of 'T' is : " << t / total * 100 << "%" << endl;
			newFile << "The probability of 'G' is : " << g / total * 100 << "%" << endl;
			//probablity of A based Bigram
			newFile << "The probility of the bigram 'AC' is : " << ac / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'AT' is : " << at / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'AG' is : " << ag / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'AA' is : " << aa / total * 100 << "%" << endl;
			//probablity of C based Bigram
			newFile << "The probility of the bigram 'CC' is : " << cc / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'CT' is : " << ct / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'CG' is : " << cg / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'CA' is : " << ca / total * 100 << "%" << endl;
			//probablity of G based Bigram
			newFile << "The probility of the bigram 'GC' is : " << gc / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'GT' is : " << gt / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'GG' is : " << gg / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'GA' is : " << ga / total * 100 << "%" << endl;
			//probablity of T based Bigram
			newFile << "The probility of the bigram 'TC' is : " << tc / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'TT' is : " << tt / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'TG' is : " << tg / total * 100 << "%" << endl;
			newFile << "The probility of the bigram 'TA' is : " << ta / total * 100 << "%" << endl;

			//calculate the probability for the gaussian 
			for (int i = 0; i < 1000; i++)
			{
				float d = calcGaussian();
				string fileString;
				int aNeed = d * (a / total);
				fileString += aNeed;
				int cNeed = d * (c / total);
				fileString += cNeed;
				int gNeed = d * (g / total);
				fileString += gNeed;
				int tNeed = d * (t / total);
				fileString += tNeed;

				//convert the numbers to the letters
				for (int indexA = 0; indexA < aNeed; indexA++)
				{
					newFile << "a";
				}
				for (int indexG = 0; indexG < aNeed; indexG++)
				{
					newFile << "g";
				}
				for (int indexC = 0; indexC < aNeed; indexC++)
				{
					newFile << "c";
				}
				for (int indexT = 0; indexT < aNeed; indexT++)
				{
					newFile << "t";
				}
				newFile << "\n";
			}
			newFile.close();
		}

		cout << "Would you like to process another list? Enter y/n: ";
		cin >> answer;
		if (answer == 'y')
		{
			cout << "Enter the name of the file you wish to process: " << endl;
			cin >> fileInfo;
		}
		else if (answer == 'n')
		{
			cout << "Goodbye!" << endl;
			break;
		}
	}
	//always return 0
	return 0;
}



