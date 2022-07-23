/* Exercise 03 from chapter 09.
 * Write a function elapsed_time that takes as its arguments two time
 * structures and returns a atime structure that represents the elapsed time
 * (in hours, minutes, and seconds) between the two times.
 */

#include <stdio.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};

int time_to_seconds(struct time t)
{
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

struct time seconds_to_time(int s)
{
    int hours = s / 3600;
    int minutes = (s - hours * 3600) / 60;
    int seconds = s % 60;
    
    return (struct time) {hours, minutes, seconds};
}

struct time elapsed_time(struct time t1, struct time t2)
{
    int seconds1 = time_to_seconds(t1);
    int seconds2 = time_to_seconds(t2);
    int diff;

    if (seconds1 > seconds2)
        diff = 86400 - seconds1 + seconds2;
    else
        diff = seconds2 - seconds1;

    return seconds_to_time(diff);
}

int main(void)
{
    struct time t1 = {  3, 45, 15 };
    struct time t2 = {  9, 44,  3 };
    struct time elapsed = elapsed_time(t1, t2);

    printf("Time 1 = %.2i:%.2i:%.2i\n", t1.hours, t1.minutes, t1.seconds);
    printf("Time 2 = %.2i:%.2i:%.2i\n", t2.hours, t2.minutes, t2.seconds);

    printf("Elapsed time between time 1 and time 2 = %ih %im %is\n\n",
            elapsed.hours, elapsed.minutes, elapsed.seconds);

    t1 = (struct time) {  8, 43,  2 };
    t2 = (struct time) {  2, 44, 14 };
    elapsed = elapsed_time(t1, t2);

    printf("Time 1 = %.2i:%.2i:%.2i\n", t1.hours, t1.minutes, t1.seconds);
    printf("Time 2 = %.2i:%.2i:%.2i\n", t2.hours, t2.minutes, t2.seconds);

    printf("Elapsed time between time 1 and time 2 = %ih %im %is\n",
            elapsed.hours, elapsed.minutes, elapsed.seconds);

    return 0;
}
