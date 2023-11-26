#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int s;

bool isContain(vector<int>& vec, int val)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == val)
            return true;
    }
    return false;
}

//bool isContain(vector<int>& vec, int val)
//{
//    for (int i : vec)
//    {
//        if (i == val)
//            return true;
//    }
//    return false;
//}

vector<int> rustMurderer(int n, vector<vector<int>> roads) {
    int i, j;
    vector<vector<int>> tree(n + 1);
    vector<bool> visited(n + 1);
    vector<int> D(n + 1, 2147483647);
    queue<int> q;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j || isContain(roads[i], j) == true)
                continue;
            tree[i].push_back(j);
            tree[j].push_back(i);
        }
    }

    D[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        if (visited[val] == true)
            continue;
        visited[val] = true;

        for (i = 0; i < tree[val].size(); i++)
        {
            int next = tree[val][i];

            if (D[next] > D[val] + 1)
            {
                D[next] = D[val] + 1;
                q.push(next);
            }
        }
    }

    D.erase(D.begin());
    for (auto it = D.begin(); it != D.end(); it++)
    {
        if (*it == 0)
        {
            D.erase(it);
            break;
        }
    }
    return D;
}

int main(void)
{
    vector<vector<int>> roads;
    int T, N, M;
    int x, y, S;
    int i;

    //cin >> T;
    cin >> N >> M;

    roads.resize(N + 1);
    for (i = 0; i < M; i++)
    {
        cin >> x >> y;
        roads[x].push_back(y);
        roads[y].push_back(x);
    }
    cin >> s;

    vector<int> result = rustMurderer(N, roads);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}