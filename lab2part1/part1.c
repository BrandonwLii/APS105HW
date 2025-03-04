#include <stdio.h>
#include <math.h>

int main(){
    //initialize variables
    const double G = 6.6726*pow(10,-11);
    const double pi = 3.14159265359;
    double circumference;
    double a;

    double radius,mass,velocity;
    
    //get circumference 
    printf("Circumference (km) of planet: ");
    scanf("%lf",&circumference);

    //get acceleration
    printf("Acceleration due to gravity (m/s^2) on planet: ");
    scanf("%lf",&a);

    //formatting
    printf("\n");

    //calculate radius, mass, velocity
    radius = circumference/2;
    radius /= pi;

    //convert km to m
    radius *= 1000;

    mass = a*radius*radius/G;

    velocity = sqrt(2*G*mass/(radius));

    //format values for output
    //convert m to km
    radius /= 1000;
    radius = rint(radius*10)/10;

    //10^21 kg
    mass = mass / pow(10,21);
    mass = rint(mass*10)/10;

    //convert m/s to km/s
    velocity /= 1000;
    velocity = rint(velocity*10)/10;

    //output values
    printf("Calculating the escape velocity...\n");
    printf("Planet radius: %.1lf km\n",radius);
    printf("Planet mass: %.1lf x 10^21 kg\n",mass);
    printf("Escape velocity: %.1lf km/s\n",velocity);
    
    return 0;
}