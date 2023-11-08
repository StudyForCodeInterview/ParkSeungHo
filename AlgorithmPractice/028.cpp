// 트리의 지름 구하기 (1167)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> A;
vector<bool> visited;
vector<int> m_distance;
void BFS(int node);

int main(void)
{
    int N;
    scanf("%d", &N);
    A.resize(N + 1);

    for (int i = 0; i < N; i++)
    {
        int S;
        scanf("%d", &S);
        while (1)
        {
            int E, V;
            scanf("%d", &E);
            if (E == -1)
                break;
            scanf("%d", &V);
            A[S].push_back(edge(E, V));
        }
    }

    m_distance = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);
    BFS(1);
    int Max = 1;

    for (int i = 2; i <= N; i++)
    {
        if (m_distance[Max] < m_distance[i])
            Max = i;
    }
    fill(m_distance.begin(), m_distance.end(), 0);  // 거리 배열 초기화
    fill(visited.begin(), visited.end(), false);    // 방문 배열 초기화
    BFS(Max);
    sort(m_distance.begin(), m_distance.end());
    printf("%d\n", m_distance[N]);
    return 0;
}

void BFS(int index)
{
    queue<int> q;
    q.push(index);
    visited[index] = true;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        for (edge i : A[curNode])
        {
            if (!visited[i.first])
            {
                visited[i.first] = true;
                q.push(i.first);
                // 거리 배열 업데이트
                m_distance[i.first] = m_distance[curNode] + i.second;
            }
        }
    }
}