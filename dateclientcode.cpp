// Jason Decker -> ClientCode

#include<iostream>
#include<fstream>
#include<string>
#include "nameType.h"

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	dateType d1;

	infile.open("dateInput.txt");
	outfile.open("dateOutput.txt");
	
	if (!infile || !outfile)
	{
		cout << "Error Opening one of the files, either create them or find them on the GitHub\n";
		system("pause");
		return 1;
	}

	outfile << "Jason Decker\n";

	while (!infile.eof())
	{
		try 
		{
			infile >> d1;
			d1.printDate(outfile);
		}
		catch (string errorMessage)
		{
			outfile << errorMessage << endl;
		}
	}

	infile.close();
	outfile.close();
	system("pause");
	return 0;
}
