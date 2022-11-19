#include "NumClass.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
// #include "advancedClassificationRecursion.c"
#include "advancedClassificationLoop.c"
#include "BasicClassification.c"

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

    // read file into array
    char armstrong_nums[numberArray[1]];
    char palindrome_nums[numberArray[1]];
    char prime_nums[numberArray[1]];
    char strong_nums[numberArray[1]];

    // Going all over the range of numbers
    int number;
    for (number = numberArray[0]; number <= numberArray[1]; number++)
    {
        // const char* char_number = (const char*)number;
        if (isArmstrong(number))
        {
            sprintf(armstrong_nums, "%s %d", armstrong_nums, number);
        }
        if (isPalindrome(number))
        {
            sprintf(palindrome_nums, "%s %d", palindrome_nums, number);
        }
        if (isPrime(number))
        {
            sprintf(prime_nums, "%s %d", prime_nums, number);
        }
        if (isStrong(number))
        {
            sprintf(strong_nums, "%s %d", strong_nums, number);
        }
    }

    printf("The Armstrong numbers are:%s\n", armstrong_nums);
    printf("The Palindromes are:%s\n", palindrome_nums);
    printf("The Prime numbers are:%s\n", prime_nums);
    printf("The Strong numbers are:%s\n", strong_nums);
    return 0;
}