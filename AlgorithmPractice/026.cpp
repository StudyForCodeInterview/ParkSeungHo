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

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<vector<int>> A;
stack<int> st;

void DFS(int node);
void BFS(int node);
int main(void)
{
    int N, M, V;
    int n1, n2;

    cin >> N >> M >> V;
    visited.resize(N + 1, false);
    A.resize(N + 1);
    for (int i = 1; i <= M; i++)
    {
        cin >> n1 >> n2;
        A[n1].push_back(n2);
        A[n2].push_back(n1);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(A[i].begin(), A[i].end());
    }

    DFS(V);
    cout << endl;
    fill(visited.begin(), visited.end(), false);
    BFS(V);
    return 0;
}

void DFS(int node)
{
    if (visited[node] == true)
        return;

    visited[node] = true;
    cout << node << " ";
    for (int i : A[node])
    {
        DFS(i);
    }
}

void BFS(int node)
{
    queue<int> q;

    visited[node] = true;
    q.push(node);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cout << tmp << " ";
        for (int i : A[tmp])
        {
            if (visited[i] != true)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}