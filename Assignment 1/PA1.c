/* PA1.c  -- Jack Palmstrom */

#include <stdio.h>


	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char *months[] = {
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};

//----------------------- User inputs a given year ----------------------------------//
int givenYear(void) {
	
	int inputYear;
	printf("Please input a non-negative year number:-\n");
	scanf("%d", &inputYear);
	return inputYear;
} // ends givenYear

//--------------------- Calculating the startingDay ---------------------------------//
int startingDay(int inputYear) {	
	int day;
	int d1, d2, d3;
	
	d1 = (inputYear - 1.0) / 4.0;
	d2 = (inputYear - 1.0) / 100.0;
	d3 = (inputYear - 1.0) / 400.0;
	day = (inputYear + d1 - d2 + d3) % 7;
	return day;	
} // ends startingDay

//----------------------- Determines if leap year -----------------------------------//
int isLeapYear(int inputYear) {
	if((inputYear % 4 == 0 && inputYear % 100 != 0) || inputYear % 400 == 0) {
		daysInMonth[2] = 29; // Sets February to have 29 days
		return 1;
	}
	else {
		daysInMonth[2] = 28; // Sets February to have 28 days
		return 0;
	}
} // ends isLeapYear


//--------------------------------- Calendar ----------------------------------------//
void calendar(int inputYear, int day) {
	
	int month, date;

	for(month = 1; month <= 12; month++) {
		
		printf("%s", months[month]);                       //month name
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n"); //days of week

		for(date= 1; date <= 1 + day * 5; date++) {
			printf(" ");
		}
		// Print dates in a month
		for(date = 1; date <= daysInMonth[month]; date++) {
			
			printf("%2d", date);
			
			if ((date + day) % 7 > 0) {
				printf("   ");
			}
			else {
				printf("\n ");
			}
		} // for date
		
		// Set starting day for next month
		day = (day + daysInMonth[month]) % 7;

	} // for month
} // ends calendar

//--------------------------------- Main --------------------------------------------//
int main(void)
{
	int inputYear, day; 
	
	inputYear = givenYear();
	day = startingDay(inputYear);
	isLeapYear(inputYear);
	calendar(inputYear, day);
	printf("\n");
} // int main(void)


