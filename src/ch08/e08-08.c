/* Exercise 08 from chapter 08.
 * Write a program to solve a quadratic equation of the form ax² + bx + c = 0.
 */

# include <stdio.h>

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

int main (void)
{
    double a = 0, b = 0, c = 0;
    double discriminant = 0;
    double x1 = 0, x2 = 0;

    printf("Input coefficient a: ");
    scanf("%lf", &a);
    printf("Input coefficient b: ");
    scanf("%lf", &b);
    printf("Input coefficient c: ");
    scanf("%lf", &c);

    discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        printf("The roots are complex.\n");

        return 1;
    }

    x1 = (-b - squareRoot(discriminant)) / (2 * a);
    x2 = (-b + squareRoot(discriminant)) / (2 * a);

    if (x1 == x2) {
        printf("The solution has 1 root:\n");
        printf("x = %f\n", x1);

        return 0;
    }

    printf("The solution has 2 roots:\n");
    printf("x1 = %f    x2 = %f\n", x1, x2);

    return 0;
}
