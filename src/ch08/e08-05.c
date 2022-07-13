/* Exercise 05 from chapter 08.
 * Modify Program 8.8 so that it compares the ratio of guess² and x instead
 * of its difference. The closer this ratio gets to 1 the more accurate the
 * approximation of the square root.
 */

# include <stdio.h>

float absoluteValue (float x)
{
    if ( x < 0 )
        x = -x;

    return (x);
}


// Function to compute the square root of a number

float squareRoot (float x)
{
    float epsilon = 0.00001;
    float guess = 1.0;

    while ( absoluteValue((guess * guess / x) - 1.0) >= epsilon )
        guess = ( x / guess + guess ) / 2.0;

    return guess;
}


int main (void)
{
    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0));
    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0));
    printf ("squareRoot (17.5) = %f\n", squareRoot (17.5));

    return 0;
}
