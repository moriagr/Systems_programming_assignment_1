#include <NumClass.h>

int isPrime(int num)
{
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i != 0)
        {
            return 0;
        }
    }
    return 1;
}

int isStrong(int num)
{
    int sum;
    int single_digit;
    while (num != 0)
    {
        single_digit = num % 10;
        int strong = 1;
        for (int i = 2; i <= single_digit; i++)
        {
            strong = strong * i;
        }
        sum = sum + strong;
    }
    return sum;
}