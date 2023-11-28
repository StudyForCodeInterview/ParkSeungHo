// 계단 수 구하기 (10844)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// D[N][0]은 길이가 N이고 0으로 끝나는 계단 수의 개수.
int main(void)
{
    int i, j;
    int N;
    long D[101][10] = {0,};
    long mod = 1000000000;

    cin >> N;
    for (i = 1; i <= 9; i++)
        D[1][i] = 1;
    for (i = 2; i <= N; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            if (j == 0)
                D[i][j] = D[i - 1][1];
            else if (j == 9)
                D[i][j] = D[i - 1][8];
            else
                D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % mod;
        }
    }

    long sum = 0;
    for (i = 0; i <= 9; i++)
    {
        sum = (sum + D[N][i]) % mod;
    }
    cout << sum << endl;
    return 0;
}