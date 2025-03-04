#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    //ini variables
    int input;
    int luckyCount;
    int totalCount = 0;

    //get first input
    printf("Input an integer: ");
    scanf("%d",&input);

    //lucky number loop;
    while (input != 0){
        

        //check for magic number
        luckyCount = 0;

        //exits if original input is 0 or out of digits
        while(input != 0){

            //increments counter if last digit is 3
            if(input % 10 == 7) luckyCount++;

            //next digit
            input /= 10;

        }

        //increments counter if number is lucky
        if(luckyCount >= 3) totalCount++;

        printf("Input an integer (0 to stop): ");
        scanf("%d",&input);
    } 

    //output number of lucky numbers
    printf("You entered %d lucky number(s)!\n", totalCount);

    return 0;
}
