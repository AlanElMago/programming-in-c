/* Exercise 02 from chapter 14.
 * Write a function called month_name that takes as its argument a value of
 * type enum month (as defined in this chapter) and returns a pointer to a
 * character string containing the name of the month.
 */

#include <stdio.h>

enum month { january = 1, february, march, april, may, june, july, august,
        september, october, november, december };

char *name_of_months[13] = { "", "January", "February", "March", "April",
    "May", "June", "July", "August", "September", "October", "November",
    "December" };

char *month_name(enum month m)
{
    return *(name_of_months + (int) m);
}

int main(void)
{
    printf("%s\n", month_name(january));
    printf("%s\n", month_name(february));
    printf("%s\n", month_name(march));
    printf("%s\n", month_name(april));
    printf("%s\n", month_name(may));
    printf("%s\n", month_name(june));
    printf("%s\n", month_name(july));
    printf("%s\n", month_name(august));
    printf("%s\n", month_name(september));
    printf("%s\n", month_name(october));
    printf("%s\n", month_name(november));
    printf("%s\n", month_name(december));

    return 0;
}
