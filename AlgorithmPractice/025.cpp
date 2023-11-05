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

void DFS(int startIndex, int depth)
{
    if (depth >= 5 || ret == true)
    {
        ret = true;
        return;
    }
    visited[startIndex] = true;
    for (int i = 0; i < adjustList[startIndex].size(); i++)
    {
        int index = adjustList[startIndex][i];
        if (visited[index] == false)
        {
            DFS(index, depth + 1);
        }
    }
    visited[startIndex] = false;
}

int main(void)
{
    adjustList.resize(2000);
    visited.resize(2000);

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        adjustList[a].push_back(b);
        adjustList[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        DFS(i, 1);
        if (ret == true)
            break;
    }

    printf("%d\n", ret);
    return 0;
}