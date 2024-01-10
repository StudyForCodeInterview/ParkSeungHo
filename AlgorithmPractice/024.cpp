// 신기한 소수 찾기 (2023)
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//int g_arr[8];
//int g_N;
//
//bool IsPrimeNumber(int n);
//void IsWonderfulPrimeNumber(int num, int depth);
//
//int main(void)
//{
//    int num = 1;
//    scanf("%d", &g_N);
//    IsWonderfulPrimeNumber(2, 1);
//    return 0;
//}
//
//bool IsPrimeNumber(int n)
//{
//    if (n == 2 || n == 3)
//        return true;
//    if (n % 2 == 0)
//        return false;
//    for (int i = 3; i * i <= n; i += 2)
//    {
//        if (n % i == 0)
//            return false;
//    }
//    return true;
//}
//void IsWonderfulPrimeNumber(int num, int length)
//{
//    int base = 1;
//    if (length > g_N)
//        return;
//    for (int i = 0; i < length; i++)
//        base*= 10;
//    for (int i = 0; i < 10; i++)
//    {
//        if ((num + i) / base >= 1)
//            continue;
//        if (IsPrimeNumber(num + i))
//        {
//            IsWonderfulPrimeNumber((num + i) * 10, length + 1);
//            if (length == g_N)
//                printf("%d\n", num + i);
//        }
//    }
//}

#include <iostream>
#include <vector>
using namespace std;

void func(int totalNum, int len, int addNum, int maxLen);
bool IsPrime(int n)
{
    if (n == 2)
        return true;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main(void)
{
    int N;
    int arr[4] = { 2, 3, 5, 7 };

    cin >> N;

    for (int i : arr)
    {
        func(0, 0, i, N);
    }

    return 0;
}

void func(int totalNum, int len, int addNum, int maxLen)
{
    totalNum = totalNum * 10 + addNum;
    len++;
    if (IsPrime(totalNum))
    {
        if (len == maxLen)
        {
            cout << totalNum << endl;
            return;
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                func(totalNum, len, i, maxLen);
            }
        }
    }
}