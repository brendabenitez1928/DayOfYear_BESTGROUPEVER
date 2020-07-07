/*
 *Group Project participants: Austin, Nick, Brogan, Brenda
 *Each person in the group designed their own code and we collaborated to create the final project
 */


#include <iostream>
using namespace std;

//Initialize Class 
class DayOfYear {
private:
	int day;
public:
	static int daysAtEndOfMonth[];
	static string monthName[];
	void print();
	void setDay(int day){this->day = day;}
};
//define array containing days at the end of each month 
int DayOfYear::daysAtEndOfMonth[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

//define array containing each months name in order
string DayOfYear::monthName[] = {"January", "February", "March", "April", "May", "June", "July", 
"August", "September", "October", "November", "December"};

//print function
void DayOfYear::print() 
{
	int d;//remainder of days in month
	for (int i = 0; i < 12; ++i) 
	{
		if (day <= daysAtEndOfMonth[i])
		{
			if (i == 0)//initialize remainder days 0 if in the first month
			{
				d = 0;
			}
			else//subtract previous month(s) total from input number
			{
				d = daysAtEndOfMonth[i - 1];
			}
			//output correlating month and day
			cout << monthName[i] << " " << day - d << endl;
			return;
		}
	}
}


int main()
{	//create new object and variable
	DayOfYear dayNumber;
	int inputDay;
	
	//prompt user for number 
	cout << "Enter number between 1 & 365 to find the correlating date: ";
	cin >> inputDay;
	while (inputDay < 1 or inputDay > 365)//input validation
	{
		cout << "Invalid input. Please try again." << endl;
		cout << "Enter a number between 1 & 365: ";
		cin >> inputDay;
	}
	dayNumber.setDay(inputDay);
	dayNumber.print();
	return 0;
}