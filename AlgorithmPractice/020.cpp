// 수 정렬하기2 (2751)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

int main(void)
{
    int N;
    int* A = new int[1000000];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    std::sort(A, A + N);

    for (int i = 0; i < N; i++)
        printf("%d\n", A[i]);
    return 0;
}