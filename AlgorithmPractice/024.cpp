// 신기한 소수 찾기 (2023)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int g_arr[8];
int g_N;

bool IsPrimeNumber(int n);
void IsWonderfulPrimeNumber(int num, int depth);

int main(void)
{
    int num = 1;
    scanf("%d", &g_N);
    IsWonderfulPrimeNumber(2, 1);
    return 0;
}

bool IsPrimeNumber(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void IsWonderfulPrimeNumber(int num, int length)
{
    int base = 1;
    if (length > g_N)
        return;
    for (int i = 0; i < length; i++)
        base*= 10;
    for (int i = 0; i < 10; i++)
    {
        if ((num + i) / base >= 1)
            continue;
        if (IsPrimeNumber(num + i))
        {
            IsWonderfulPrimeNumber((num + i) * 10, length + 1);
            if (length == g_N)
                printf("%d\n", num + i);
        }
    }
}