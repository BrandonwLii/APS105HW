#include <stdio.h>

int main()
{
    // declare variables
    int temp;
    int threshold;

    const int water = 100;
    const int mercury = 357;
    const int copper = 1187;
    const int silver = 2193;
    const int gold = 2660;

    // get user input
    printf("Enter the threshold in Celsius: ");
    scanf("%d", &threshold);

    printf("Enter the observed boiling point in Celsius: ");
    scanf("%d", &temp);

    // determine substance & output
    if (temp > water - threshold && temp < water + threshold)
    {
        printf("The substance you tested is: Water\n");
    }
    else if (temp > mercury - threshold && temp < mercury + threshold)
    {
        printf("The substance you tested is: Mercury\n");
    }
    else if (temp > copper - threshold && temp < copper + threshold)
    {
        printf("The substance you tested is: Copper\n");
    }
    else if (temp > silver - threshold && temp < silver + threshold)
    {
        printf("The substance you tested is: Silver\n");
    }
    else if (temp > gold - threshold && temp < gold + threshold)
    {
        printf("The substance you tested is: Gold\n");
    }
    else
    {
        printf("Substance unknown.\n");
    }

    return 0;
}