/* Exercise 05 from chapter 09.
 * Write a function called clockKeeper that takes as its argument a
 * dateAndTime structure. The function should call the dateUpdate function
 * to switch over to the next day. Have the function return the updated
 * dateAndTime structure.
 */

#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

struct time
{
    int hour;
    int minutes;
    int seconds;
};

struct dateAndTime
{
    struct date sdate;
    struct time stime;
};

struct date dateUpdate (struct date today)
{
    struct date tomorrow;
    int numberOfDays (struct date d);

    if ( today.day != numberOfDays (today) ) {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if ( today.month == 12 ) {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else {
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }

    return tomorrow;
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

// Function to update the time by one second

struct time timeUpdate (struct time now)
{
    ++now.seconds;

    if ( now.seconds == 60 ) {      // next minute
        now.seconds = 0;
        ++now.minutes;

        if ( now.minutes == 60 ) {  // next hour
            now.minutes = 0;
            ++now.hour;

            if ( now.hour == 24 )   // midnight
                now.hour = 0;
        }
    }

    return now;
}

bool isMidnight (struct time t)
{
    return t.hour == 0 && t.minutes == 0 && t.seconds == 0;
}

struct dateAndTime clockKeeper (struct dateAndTime dnt)
{ 
    struct date nextDay = dnt.sdate;
    struct time nextTime = timeUpdate (dnt.stime);
    struct dateAndTime nextDateAndTime;

    if ( isMidnight (nextTime) )
        nextDay = dateUpdate (dnt.sdate);

    return (struct dateAndTime) { nextDay, nextTime };
}

int main (void)
{
    struct date currentDay;
    struct time currentTime;
    struct dateAndTime currentDateAndTime, nextDateAndTime;

    printf ("Enter today's date (mm dd yyyy): ");
    scanf ("%i%i%i", &currentDay.month, &currentDay.day,
            &currentDay.year);

    printf ("Enter the time (hh:mm:ss): ");
    scanf ("%i:%i:%i", &currentTime.hour, &currentTime.minutes,
            &currentTime.seconds);

    currentDateAndTime = (struct dateAndTime) { currentDay, currentTime };
    nextDateAndTime = clockKeeper (currentDateAndTime);

    printf ("Updated date and time is %i/%i/%.2i %.2i:%.2i:%.2i\n",
            nextDateAndTime.sdate.month,
            nextDateAndTime.sdate.day,
            nextDateAndTime.sdate.year % 100,
            nextDateAndTime.stime.hour,
            nextDateAndTime.stime.minutes,
            nextDateAndTime.stime.seconds);

    return 0;
}
