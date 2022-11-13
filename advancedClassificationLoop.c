#include "NumClass.h"

int isArmstrong(int num)
{
}

int isPalindrome(int num)
{
    int reversed_num = 0;
    while (num != 0)
    {
        reversed_num = (reversed_num * 10) + (num % 10);
        num = num / 10;
    }

    if (num == reversed_num)
    {
        return 1;
    }
    return 0;
}