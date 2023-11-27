// 이친수 구하기 (2193)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    int i;
    int N;
    long long D[91][2];

    cin >> N;

    D[1][0] = 0;
    D[1][1] = 1;
    //D[2][0] = 1;
    //D[2][1] = 0;
    for (i = 2; i <= N; i++)
    {
        D[i][0] = D[i - 1][0] + D[i - 1][1];
        D[i][1] = D[i - 1][0];
    }

    cout << D[N][0] + D[N][1] << std::endl;
    return 0;
}