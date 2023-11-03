// 친구 관계 파악하기 (13023)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int a, b;
vector<vector<int>> adjustList;
vector<int> visited;
bool ret;

void DFS(int depth)
{
    if (depth >= 5 || ret == true)
    {
        ret = true;
        return;
    }
    for (int i = 0; i < adjustList[depth].size(); i++)
    {
        if (visited[adjustList[depth][i]] == false)
        {
            visited[adjustList[depth][i]] = true;
            if (depth == N - 1)
            {
                ret = true;
                return;
            }
            DFS(depth + 1);
        }
    }
}

int main(void)
{
    adjustList.resize(200);
    visited.resize(200);

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        adjustList[a].push_back(b);
        adjustList[b].push_back(a);
    }

    DFS(0);

    printf("%d\n", ret);
    return 0;
}