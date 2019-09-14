/*Joely Fontana
Student ID: 2313535
Data Structures
Section 1
Programming Assignment 1
*/

#include <iostream>
#include <fstream>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

//declare the thousands of variables we need
int t = 0, a =0, c=0, g=0;
int tt=0, ta=0, tc=0, tg=0;
int at=0, aa=0, ac=0, ag=0;
int ct=0, ca=0, cc=0, cg=0;
int gt=0, ga=0, gc=0, gg=0;
float total;
string line;
int lineNum = 0;
string fileInfo;
int mean =0; 
float var =0;
float sDev =0;
int newSum =0;
int num =0;
int bigram =0;
char answer = 'y';


//create a method to compute the sum, mean, variance, and standard deviation
//make void - does not return anything
void computeMath(string fileInfo)
{
	//calculate the sum and print it out to the command prompt
	for (int i = 0; i < fileInfo.length(); i++)
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
				bigram++;
				ac++;
			}
			else if (fileInfo[i + 1] == 'g')
			{
				bigram++;
				ag++;
			}
			else if (fileInfo[i + 1] == 't')
			{
				bigram++;
				at++;
			}
			else if (fileInfo[i + 1] == 'a')
			{
				bigram++;
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
				bigram++;
				cc++;
			}
			else if (fileInfo[i + 1] == 'g')
			{
				bigram++;
				cg++;
			}
			else if (fileInfo[i + 1] == 't')
			{
				bigram++;
				ct++;
			}
			else if (fileInfo[i + 1] == 'a')
			{
				bigram++;
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
				bigram++;
				tc++;
			}
			else if (fileInfo[i + 1] == 'g')
			{
				bigram++;
				tg++;
			}
			else if (fileInfo[i + 1] == 't')
			{
				bigram++;
				tt++;
			}
			else if (fileInfo[i + 1] == 'a')
			{
				bigram++;
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
				bigram++;
				gc++;
			}
			else if (fileInfo[i + 1] == 'g')
			{
				bigram++;
				gg++;
			}
			else if (fileInfo[i + 1] == 't')
			{
				bigram++;
				gt++;
			}
			else if (fileInfo[i + 1] == 'a')
			{
				bigram++;
				ga++;
			}
		}
	}
}

//calculate the variance
//make void because does not return anything
void variance(string inputFileName)
{
	float varTwo = 0;
	ifstream newFile;
	newFile.open(inputFileName);

	//calculate the variance 
	while (getline(newFile, line))
	{
		int newSum = pow((int)(line.length() - mean), 2);
		varTwo += newSum;
	}
	
	var = (float)varTwo / (float)(lineNum - 1);
	//calculate the standard deviation UGHHHHHH i SUCK AT MATH
	sDev = sqrt(var);
	
	//close the file
	newFile.close();
}

//calculates the Gaussian - equations gotten from rubric
//returns the Gaussian
int calcGaussian()
{
	//randomizes the numbers and normalizes them
	float a = (float) rand() / (float)RAND_MAX;
	float b =(float) rand() / (float) RAND_MAX;
	float c = sqrt(-2 * log(a)) * cosf(2 * M_PI * b);
	float d = sqrt(var) * c + mean;
	return d;
}

//MAIN METHOD ---------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	//randomizes the numbers based off of the time
	srand(time(NULL));

	string dnaFileName = argv[1];

	//write out to a new file
	ofstream newFile;
	newFile.open("joelyfontana.txt");

	while (answer == 'y')
	{
		//check to make sure that the file name has been entered in the command prompt
		if (argc != 2)
		{
			//this part works fantasic because it tells me EVERY FREAKING TIME I FORGET THE FILE
			cout << "please enter the name of the file you wish to open in the command prompt" << endl;
		}

		// if file has been entered correctly: 
		else
		{
			//open the file
			ifstream DNAtestFile;
			DNAtestFile.open(dnaFileName);

			//checks to make sure that the file name entered is an actual file
			if (!DNAtestFile)
			{
				cout << "Not a valid file name. Please enter a valid file name: " << endl;
				cin >> dnaFileName;
				continue;
			}

			//sees if the file is open and then takes the contents of the file and puts it in a string
			//structure gotten from a source (in readme) but changed and modified to work for my code and purpose
			if (DNAtestFile.is_open()){
				cout << "File " << dnaFileName << " is open" << endl;
				
				string line;
				while (getline(DNAtestFile, line)) {
					fileInfo += line;
					lineNum++;
				}

				//check to make sure the file is not empty
				if (lineNum == 0) {
					cout << "File is empty. Please add content." << endl;
					break;
				}

				//check to see if the file has only 1 line
				if (lineNum == 1) {
					cout << "File contains only one line. The statistics may be incorrect. Please add more lines to your file." << endl;
					break;
				}


				//make the file string lower case
				string fileInfoLow;
				for (int i = 0; i < fileInfo.length(); i++)
				{
					fileInfoLow += tolower(fileInfo[i]);
				}

				//close the file
				DNAtestFile.close();
				fileInfo = fileInfoLow;

			}

			//declare the sum function
			computeMath(fileInfo);

			//stuff to write to the top of the file
			newFile << "Joely Fontana\n" << "2313535\n" << "Data Structures\n" << "Section 1\n" << "Programming Assignment 1\n" << endl;
			//calculate the mean and print
			mean = total / lineNum;
			newFile << "The mean is: " << mean << endl;

			//call the variance and print the variance and the standard deviation to the file
			variance(dnaFileName);
			newFile << "The variance is: " << var << endl;
			newFile << "The standard deviation is: " << sDev << endl;
			newFile << "The sum is: " << total << endl;

			//cast all nucleotides as floats to save memory and make sure they are not 0
			//probability of neucleotides
			newFile << "The probability of 'A' is : " << (float) a / total * 100 << "%" << endl;
			newFile << "The probability of 'C' is : " << (float) c / total * 100 << "%" << endl;
			newFile << "The probability of 'T' is : " << (float) t / total * 100 << "%" << endl;
			newFile << "The probability of 'G' is : " << (float) g / total * 100 << "%" << endl;

			//cast all bigrams as floats so they are not zero and to save memory
			//probablity of A based Bigram
			newFile << "The probility of the bigram 'AC' is : " << (float) ac / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'AT' is : " << (float)at / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'AG' is : " << (float)ag / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'AA' is : " << (float)aa / bigram * 100 << "%" << endl;
			//probablity of C based Bigram
			newFile << "The probility of the bigram 'CC' is : " << (float)cc / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'CT' is : " << (float)ct / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'CG' is : " << (float)cg / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'CA' is : " << (float)ca / bigram * 100 << "%" << endl;
			//probablity of G based Bigram
			newFile << "The probility of the bigram 'GC' is : " << (float)gc / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'GT' is : " << (float)gt / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'GG' is : " << (float)gg / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'GA' is : " << (float)ga / bigram * 100 << "%" << endl;
			//probablity of T based Bigram
			newFile << "The probility of the bigram 'TC' is : " << (float)tc / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'TT' is : " << (float)tt / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'TG' is : " << (float)tg / bigram * 100 << "%" << endl;
			newFile << "The probility of the bigram 'TA' is : " << (float)ta / bigram * 100 << "%" << endl;

			//calculate the probability for the gaussian and add it to the string 
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
				for (int indexG = 0; indexG < gNeed; indexG++)
				{
					newFile << "g";
				}
				for (int indexC = 0; indexC < cNeed; indexC++)
				{
					newFile << "c";
				}
				for (int indexT = 0; indexT < tNeed; indexT++)
				{
					newFile << "t";
				}
				newFile << "\n";
			}
			
		}

		//ask user if they would like to process another list and append it to the file
		cout << "Would you like to process another list? Enter y/n: ";
		cin >> answer;
		if (answer == 'y')
		{
			//reset all of the values to 0 so they do not continue building on one another
			t = 0; a = 0; c = 0; g = 0;
			tt = 0; ta = 0; tc = 0; tg = 0;
			at = 0; aa = 0; ac = 0; ag = 0;
			ct = 0; ca = 0; cc = 0; cg = 0;
			gt = 0; ga = 0; gc = 0; gg = 0;
			total = 0;
			lineNum = 0;
			fileInfo = "";
			mean = 0; var = 0; sDev = 0; newSum = 0; num = 0; bigram = 0;
			cout << "Enter the name of the file you wish to process: " << endl;
			cin >> dnaFileName;
		}
		else if (answer == 'n')
		{
			cout << "Goodbye!" << endl;
			break;
		}
	}

	//close the output file
	newFile.close();
	
	//always return 0
	return 0;
}



