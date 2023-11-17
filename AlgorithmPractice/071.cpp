// 구간합 구하기 (세그먼트 트리 2042)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<long> arr;

void SetValue(int index, long value);
long GetValue(int startIndex, int endIndex);

int main(void)
{
    int i;
    int N, M, K;
    long a, b, c;
    long num = 1;
    int exponent = 0;
    int startIndex;
    long tmp;

    scanf("%d %d %d", &N, &M, &K);
    while (1)
    {
        if (num >= N)
            break;
        num *= 2;
        exponent++;
    }
    num *= 2;
    arr.resize(num);
    startIndex = num / 2;

    for (i = 0; i < N; i++)
    {
        scanf("%ld", &tmp);
        arr[startIndex + i] = tmp;
    }

    num--;
    while (num != 1)
    {
        arr[num / 2] += arr[num];
        num--;
    }


    for (i = 0; i < M + K; i++)
    {
        scanf("%ld %ld %ld", &a, &b, &c);
        if (a == 1)
        {
            // b번째 수를 c로 바꿈.
            SetValue(startIndex - 1 + b, c);
        }
        else
        {
            // b번째 수부터 c번째 수까지 합을 구함.
            printf("%ld\n", GetValue(startIndex - 1 + b, startIndex - 1 + c));
        }
    }
    return 0;
}

void SetValue(int index, long value)
{
    long diff = value - arr[index];

    while (index > 0)
    {
        arr[index] += diff;
        index /= 2;
    }
}

long GetValue(int startIndex, int endIndex)
{
    long sum = 0;

    while (startIndex <= endIndex)
    {
        if (startIndex % 2 == 1)
        {
            sum += arr[startIndex++];
        }
        if (endIndex % 2 == 0)
        {
            sum += arr[endIndex--];
        }
        startIndex /= 2;
        endIndex /= 2;
    }

    return sum;
}