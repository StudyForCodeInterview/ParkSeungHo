// 최소 공통 조상 (11437)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

int LCA(int a, int b);
void BFS(int node);

int main(void)
{
    int i;
    int N, M;
    int n1, n2;
    scanf("%d", &N);

    tree.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);
    visited.resize(N + 1);

    for (i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &n1, &n2);
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    BFS(1);

    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &n1, &n2);
        printf("%d\n", LCA(n1, n2));
    }
    return 0;
}

int LCA(int a, int b)
{
    if (depth[a] < depth[b])
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while (depth[a] != depth[b])
    {
        a = parent[a];
    }
    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}
void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int level = 1;
    int curSize = 1;
    int count = 0;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        for (int nextNode : tree[curNode])
        {
            if (!visited[nextNode])
            {
                visited[nextNode] = true;
                q.push(nextNode);
                parent[nextNode] = curNode;
                depth[nextNode] = level;
            }
        }
        count++;
        if (count == curSize)
        {
            count = 0;
            curSize = q.size();
            level++;
        }
    }
}