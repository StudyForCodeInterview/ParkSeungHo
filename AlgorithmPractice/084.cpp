// 정수를 1로 만들기 (1463)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int num;
    int i;
    int* D = new int[1000001];
    D[0] = D[1] = 0;
    scanf("%d", &num);

    for (i = 2; i <= num; i++)
    {
        D[i] = D[i - 1];
        if (i % 3 == 0)
            D[i] = min(D[i], D[i / 3]);
        if (i % 2 == 0)
            D[i] = min(D[i], D[i / 2]);
        D[i] += 1;
    }

    printf("%d\n", D[num]);
    return 0;
}