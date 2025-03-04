#include <stdio.h>

int main(){
    //Initialize variables
    double price, cost;
    int donuts;
    int freeDonuts;
    
    //Number of donuts to get 1 free
    const int discountThreshold = 4;

    //Ask user for donut price
    printf("Enter the price per donut in CAD\n");
    scanf("%lf",&price);

    //Ask user for number of donuts
    printf("Enter the number of donuts\n");
    scanf("%d",&donuts);

    //Calculate number of free donuts
    //Casted into an int, truncates remainder
    freeDonuts = donuts / discountThreshold;

    //Output number of free donuts
    printf("You are getting %d free donut(s)\n", freeDonuts);

    //Calculate final cost
    cost = (donuts - freeDonuts) * price;
    cost = cost * 1.13;

    //Output final cost
    printf("You should pay $%.2lf\n",cost);

    return 0;
}