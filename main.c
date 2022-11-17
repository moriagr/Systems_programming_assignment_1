#include "NumClass.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
// #include "advancedClassificationRecursion.c"
#include "advancedClassificationLoop.c"
#include "BasicClassification.c"

#define PATH_ "./self_check_hw1/inputs/"
#define NUM_IN_FILE 2

int main()
{
    char text_from_file;
    struct dirent *dir;
    DIR *d;
    FILE *in_file;
    d = opendir(PATH_);
    if (d)
    {
        // read file into array
        while ((dir = readdir(d)) != NULL)
        {
            char path[515];
            int number;

            sprintf(path, "%s%s", PATH_, dir->d_name);
            printf("%s\n", dir->d_name);
            in_file = fopen(path, "r");

            if (NULL == in_file)
            {
                break;
            }

            int numberArray[NUM_IN_FILE];
            int i;

            for (i = 0; i < NUM_IN_FILE; i++)
            {
                fscanf(in_file, "%d", &numberArray[i]);
            }

            // printf("%d\n", isPalindrome(64746));
            char armstrong_nums[numberArray[1]];
            char palindrome_nums[numberArray[1]];
            char prime_nums[numberArray[1]];
            char strong_nums[numberArray[1]];
            // Going all over the range of numbers
            for (number = numberArray[0]; number < numberArray[1]; number++)
            {
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

                // printf("Number is: %d\n", number);
            }
            printf("The Armstrong numbers are:%s\n", armstrong_nums);
            printf("The Palindromes are:%s\n", palindrome_nums);
            printf("The Prime numbers are:%s\n", prime_nums);
            printf("The Strong numbers are:%s\n",strong_nums );

            // Closing the file
            fclose(in_file);
        }
        closedir(d);
    }
    return 0;
}