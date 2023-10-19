// 최솟값 찾기 1 (11003) *****
#include <iostream>
#include <deque>
#include <algorithm>

typedef std::pair<int, int> Node;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, L;
    std::cin >> N >> L;
    std::deque<Node> dq;

    for (int i = 0; i < N; i++)
    {
        int now;
        std::cin >> now;
        
        while (dq.size() != 0 && dq.back().first > now)
            dq.pop_back();
        dq.push_back(Node(now, i));
        if (dq.front().second <= i - L)
            dq.pop_front();

        std::cout << dq.front().first << ' ';
    }

    return 0;
}