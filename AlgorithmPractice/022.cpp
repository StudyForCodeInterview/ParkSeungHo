// 기수 정렬 O(kN) k는 데이터의 자릿수
// 수 정렬하기 3 (10989)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void)
{
    int N;
    int tmp;
    int A[10001] = { 0, };

    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        A[tmp]++;
    }


    for (int i = 1; i <= 10000; i++)
    {
        if (A[i] != 0)
        {
            for (int j = 0; j < A[i]; j++)
                printf("%d\n", i);
        }
    }
    return 0;
}