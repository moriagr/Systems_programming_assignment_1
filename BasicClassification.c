#define TRUE 1
#define FALSE 0

int isPrime(int num)
{
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i != 0)
        {
            return FALSE;
        }
    }
    return TRUE;
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
        num = num / 10;
    }
    if (sum == num)
    {
        return TRUE;
    }
    return FALSE;
}