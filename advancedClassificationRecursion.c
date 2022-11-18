#include <math.h>
#include "NumClass.h"

#define TRUE 1
#define FALSE 0

// Utility function
int numOfDigits(int x){
    if (x / 10 == 0){
        return 1;
    }
    else{
        return 1 + numOfDigits(x / 10);
    }
}

// Utility function
int calcSum(int x, int n){
    if (x / 10 == 0){
        return (int)pow(x, n);
    }
    else{
        return (int)(pow(x % 10, n)) + calcSum(x / 10, n);
    }
}

int isArmstrong(int x){
    int n = numOfDigits(x);
    if (calcSum(x, n) == x){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

// Utility function
int reversedNum(int num1, int num2){
    if (num1 == 0){
        return num2;
    }
    return reversedNum((num1 / 10), ((num2 * 10) + (num1 % 10)));
}

int isPalindrome(int num){
    int reversed_num = isPalindromeReverse(num, 0);
    if (num == reversed_num){
        return TRUE;
    }
    return FALSE;
}
