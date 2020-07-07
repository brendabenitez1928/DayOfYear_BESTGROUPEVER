/*  GroupProjectDayOfYear.cpp | 7/6/2020
	Austin Sommars, Brenda Benitez, Brogan Avery, Nick Hofmann

	This program will ask the user to input an integer between 1 and 365 and then display
	what month and day of the year that number would equate to.

	Austin and Brenda designed the DayOfYear::print() function while Brogan and Nick built the main
	function/method.

*/
#include <iostream>
using namespace std;

class DayOfYear  // Used the hint from Blackboard to create the DayOfYear class.
{
private:
	int day;

public:
	~DayOfYear();  // Destructor
	static int daysAtEndOfMonth[];
	static string monthName[];
	void print();
	void setDay(int day)  // Constructor for the DayOfYear class.
	{
		this->day = day;
	}
};

DayOfYear::~DayOfYear()
{
    // DESTRUCTOR FOR THE STUDENT CLASS.
}

// Last day for each of the 12 months.
int DayOfYear::daysAtEndOfMonth[] = { 31, 59, 90, 120,
									  151, 181, 212, 243,
									  273, 304, 334, 365 };

// Name for each of the 12 months.
string DayOfYear::monthName[] = { "January", "February", "March", "April",
								  "May", "June", "July", "August",
								  "September", "October", "November", "December" };

// Function to print the day of the year in the month-day format that was requested.
void DayOfYear::print() {
	// VARIABLE DECLARATIONS
	const int NUMBER_OF_MONTHS = 12;
	int d = 0;  // Represents the remainder of days in month.

	for (int counter = 0; counter < NUMBER_OF_MONTHS; ++counter)
	{
		if (day <= daysAtEndOfMonth[counter])
		{
			if (counter == 0)
			{
				d = 0;
			}
			else
			{
				d = daysAtEndOfMonth[counter - 1];
			}
			
			cout << monthName[counter] << " " << (day - d) << endl;
			break;
		}
	}
}  // End of the print() function.

int main()
{	// Create new class object and variables.
	DayOfYear dayNumber;
	int userInput;
	const int RANGE_BASEMENT = 1;   // First day of year.
	const int RANGE_CEILING = 365;  // Last day of year.

	// Prompt user for an integer.
	cout << "Enter an integer between 1 and 365 to find the correlating date: ";
	cin >> userInput;

	while (userInput < RANGE_BASEMENT or userInput > RANGE_CEILING)  // Input validation.
	{
		cout << "\nThe integer must be between 1 and 365. Please try again.\n";
		cout << "\nEnter an integer between 1 and 365: ";
		cin >> userInput;
	}

	dayNumber.setDay(userInput);
	cout << endl;
	dayNumber.print();
	
	return 0;
}  // End of main method.

/*
				TEST DATA
		USER INPUT			OUTPUT
		1					January 1
		32					February 1
		365					December 31
*/