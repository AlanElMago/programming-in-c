/* Exercise 04 from chapter 08.
 * Modify Program 8.8 so that the value of guess is printed each time through
 * the while loop.
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
    const float epsilon = .00001;
    float       guess   = 1.0;
    int         iter    = 0;

    while ( absoluteValue (guess * guess - x) >= epsilon ) {
        iter++;
        guess = ( x / guess + guess ) / 2.0;
        printf ("Iteration %d: %f\n", iter, guess);
    }

    return guess;
}


int main (void)
{
    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0));
    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0));
    printf ("squareRoot (17.5) = %f\n", squareRoot (17.5));

    return 0;
}
