#include <stdio.h>

int main(){
    //Initialize variables
    double cm;

    int feet;
    double inches;

    //Get user input
    printf("Enter the length in centimeters (cm)\n");
    scanf("%lf",&cm);

    //Calculate output
    inches = cm/2.54;
    feet = inches/12;
    inches = inches - feet * 12;

    //Output inches
    printf("The length is %dft %din\n", feet, (int) inches);
}