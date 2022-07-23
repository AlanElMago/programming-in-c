/* Exercise 01 from chapter 09.
 * Write a program that permits the user to type in two dates and then
 * calculates the number of elapsed days between the two dates.
 */

#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

int absolute_value(int n)
{
    if (n < 0)
        return -n;

    return n;
}

int date_to_days(struct date d)
{
    return 1461 * (d.year - 1 * (d.month <= 2)) / 4
            + 153 * (d.month + 1 + 12 * (d.month <= 2)) / 5 + d.day;
}

int dates_day_diff(struct date d1, struct date d2)
{
    return absolute_value(date_to_days(d1) - date_to_days(d2));
}

int main(void)
{
    struct date d1 = {21,  2, 2005}; // February 21, 2005
    struct date d2 = { 3,  8, 2004}; // August 3, 2004
    int diff;

    printf("Date 1 = %.2i/%.2i/%.4i\n", d1.day, d1.month, d1.year);
    printf("Date 2 = %.2i/%.2i/%.4i\n", d2.day, d2.month, d2.year);

    diff = dates_day_diff(d1, d2);
    
    printf("Difference between date 1 and date 2 = %i days.\n", diff);
}
