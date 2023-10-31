// 깊이 우선 탐색 (DFS) 스택 자료구조 이용
// 연결 요소의 개수 구하기 (11724)
#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//
//bool g_visited[1001];
//std::vector<int> g_adjustList[1001];
//
//void DFS(int i)
//{
//    if (g_visited[i] = true)
//        return;
//    g_visited[i] = true;
//    std::vector<int>::iterator it;
//    for (it = g_adjustList[i].begin(); it != g_adjustList[i].end(); it++)
//    {
//        if (g_visited[*it] == false)
//            DFS(*it);
//    }
//}
//
//int main(void)
//{
//    int N, M;
//    int u, v;
//    int component = 0;
//
//    scanf("%d %d", &N, &M);
//    for (int i = 0; i < M; i++)
//    {
//        scanf("%d %d", &u, &v);
//        g_adjustList[u].push_back(v);
//        g_adjustList[v].push_back(u);
//    }
//
//    for (int i = 1; i <= N; i++)
//    {
//        if (g_visited[i] == false)
//        {
//            DFS(i);
//            component += 1;
//        }
//    }
//
//    printf("%d\n", component);
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int v);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    int g_count = 0;

    for (int i = 1; i < N + 1; i++)
    {
        if (!visited[i])
        {
            g_count++;
            DFS(i);
        }
    }
    cout << g_count << "\n";
}

void DFS(int v)
{
    if (visited[v])
        return;

    visited[v] = true;

    for (int i : A[v])
    {
        if (visited[i] == false)
            DFS(i);
    }
}