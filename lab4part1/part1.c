#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double randDouble() {
    return (double)rand() / ((double)RAND_MAX);
}

bool inBounds(double x, double y) {
    return (x * x + y * y <= 1);
}

int main() {

    srand(42);

    //initialize variables
    int iterations;
    int successes = 0;

    double piEstimate;

    //get user input
    printf("Number of monte carlo iterations: ");
    scanf("%d",&iterations);

    //run iterations
    for(int i = 0; i < iterations; i++){
        if(inBounds(randDouble(), randDouble())){
            successes++;
        }
    }

    //calculate pi
    piEstimate = 4.0 * (double) successes / (double) iterations;

    //output pi estimate
    printf("Pi: %.4lf\n", piEstimate);

    return 0;
}
