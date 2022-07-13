/* Exercise 03 from chapter 08.
 * Modify Program 8.8 so that the value of epsilon is passed as an argument to
 * the function.
 */
# include <stdio.h>

float absoluteValue (float x)
{
    if ( x < 0 )
        x = -x;

    return (x);
}


// Function to compute the square root of a number

float squareRoot (float x, float epsilon)
{
    float guess   = 1.0;

    while ( absoluteValue (guess * guess - x) >= epsilon )
        guess = ( x / guess + guess ) / 2.0;

    return guess;
}


int main (void)
{
    printf ("squareRoot (17.0, 1.0) = %f\n", squareRoot (17.0f, 1.0f));
    printf ("squareRoot (17.0, 0.1) = %f\n", squareRoot (17.0f, 0.1f));
    printf ("squareRoot (17.0, 0.01) = %f\n", squareRoot (17.0f, 0.01f));
    printf ("squareRoot (17.0, 0.001) = %f\n", squareRoot (17.0f, 0.001f));
    printf ("squareRoot (17.0, 0.0001) = %f\n", squareRoot (17.0f, 0.0001f));
    printf ("squareRoot (17.0, 0.00001) = %f\n", squareRoot (17.0f, 0.00001f));

    return 0;
}
