#include <stdio.h>

int main()
{
    // initialize variables
    int depositAmt;

    int hundred = 0;
    int fifty = 0;
    int twenty = 0;
    int ten = 0;
    int five = 0;

    // get user input
    printf("Please enter an amount in dollars ($): ");
    do
    {
        scanf("%d", &depositAmt);

        if (depositAmt % 5 != 0)
        {
            printf("The amount should be a multiple of $5: ");
        }
    } while (depositAmt % 5 != 0);

    // calculate output
    hundred = depositAmt / 100;
    depositAmt -= 100 * hundred;

    fifty = depositAmt / 50;
    depositAmt -= 50 * fifty;

    twenty = depositAmt / 20;
    depositAmt -= 20 * twenty;

    ten = depositAmt / 10;
    depositAmt -= 10 * ten;

    five = depositAmt / 5;
    depositAmt -= 5 * five;

    // output
    if (hundred != 0)
    {
        printf("$100: %d\n", hundred);
    }
    if (fifty != 0)
    {
        printf("$50: %d\n", fifty);
    }
    if (twenty != 0)
    {
        printf("$20: %d\n", twenty);
    }
    if (ten != 0)
    {
        printf("$10: %d\n", ten);
    }
    if (five != 0)
    {
        printf("$5: %d\n", five);
    }
    return 0;
}
