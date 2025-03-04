#include <stdio.h>
#define ARRAY_SIZE 21

void printArray(int array[]){
    for(int i = 0;i<ARRAY_SIZE;i++){
        if(array[i] == 1){
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

void initializeArray(int aliveIndex, int array[]){
    for(int i = 0;i<ARRAY_SIZE;i++){
        array[i] = 0;
    }

    array[aliveIndex] = 1;
}

int getRuleOutcome(int rule, int left, int center, int right){
    int decimal = left * 4 + center * 2 + right;

    int bin[8] = {0};

    for(int i = 0; i <= 7; i++){
        bin[i] = rule % 2;
        rule /= 2;
    }

    return bin[decimal];
}

void calculateNextState(int currentArray[], int nextArray[], int rule){
    int left;
    int center;
    int right;

    for(int i = 0;i<ARRAY_SIZE;i++){
        if(i == 0){
            left = currentArray[20];
            center = currentArray[i];
            right = currentArray[i+1];
        }else if(i == 20){
            left = currentArray[i-1];
            center = currentArray[i];
            right = currentArray[0];
        }else{
            left = currentArray[i-1];
            center = currentArray[i];
            right = currentArray[i+1];
        }

        nextArray[i] = getRuleOutcome(rule, left, center, right);
    }
}

void simulateGenerations(int iterations, int array[], int rule){
    int nextArray[21] = {0};
    for(int i = 0;i<iterations;i++){
        printArray(array);
        calculateNextState(array, nextArray, rule);
        for(int i = 0;i<ARRAY_SIZE;i++){
            array[i] = nextArray[i];
        }
    }
}

int main(){
    int arr[21];
    int aliveIndex;
    int rule;
    int iterations;

    printf("Enter input: ");
    scanf("%d %d %d",&aliveIndex, &rule, &iterations);

    initializeArray(aliveIndex, arr);

    simulateGenerations(iterations, arr, rule);
}