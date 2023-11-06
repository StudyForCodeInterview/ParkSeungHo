// 미로 탐색하기 (2178)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
int visited[101][101];
std::queue<pair<int, int>> q;

bool IsValidPos(int x, int y)
{
    if (x >= 1 && x <= M && y >= 1 && y <= N)
        return true;
    return false;
}

void PathFinding(int x, int y)
{
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[y][x] = true;
        int nextX = x;
        int nextY = y - 1;
        if (IsValidPos(nextX, nextY))
        {
            if (map[nextY][nextX] == true && visited[nextY][nextX] == false)
            {
                visited[nextY][nextX] = true;
                map[nextY][nextX] = map[y][x] + 1;
                q.push(make_pair(nextX, nextY));
            }
        }
        nextX = x + 1;
        nextY = y;
        if (IsValidPos(nextX, nextY))
        {
            if (map[nextY][nextX] == true && visited[nextY][nextX] == false)
            {
                visited[nextY][nextX] = true;
                map[nextY][nextX] = map[y][x] + 1;
                q.push(make_pair(nextX, nextY));
            }
        }
        nextX = x;
        nextY = y + 1;
        if (IsValidPos(nextX, nextY))
        {
            if (map[nextY][nextX] == true && visited[nextY][nextX] == false)
            {
                visited[nextY][nextX] = true;
                map[nextY][nextX] = map[y][x] + 1;
                q.push(make_pair(nextX, nextY));
            }
        }
        nextX = x - 1;
        nextY = y;
        if (IsValidPos(nextX, nextY))
        {
            if (map[nextY][nextX] == true && visited[nextY][nextX] == false)
            {
                visited[nextY][nextX] = true;
                map[nextY][nextX] = map[y][x] + 1;
                q.push(make_pair(nextX, nextY));
            }
        }
    }
}

void BFS(int x, int y)
{
    // 남 동 북 서
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        visited[curY][curX] = true;

        for (int k = 0; k < 4; k++)
        {
            int nextX = curX + dx[k];
            int nextY = curY + dy[k];
            if (nextX >= 1 && nextY >= 1 && nextX <= M && nextY <= N)
            {
                if (map[nextY][nextX] != 0 && visited[nextY][nextX] == false)
                {
                    visited[nextY][nextX] = true;
                    map[nextY][nextX] = map[y][x] + 1;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }
}

int main(void)
{
    char numStr[101];

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", &numStr);
        for (int j = 1; j <= M; j++)
        {
            map[i][j] = numStr[j - 1] - '0';
        }
    }

    //PathFinding(1, 1);
    BFS(1, 1);
    printf("%d\n", map[N][M]);
    return 0;
}