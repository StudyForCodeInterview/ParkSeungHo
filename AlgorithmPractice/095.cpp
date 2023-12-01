// ���ǿ��� ��ȸ ��� ¥�� (2098) (DP + ��Ʈ����ũ) //�𸣰���
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// D[c][v] : ���� ���ð� c, ������� �湮�� ��� ���� ����Ʈ�� v�� �� ������ ���� ��� ���ø� �����ϴ� �� �ʿ��� �ּ� ���
// ���� �湮���� ���� ��� ���ÿ� ���� �ݺ��ϰ�, �湮���� ���� ���ø� i��� ���� �� ������ ����.
// D[c][v] : min(D[c][v], D[i][v | (1 << i)] + W[c][i])

int i, j;
int N;
int W[16][16];
int D[16][1 << 16];
int INF = 1000000 * 16 + 1;
int TSP(int c, int v);

int main(void)
{
    cin >> N;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }


    cout << TSP(0, 1) << endl;
    return 0;
}

int TSP(int c, int v)
{
    if (v == (1 << N) - 1)  // ��� ��带 �湮���� ��
    {
        // ���� ���÷� ���ư� �� �ִ� ��� -> return W[c][���� ����]
        // ���� ���÷� ���ư� �� ���� ��� -> return ���Ѵ�(������ �� �� ����)
        return W[c][0] == 0 ? INF : W[c][0];
    }

    if (D[c][v] != 0)   // �̹� �湮�� ����� �� -> �̹� ����ߴٸ� �ٷ� ��ȯ(�޸������̼�)
        return D[c][v];

    int min_val = INF;
    for (i = 0; i < N; i++)
    {
        // �湮�� ���� ���� �� �� �ִ� ������ ��
        if ((v & (1 << i)) == 0 && W[c][i] != 0)
            min_val = min(min_val, TSP(i, (v | (1 << i))) + W[c][i]);
    }
    D[c][v] = min_val;
    return D[c][v];
}