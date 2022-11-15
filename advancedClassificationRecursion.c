int isArmstrong(int num)
{
}

int isPalindromeReverse(int num1, int num2)
{
    if (num1 == 0)
    {
        return num2;
    }
    isPalindromeReverse((num1 / 10), ((num2 * 10) + (num1 % 10)));
}

int isPalindrome(int num)
{
    int reversed_num = isPalindromeReverse(num, 0);
    if (num == reversed_num)
    {
        return 1;
    }
    return 0;
}

