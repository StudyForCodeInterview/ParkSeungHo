// 카드 게임 (2164)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

int main(void)
{
    int N;
    std::queue<int> q;

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        q.push(i);

    while (q.size() != 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    printf("%d\n", q.front());

    return 0;
}