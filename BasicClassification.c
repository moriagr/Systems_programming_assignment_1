#define TRUE 1
#define FALSE 0

int isPrime(int num)
{
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

int isStrong(int num)
{
    int sum = 0;
    int single_digit;
    int changed_num = num;
    while (changed_num != 0)
    {
        single_digit = changed_num % 10;
        int strong = 1;
        for (int i = 2; i <= single_digit; i++)
        {
            strong = strong * i;
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