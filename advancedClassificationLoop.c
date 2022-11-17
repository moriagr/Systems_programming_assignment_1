#include <NumClass.h>

#define TRUE 1
#define FALSE 0

int isArmstrong(int num)
{
    int changed_num = num;
    int len = 0;
    int short_num = changed_num;
    while (short_num != 0)
    {
        len = len + 1;
        short_num = short_num / 10;
    }

    int sum = 0;
    int mul;
    while (changed_num != 0)
    {
        mul = changed_num % 10;
        int strong = 1;
        for (int i = 0; i < len; i++)
        {
            strong = strong * mul;
        }
        sum = sum + strong;
        changed_num = changed_num / 10;
    }
    if (sum == num)
    {
        return TRUE;
    }
    return FALSE;
}

int isPalindrome(int num)
{
    int changed_num = num;
    int reversed_num = 0;
    while (changed_num != 0)
    {
        reversed_num = (reversed_num * 10) + (changed_num % 10);
        changed_num = changed_num / 10;
    }

    if (num == reversed_num)
    {
        return TRUE;
    }
    return FALSE;
}