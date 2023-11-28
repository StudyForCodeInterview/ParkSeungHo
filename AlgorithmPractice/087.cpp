// 2 * N Ÿ�� ä���
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// ���̰� N�̰� [|]�� ������ ���� D[N][0] = D[N-1][0] + D[N-1][1]
// ���̰� N�̰� �������� [��] 2���� ������ ���� D[N][1] = D[N-2][0] + D[N-2][1]
//int main(void)
//{
//    int i;
//    int N;
//    int D[1001][2] = {0,};
//
//    cin >> N;
//    D[1][0] = 1;
//    D[2][0] = 1;
//    D[2][1] = 1;
//    for (i = 3; i <= N; i++)
//    {
//        D[i][0] = (D[i - 1][0] + D[i - 1][1]) % 10007;
//        D[i][1] = (D[i - 2][0] + D[i - 2][1]) % 10007;
//    }
//
//    cout << (D[N][0] + D[N][1]) % 10007 << endl;
//    return 0;
//}

int main(void)
{
    int i;
    int N;
    int D[1001];
    int mod = 10007;
    
    cin >> N;
    D[1] = 1;
    D[2] = 2;

    for (i = 3; i <= N; i++)
    {
        D[i] = (D[i - 1] + D[i - 2]) % mod;
    }
    cout << D[N] << endl;
    return 0;
}