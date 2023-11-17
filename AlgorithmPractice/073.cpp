// 구간곱 구하기 (11505)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long> arr;
long GetValue(int startIndex, int endIndex);
void SetValue(int index, long value);

int main(void)
{
    int N, M, K;
    int a, b, c;
    int i;
    int num = 1;
    int tmp;
    int exponent = 1;
    int startIndex;

    scanf("%d %d %d", &N, &M, &K);
    while (1)
    {
        if (num >= N)
            break;
        num *= 2;
        exponent++;
    }
    num *= 2;
    arr.resize(num, 1);
    startIndex = num / 2;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        arr[startIndex + i] = tmp;
    }

    // MakeTree()
    num--;
    while (num != 1)
    {
        arr[num / 2] = (arr[num / 2] * arr[num]) % 1000000007;
        num--;
    }

    for (i = 0; i < M + K; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1)
        {
            // b번째 수를 c로 변경.
            SetValue(startIndex - 1 + b, c);
        }
        else
        {
            // b부터 c까지 곱 출력
            printf("%ld\n", GetValue(startIndex - 1 + b, startIndex - 1 + c) % 1000000007);
        }
    }
    return 0;
}

long GetValue(int startIndex, int endIndex)
{
    long sum = 1;

    while (startIndex <= endIndex)
    {
        if (startIndex % 2 == 1) // select
        {
            sum = (sum * arr[startIndex++]) % 1000000007;
        }
        startIndex /= 2;

        if (endIndex % 2 == 0)  // select
        {
            sum = (sum * arr[endIndex--]) % 1000000007;
        }
        endIndex /= 2;
    }
    return sum;
}

void SetValue(int index, long value)
{
    arr[index] = value;
    index /= 2;
    while (index >= 1)
    {
        arr[index] = (arr[index * 2] * arr[index * 2 + 1]) % 1000000007;
        index /= 2;
    }
}
