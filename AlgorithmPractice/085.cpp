// ��� �غ��ϱ� (14501)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// D[i] = i��° ������ ����ϱ��� �� �� �ִ� �ִ� ����
// D[i] = D[i + 1]; // ���� ���۵Ǵ� ����� ���� �� ����ϱ��� ������ �ʴ� ���
// D[i] = MAX(D[i + 1], D[i + T[i]] + P[i]);    // ���� ���۵Ǵ� ����� ���� �� ����� �ȿ� ������ ���
int N;
vector<int> D, T, P;
int main(void)
{
    int i;
    cin >> N;

    D.resize(N + 2);
    T.resize(N + 1);
    P.resize(N + 1);

    for (i = 1; i <= N; i++)
        cin >> T[i] >> P[i];

    for (i = N; i > 0; i--)
    {
        if (i + T[i] > N + 1)
            D[i] = D[i + 1];
        else
            D[i] = max(D[i + 1], P[i] + D[i + T[i]]);
    }

    cout << D[1];
    return 0;
}

// D[i] = i��° ������ �� �� �ִ� �ִ� ����

//int GetMax(int* D, int idx)
//{
//    int i;
//    int max = 0;
//    for (i = 1; i <= idx; i++)
//    {
//        if (max < D[i])
//            max = D[i];
//    }
//    return max;
//}
//int main(void)
//{
//    int i;
//    int N;
//    int T[16] = { 0, };
//    int P[16] = { 0, };
//    int D[17] = { 0, };
//    int max = 0;
//
//    scanf("%d", &N);
//
//    for (i = 1; i <= N; i++)
//    {
//        scanf("%d %d", &T[i], &P[i]);
//    }
//
//    for (i = 1; i <= N; i++)
//    {
//        int index = i + T[i] - 1;
//        if (index > N)
//            continue;
//        max = GetMax(D, i - 1);
//        if (max + P[i] > D[index])
//            D[index] = max + P[i];
//    }
//
//    max = 0;
//    for (i = 1; i <= N; i++)
//    {
//        if (D[i] > max)
//            max = D[i];
//    }
//
//    printf("%d\n", max);
//    return 0;
//}