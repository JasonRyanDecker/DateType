// Jason Decker -> DateType Class

#include<iostream>
#include<string>

using namespace std;

class exceptionHandler
{
public:
	exceptionHandler();
	exceptionHandler(string s);
	string errorMessage;
};
exceptionHandler::exceptionHandler()
{
	errorMessage = "";
}
exceptionHandler::exceptionHandler(string s)
{
	errorMessage = s;
	throw errorMessage;
}

class dateType 
{
protected:
	int myMonth;
	int myDay;
	int myYear;
	string myName;
public:
	dateType();
	dateType(int m, int d, int y);
	dateType(const dateType&);
	void printDate(ostream &os);
	void setDate(int m, int d, int y);
	void setName();
	const dateType& operator =(const dateType&);
	bool leap(int value);
	friend istream& operator>>(istream &is, dateType &dt);
};

dateType::dateType()
{
	myMonth = 1;
	myDay = 1;
	myYear = 0;
	setName();
}
dateType::dateType(int m, int d, int y)
{
	if (m < 1 || m > 12)
	{
		exceptionHandler error("ERROR: Month is out of bounds. Did not construct.");
	}
	else if(y < 0)
	{
		exceptionHandler error("ERROR: Year is out of bounds. Did not construct.");
	}
	else
	{
		switch (m)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (d > 31)
			{
				exceptionHandler error("ERROR: Day is out of bounds. Did not construct.");
			}
			break;
		case 4: case 6: case 9: case 11:
			if (d > 30)
			{
				exceptionHandler error("ERROR: Day is out of bounds. Did not construct.");
			}
			break;
		case 2: 
			if (((y % 4) == 0 && (y % 100) != 0) || ((y % 400) == 0))
			{
				if (d > 29)
				{
					exceptionHandler error("ERROR: Day is out of bounds. Did not construct.");
				}
			}
			else if (d > 28)
			{
				exceptionHandler error("ERROR: Day is out of bounds. Did not construct.");
			}
			break;
		default: 
			exceptionHandler error;
			break;

		}
	}

	myMonth = m;
	myDay = d;
	myYear = y;
	setName();
}
dateType::dateType(const dateType& d)
{
	myMonth = d.myMonth;
	myDay = d.myDay;
	myYear = d.myYear;
	setName();

}
void dateType::printDate(ostream &os)
{
	os << "Start----" << endl;
	os << "\tMonth: " << myMonth << endl;
	os << "\tDay: " << myDay << endl;
	os << "\tYear: " << myYear << endl;
	os << "\tName: " << myName << endl;
	os << "End----" << endl << endl;
}
void dateType::setDate(int m, int d, int y)
{
	myDay = d;
	myMonth = m;
	myYear = y;
	setName();
}
void dateType::setName()
{
	int total, monthCon;
	total = myYear + ((myYear / 4) - (myYear / 100) + (myYear / 400)) + 1;

	switch (myMonth)
	{
	case 1:
		//Jan
		monthCon = 0;
		total = total + monthCon;
		break;
	case 2:
		//Feb
		monthCon = 3;
		total = total + monthCon;
		break;
	case 3:
		//March
		monthCon = 3;
		total = total + monthCon;
		break;
	case 4:
		//April
		monthCon = 6;
		total = total + monthCon;
		break;
	case 5:
		//May
		monthCon = 1;
		total = total + monthCon;
		break;
	case 6:
		//Jun
		monthCon = 4;
		total = total + monthCon;
		break;
	case 7:
		//Jul
		monthCon = 6;
		total = total + monthCon;
		break;
	case 8:
		//Aug
		monthCon = 2;
		total = total + monthCon;
		break;
	case 9:
		//Sep
		monthCon = 5;
		total = total + monthCon;
		break;
	case 10:
		//Oct
		monthCon = 0;
		total = total + monthCon;
		break;
	case 11:
		//Nov
		monthCon = 3;
		total = total + monthCon;
		break;
	case 12:
		//Dec
		monthCon = 5;
		total = total + monthCon;
		break;
	default:
		monthCon = 0;
		break;
	}

	if (leap(total))
	{
		if (myMonth == 1 || myMonth == 2)
		{
			total = total - 1;
		}
	}

	total = total + (myDay - 1);
	total = total % 7;
	switch (total)
	{
	case 0:
		myName = "Saturday";
		break;
	case 1:
		myName = "Sunday";
		break;
	case 2:
		myName = "Monday";
		break;
	case 3:
		myName = "Tuesday";
		break;
	case 4:
		myName = "Wednesday";
		break;
	case 5:
		myName = "Thursday";
		break;
	case 6:
		myName = "Friday";
		break;
	default:
		myName = "NULL";
		break;
	}

}
bool dateType::leap(int value)
{
	return (myYear % 4 == 0 && myYear % 100 != 0) || (myYear % 400 == 0);
}
const dateType& dateType::operator=(const dateType& rhs)
{
	if (this != &rhs)
	{
		myMonth = rhs.myMonth;
		myDay = rhs.myDay;
		myYear = rhs.myYear;
		myName = rhs.myName;
	}
	return *this;
}
istream& operator>>(istream& is, dateType& dt)
{
	int m, d, y;
	is >> m;
	is >> d;
	is >> y;
	dateType temp(m, d, y);
	dt = temp;
	return is;
}





