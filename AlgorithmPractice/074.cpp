// 최소 공통 조상 (11437)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;

int LCA(int n1, int n2);

int main(void)
{
    int i;
    int N, M;
    int n1, n2;
    scanf("%d", &N);
    vec.resize(N + 1);

    for (i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &n1, &n2);
    }

    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &n1, &n2);
        printf("%d\n", LCA(n1, n2));
    }
    return 0;
}

int LCA(int n1, int n2)
{

}