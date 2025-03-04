#include <stdio.h>
#include <math.h>

int main()
{
    // initialize variables
    const double v = 20;
    const double y0 = 2;
    double yf;

    const double pi = 3.1415;
    const double g = 9.81;

    double d;
    double h;
    double t;

    double angle;

    // get and validate user input
    do
    {
        printf("Please enter the horizontal distance from the wall between 3 and 30 m:\n");
        scanf("%lf", &d);
    } while (d < 3 || d > 30);

    do
    {
        printf("Please enter the target height between 3 and 6 m:\n");
        scanf("%lf", &h);
    } while (h < 3 || h > 6);

    // calculate angle
    for (angle = 0; angle < 91; angle++)
    {
        t = d / (v * cos(angle * pi / 180));
        yf = y0 + v * sin(angle * pi / 180) * t - g * t * t / 2;

        if (fabs(yf - h) <= 0.3)
        {
            printf("The angle should be %.2lf\n", angle);
            break;
        }
    }

    return 0;
}