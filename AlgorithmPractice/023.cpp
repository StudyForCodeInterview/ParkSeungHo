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

//#include <iostream>
//#include <vector>
//using namespace std;
//
//static vector<vector<int>> A;
//static vector<bool> visited;
//void DFS(int v);
//
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int N, M;
//    cin >> N >> M;
//    A.resize(N + 1);
//    visited = vector<bool>(N + 1, false);
//
//    for (int i = 0; i < M; i++)
//    {
//        int s, e;
//        cin >> s >> e;
//        A[s].push_back(e);
//        A[e].push_back(s);
//    }
//
//    int g_count = 0;
//
//    for (int i = 1; i < N + 1; i++)
//    {
//        if (!visited[i])
//        {
//            g_count++;
//            DFS(i);
//        }
//    }
//    cout << g_count << "\n";
//}
//
//void DFS(int v)
//{
//    if (visited[v])
//        return;
//
//    visited[v] = true;
//
//    for (int i : A[v])
//    {
//        if (visited[i] == false)
//            DFS(i);
//    }
//}

#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> adjucencyList;
int answer;

void DFS_Stack(int node);
void DFS_Recursive(int node);

int main(void)
{
    int N;
    int M;

    cin >> N >> M;
    visited.resize(N + 1, 0);
    adjucencyList.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int n, m;
        cin >> n >> m;
        adjucencyList[n].push_back(m);
        adjucencyList[m].push_back(n);
    }

    for (int i = 1; i <= N; i++)
    {
        //DFS_Stack(i);

        if (visited[i] == false)
            answer++;
        DFS_Recursive(i);
    }

    cout << answer << endl;
    return 0;
}

void DFS_Stack(int node)
{
    vector<int> st;
    
    if (visited[node] == true)
        return;
    
    answer++;
    st.push_back(node);
    visited[node] = true;
    while (!st.empty())
    {
        int tmp = st[st.size() - 1];
        st.pop_back();
        for (int i : adjucencyList[tmp])
        {
            if (visited[i] != true)
            {
                st.push_back(i);
                visited[i] = true;
            }
        }
    }
}

void DFS_Recursive(int node)
{
    if (visited[node] == true)
        return;


    visited[node] = true;
    for (int i : adjucencyList[node])
    {
        DFS_Recursive(i);
    }
}