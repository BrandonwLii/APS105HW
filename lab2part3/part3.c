#include <stdio.h>
#include <math.h>

int main()
{
    // initialize variables
    const double k = 8.9875 * pow(10, 9);
    double q1, q2;
    char unit1, unit2;
    double r;

    double force;

    // get user input
    printf("Enter the value of the two charges separated by a space: ");
    scanf("%lf%cC %lf%cC", &q1, &unit1, &q2, &unit2);

    printf("Enter distance between charges in metres: ");
    scanf("%lf", &r);

    // unit conversion to C
    if (unit1 == 'u')
    {
        q1 *= pow(10, -6);
    }
    else
    {
        q1 *= pow(10, -9);
    }

    if (unit2 == 'u')
    {
        q2 *= pow(10, -6);
    }
    else
    {
        q2 *= pow(10, -9);
    }

    // calculate force
    force = fabs(k * q1 * q2 / (r * r));

    // identify unit and output force
    if (force < pow(10, -6))
    {
        force = rint(force * 100 * pow(10, 9)) / 100;
        printf("The force between charges is %.2lfnN (less than 1uN)\n", force);
    }
    else if (force < pow(10, -3))
    {
        force = rint(force * 100 * pow(10, 6)) / 100;
        printf("The force between charges is %.2lfuN (less than 1mN)\n", force);
    }
    else if (force < 1)
    {
        force = rint(force * 100 * pow(10, 3)) / 100;
        printf("The force between charges is %.2lfmN (less than 1uN)\n", force);
    }
    else
    {
        force = rint(force * 100) / 100;
        printf("The force between charges is %.2lfN (1N or greater)\n", force);
    }

    return 0;
}