// 리프 노드의 개수 구하기 (1068)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjustList;
vector<bool> visited;
vector<int> parentArr;

int ret;
int N;
int delNode;
int root;

void DFS(int root);

int main(void)
{
    scanf("%d", &N);
    parentArr.resize(N);
    adjustList.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        parentArr[i] = num;
        if (num == -1)
        {
            root = i;
            continue;
        }
        adjustList[i].push_back(num);
        adjustList[num].push_back(i);
    }
    scanf("%d", &delNode);

    DFS(root);
    
    printf("%d\n", ret);
    return 0;
}

void DFS(int root)
{
    int child = 0;
    visited[root] = true;

    if (root == delNode)
        return;

    for (int i : adjustList[root])
    {
        if (visited[i] == false && i != delNode)
        {
            visited[i] = true;
            child++;
            DFS(i);
        }
    }

    if (child == 0)
        ret++;
}