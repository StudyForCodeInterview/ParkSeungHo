// 투 포인터 (2018) *****

#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    int answer;

    std::cin >> N;
    if (N == 1)
    {
        std::cout << 1 << std::endl;
        return 0;
    }

    answer = 1;

    for (int i = 1; i < N / 2 + 1; i++)
    {
        int tmp = 0;
        for (int j = i; j <= N; j++)
        {
            tmp += j;
            if (tmp == N)
            {
                answer++;
                break;
            }
            else if (tmp > N)
                break;
        }
    }

    std::cout << answer << std::endl;
    return 0;
}