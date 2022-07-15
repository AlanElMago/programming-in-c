/* Exercise 09 from chapter 08.
 * Write a function lcm that takes two integer arguments and returns their
 * lcm (Least Common Multiple).
 */

#include <stdio.h>

int gcd(int u, int v)
{
    int q = 0, r = 0;
    int tmp = 0;

    if (u < 0 || v < 0)
        return -1;

    if (u < v) {
        tmp = u;
        u = v;
        v = tmp;
    }

    while (v > 0) {
        tmp = u % v;
        u = v;
        v = tmp;
    }

    return u;
}

int lcm(int u, int v)
{
    if (u < 0 || v < 0)
        return -1;

    return u * v / gcd(u, v);
}

int main(void)
{
    printf("LCM(12, 18) = %i\n", lcm(12, 18));
    printf("LCM(25, 5) = %i\n", lcm(25, 5));
    printf("LCM(81, 231) = %i\n", lcm(81, 231));
}
