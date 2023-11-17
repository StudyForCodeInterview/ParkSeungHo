// ÃÖ¼Ú°ª Ã£±â 2 (10868) ???
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long> arr;

long GetValue(int startIndex, int endIndex);
int main(void)
{
    int N, M;
    int a, b;
    int i;
    int num = 1;
    int exponent = 0;
    int startIndex;
    int tmp;

    scanf("%d %d", &N, &M);
    while (1)
    {
        if (num >= N)
            break;
        num *= 2;
        exponent++;
    }
    num *= 2;
    arr.resize(num, 2147483647L);
    startIndex = num / 2;

    for (i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        arr[startIndex + i] = tmp;
    }

    num--;
    num /= 2;
    while (num != 0)
    {
        if (arr[num * 2] < arr[num * 2 + 1])
            arr[num] = arr[num * 2];
        else
            arr[num] = arr[num * 2 + 1];
        num--;
    }




    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%ld\n", GetValue(startIndex - 1 + a, startIndex - 1 + b));
    }
    return 0;
}

long GetValue(int startIndex, int endIndex)
{
    long min = LONG_MAX;

    while (startIndex <= endIndex)
    {
        if (startIndex % 2 == 1)
        {
            min = std::min(min, arr[startIndex++]);
            if (min < ) !!!
        }
        startIndex /= 2;

        if (endIndex % 2 == 0)
        {
            min = std::min(min, arr[endIndex--]);
        }
        endIndex /= 2;
        
        if (startIndex == 0 || endIndex == 0)
            break;
    }
    return min;
}