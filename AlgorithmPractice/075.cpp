#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> tree;
vector<int> depth;
int kmax;
int parent[21][100001];
vector<bool> visited;

int LCA(int a, int b);
void BFS(int node);

int main(void)
{
    int i, temp;
    int N, M;
    int a, b;
    int k, n;

    scanf("%d", &N);

    tree.resize(N + 1);
    depth.resize(N + 1);
    visited.resize(N + 1);

    for (i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    temp = 1;
    kmax = 0;

    // 최대 가능 깊이 구하기
    while (temp <= N)
    {
        temp <<= 1;
        kmax++;
    }

    BFS(1);

    for (k = 1; k <= kmax; k++)
    {
        for (n = 1; n <= N; n++)
        {
            // P[K][N] = N번 노드의 2^K번째 부모의 노드 번호.
            parent[k][n] = parent[k - 1][parent[k - 1][n]];
        }
    }

    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}

int LCA(int a, int b)
{
    // 더 깊이가 깊은 깊이가 b가 되도록 변경
    if (depth[b] < depth[a])
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // 깊이 빠르게 맞추기
    for (int k = kmax; k >= 0; k--)
    {
        if (pow(2, k) <= depth[b] - depth[a])
        {
            if (depth[a] <= depth[parent[k][b]])
            {
                b = parent[k][b];
            }
        }
    }

    // 조상 빠르게 찾기
    for (int k = kmax; k >= 0 && a != b; k--)
    {
        if (parent[k][a] != parent[k][b])
        {
            a = parent[k][a];
            b = parent[k][b];
        }
    }

    int LCA = a;

    if (a != b)
        LCA = parent[0][LCA];
    return LCA;
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int level = 1;
    int count = 0;
    int size = 1;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        for (int nextNode : tree[curNode])
        {
            if (visited[nextNode] == false)
            {
                visited[nextNode] = true;
                q.push(nextNode);
                parent[0][nextNode] = curNode;
                depth[nextNode] = level;
            }
        }
        count++;
        if (count == size)
        {
            count = 0;
            size = q.size();
            level++;
        }
    }
}