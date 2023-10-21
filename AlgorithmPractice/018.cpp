// ATM 인출 시간 계산하기 (11399)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void)
{
    int N;
    int A[1000];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    bool changed = false;
    for (int i = 0; i < N - 1; i++)
    {
        changed = false;
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                changed = true;
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
        if (changed == false)
            break;
    }

    int sum = A[0];
    int total = sum;
    for (int i = 1; i < N; i++)
    {
        sum += A[i];
        total += sum;
    }

    printf("%d\n", total);
    return 0;
}