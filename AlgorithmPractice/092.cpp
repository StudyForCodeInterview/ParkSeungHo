// °íÃþ ºôµù (1328)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>
using namespace std;

//long D[101][101][101];
//int main(void)
//{
//    int N, L, R;
//
//    cin >> N >> L >> R;
//
//    D[1][1][1] = 1;
//    D[2][1][2] = 1;
//    D[2][2][1] = 1;
//    for (int i = 3; i <= N; i++)
//    {
//        for (int j = 1; j <= N; j++)
//        {
//            for (int k = 1; k <= N; k++)
//            {
//                D[i][j][k] = (D[i - 1][j - 1][k - 1] + D[i - 1][j][k - 1] + D[i - 1][j - 1][k] + D[i - 1][j][k]) % 1000000007;
//            }
//        }
//    }
//
//    cout << D[N][L][R] << endl;
//    return 0;
//}

long mod = 1000000007;
long D[101][101][101];

int main(void)
{
    int N, L, R;

    cin >> N >> L >> R;

    D[1][1][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            for (int k = 1; k <= R; k++)
            {
                D[i][j][k] = (D[i - 1][j - 1][k] + D[i - 1][j][k - 1] + D[i - 1][j][k] * (i - 2)) % mod;
            }
        }
    }

    cout << D[N][L][R] << endl;
    return 0;
}