// 외판원의 순회 경로 짜기 (2098) (DP + 비트마스크) //모르겠음
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// D[c][v] : 현재 도시가 c, 현재까지 방문한 모든 도시 리스트가 v일 때 앞으로 남은 모든 도시를 경유하는 데 필요한 최소 비용
// 현재 방문하지 않은 모든 도시에 대해 반복하고, 방문하지 않은 도시를 i라고 했을 때 다음과 같음.
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
    if (v == (1 << N) - 1)  // 모든 노드를 방문했을 때
    {
        // 시작 도시로 돌아갈 수 있는 경우 -> return W[c][시작 도시]
        // 시작 도시로 돌아갈 수 없는 경우 -> return 무한대(정답이 될 수 없음)
        return W[c][0] == 0 ? INF : W[c][0];
    }

    if (D[c][v] != 0)   // 이미 방문한 노드일 때 -> 이미 계산했다면 바로 반환(메모이제이션)
        return D[c][v];

    int min_val = INF;
    for (i = 0; i < N; i++)
    {
        // 방문한 적이 없고 갈 수 있는 도시일 때
        if ((v & (1 << i)) == 0 && W[c][i] != 0)
            min_val = min(min_val, TSP(i, (v | (1 << i))) + W[c][i]);
    }
    D[c][v] = min_val;
    return D[c][v];
}