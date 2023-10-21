// 버블정렬 (2750)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void)
{
    int A[1000];
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int tmp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = tmp;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", A[i]);
    }
    return 0;
}