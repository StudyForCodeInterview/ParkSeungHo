// 트리 (11725)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> A;
// parentArr[i] = n; --> node i의 부모는 n
vector<int> parentArr;
vector<int> visited;

int main(void)
{
    int N;
    int n1, n2;
    queue<int> q;

    scanf("%d", &N);
    A.resize(N + 1);
    parentArr.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &n1, &n2);
        A[n1].push_back(n2);
        A[n2].push_back(n1);
    }

    int child;
    int i;
    int size;
    q.push(1);
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        size = A[i].size();
        for (int j = 0; j < size; j++)
        {
            child = A[i][j];
            if (visited[child] == false)
            {
                visited[child] = true;
                parentArr[child] = i;
                q.push(child);
            }
        }
    } 

    for (int i = 2; i <= N; i++)
    {
        printf("%d\n", parentArr[i]);
    }
    return 0;
}
 
//vector<vector<int>> tree;
//void DFS(int number)
//{
//    visited[number] = true;
//
//    for (int i : tree[number])
//    {
//        if (!visited[i])
//        {
//            answer[i] = number;
//            DFS(i);
//        }
//    }
//}