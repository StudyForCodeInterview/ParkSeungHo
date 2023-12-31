#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> adjustList;
vector<int> visited;
std::queue<int> q;

void DFS_Stack(int V)
{
    visited[V] = true;
    printf("%d ", V);   
    /*vector<int>::iterator it;
    for (it = adjustList[V].begin(); it != adjustList[V].end(); it++)
    {
        if (visited[*it] == false)
            DFS(*it);
    }*/
    for (int i : adjustList[V])
    {
        if (visited[i] == false)
            DFS_Stack(i);
    }
}
void BFS(int V)
{
    q.push(V);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        if (visited[n] == true)
            continue;
        visited[n] = true;
        printf("%d ", n);
        vector<int>::iterator it;
        for (it = adjustList[n].begin(); it != adjustList[n].end(); it++)
        {
            q.push(*it);
        }
    }
}

void BFS2(int v)
{
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        printf("%d ", n);
        for (int i : adjustList[n])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main(void)
{
    int N, M, V;
    int a, b;

    adjustList.resize(1001);
    visited.resize(1001);

    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        adjustList[a].push_back(b);
        adjustList[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adjustList[i].begin(), adjustList[i].end());
    }

    DFS_Stack(V);
    printf("\n");
    fill(visited.begin(), visited.end(), 0);
    BFS(V);
    return 0;
}