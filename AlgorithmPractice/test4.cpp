#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int A[301];
int D[301][2];
int main(void)
{
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    D[1][0] = A[1];
    D[1][1] = A[1];
    D[2][0] = A[1] + A[2];
    D[2][1] = A[2];
    for (int i = 3; i <= N; i++)
    {
        D[i][0] = D[i - 1][1] + A[i];
        D[i][1] = max(D[i - 2][0], D[i - 2][1]) + A[i];
    }

    cout << max(D[N][0], D[N][1]) << endl;
    return 0;
}