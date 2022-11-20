#include "NumClass.h"
#include <stdio.h>

#ifndef NUM_IN_FILE
#define NUM_IN_FILE 2
#endif

int main(int argc, char *argv[])
{
    int info;
    int numberArray[NUM_IN_FILE];
    int num_in_array = 0;
    while (scanf("%d", &info) == 1)
    {
        numberArray[num_in_array] = info;
        num_in_array = num_in_array + 1;
    }

    int armstrong_arr[numberArray[1]];
    int palindrome_arr[numberArray[1]];
    int prime_arr[numberArray[1]];
    int strong_arr[numberArray[1]];

    int armstrong_index = 0;
    int palindrome_index = 0;
    int prime_index = 0;
    int strong_index = 0;

    // Going all over the range of numbers
    int number;
    for (number = numberArray[0]; number <= numberArray[1]; number++)
    {
        if (isArmstrong(number))
        {
            armstrong_arr[armstrong_index] = number;
            armstrong_index++;
        }
        if (isPalindrome(number))
        {
            palindrome_arr[palindrome_index] = number;
            palindrome_index++;
        }
        if (isPrime(number))
        {
            prime_arr[prime_index] = number;
            prime_index++;
        }
        if (isStrong(number))
        {
            strong_arr[strong_index] = number;
            strong_index++;
        }
    }

    printf("The Armstrong numbers are:");
    for (number = 0; number < armstrong_index; number++)
    {
        printf(" %d", armstrong_arr[number]);
    }

    printf("\nThe Palindromes are:");
    for (number = 0; number < palindrome_index; number++)
    {
        printf(" %d", palindrome_arr[number]);
    }
    printf("\nThe Prime numbers are:");
    for (number = 0; number < prime_index; number++)
    {
        printf(" %d", prime_arr[number]);
    }
    printf("\nThe Strong numbers are:");
    for (number = 0; number < strong_index; number++)
    {
        printf(" %d", strong_arr[number]);
    }
    printf("\n");
    return 0;
}