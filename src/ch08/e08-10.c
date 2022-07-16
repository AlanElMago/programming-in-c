/* Exercise 10 from chapter 08.
 * Write a function called prime that returns 1 if its argument is a prime
 * number and returns 0 otherwise.
 */

#include <stdio.h>

double absoluteValue (double x)
{
    if ( x < 0 )
        x = -x;

    return (x);
}

double squareRoot (double x)
{
    const double epsilon = .00001;
    double       guess   = 1.0;

    while ( absoluteValue (guess * guess - x) >= epsilon )
        guess = ( x / guess + guess ) / 2.0;

    return guess;
}

int prime(int n)
{
    if (n <= 1)
        return 0;

    if (n == 2)
        return 1;

    int upper_bound = (int) squareRoot(n);

    for (int i = 3; i <= upper_bound; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    printf("Is 1 a prime number? %s\n", prime(1) == 1 ? "True" :"False");
    printf("Is 2 a prime number? %s\n", prime(2) == 1 ? "True" :"False");
    printf("Is 3 a prime number? %s\n", prime(3) == 1 ? "True" :"False");
    printf("Is 51 a prime number? %s\n", prime(51) == 1 ? "True" :"False");
    printf("Is 421 a prime number? %s\n", prime(421) == 1 ? "True" :"False");
    printf("Is 1217 a prime number? %s\n", prime(1217) == 1 ? "True" :"False");
    printf("Is 1219 a prime number? %s\n", prime(1219) == 1 ? "True" :"False");

    return 0;
}
