#define TRUE 1
#define FALSE 0

int isArmstrong(int num)
{
    int len = 0;
    int short_num = num;
    while (short_num != 0)
    {
        len = len + 1;
        short_num = short_num / 10;
    }

    int sum = 0;
    int mul;
    while (num != 0)
    {
        len = len + 1;
        mul = num % 10;
        int strong = 1;
        for (int i = 0; i < len; i++)
        {
            strong = strong * mul;
        }
        sum = sum + strong;
    }

    if (sum == num)
    {
        return TRUE;
    }
    return FALSE;
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
        return TRUE;
    }
    return FALSE;
}