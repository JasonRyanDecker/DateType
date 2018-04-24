// Jason Decker -> Date Functions 

#include<iostream>
#include "dateType.h"
#include<string>
#include<ostream>

using namespace std;

dateType::dateType()
{
	myMonth = 1;
	myDay = 1;
	myYear = 0;
}
dateType::dateType(int m, int d, int y)
{
	myMonth = m;
	myDay = d;
	myYear = y;
}
dateType::dateType(const dateType& d)
{
	myMonth = d.myMonth;
	myDay = d.myDay;
	myYear = d.myYear;
}
void dateType::printDate(ostream &os, string d_name)
{
	os << d_name << "----" << endl;
	os << "\tMonth: " << myMonth << endl;
	os << "\tDay: " << myDay << endl;
	os << "\tYear: " << myYear << endl << endl;
	os << "End----" << endl << endl;
}
void dateType::printError(ostream &os, string e_type)
{
	os << e_type << endl << endl;
}
void dateType::setDate(int m, int d, int y)
{
	myDay = d;
	myMonth = m; 
	myYear = y;
}
int dateType::getMonth()
{
	return myMonth;
}
int dateType::getDay()
{
	return myDay;
}
int dateType::getYear()
{
	return myYear;
}
const dateType& dateType::operator=(const dateType& rhs)
{
	if (this != &rhs)
	{
		myMonth = rhs.myMonth;
		myDay = rhs.myDay;
		myYear = rhs.myYear;
	}
	return *this;
}

