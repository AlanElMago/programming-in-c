/* Exercise 11 from chapter 11.
 * Given the definition of a date structure as defined in this chapter, write
 * a function called dateUpdate that takes a pointer to a date structure as
 * its argument and that updates the structure to the following day.
 */

#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

void dateUpdate (struct date *today)
{
    struct date tomorrow;
    int numberOfDays (struct date d);

    if ( today->day != numberOfDays (*today) ) {
        tomorrow.day = today->day + 1;
        tomorrow.month = today->month;
        tomorrow.year = today->year;
    }
    else if ( today->month == 12 ) {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today->year + 1;
    }
    else {
        tomorrow.day = 1;
        tomorrow.month = today->month + 1;
        tomorrow.year = today->year;
    }

    *today = tomorrow;
}

// Function to find the number of days in a month

int numberOfDays (struct date d)
{
    int days;
    bool isLeapYear (struct date d);
    const int daysPerMonth[12] =
            { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ( isLeapYear (d) == true && d.month == 2 )
        days = 29;
    else
        days = daysPerMonth[d.month - 1];

    return days;
}

bool isLeapYear (struct date d)
{
    bool leapYearFlag;

    if ( (d.year % 4 == 0 && d.year % 100 != 0) ||
            d.year % 400 == 0 )
        leapYearFlag = true;    // It's a leap year
    else
        leapYearFlag = false;   // Not a leap year

    return leapYearFlag;
}

int main (void)
{
    void dateUpdate (struct date *today);
    struct date thisDay;

    printf ("Enter today's date (mm dd yyyy): ");
    scanf ("%i%i%i", &thisDay.month, &thisDay.day,
            &thisDay.year);

    dateUpdate (&thisDay);

    printf ("Tomorrow's date is %i/%i/%.2i.\n", thisDay.month,
            thisDay.day, thisDay.year % 100);

    return 0;
}
