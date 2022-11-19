#include "NumClass.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
// #include "advancedClassificationRecursion.c"
// #include "advancedClassificationLoop.c"
// #include "BasicClassification.c"

#define NUM_IN_FILE 2

int main(int argc, char *argv[])
{
    int i;
    int numberArray[NUM_IN_FILE];
    int count = 0;
    while (scanf("%d", &i) == 1)
    {
        numberArray[count] = i;
        count = count + 1;
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
        // const char* char_number = (const char*)number;
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