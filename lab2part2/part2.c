#include <stdio.h>
#include <math.h>

int main()
{
    // initialize variables
    int input;
    int output = 0;

    int first, second, third, last;

    // get coded message
    printf("Enter an encrypted 4-digit combination: ");
    scanf("%d", &input);

    // apply encryption scheme
    first = input / 1000;
    second = input / 100 % 10;
    third = input / 10 % 10;
    last = input % 10;

    output = 0;
    output += first;
    output += (9 - third) * 10;
    output += (9 - second) * 100;
    output += last * 1000;

    printf("\nThe real combination is: %d\n", output);

    return 0;
}