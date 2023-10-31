// 주몽의 명령 (1940) *****

#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int g_count = 0;
    int i = 0;
    int j = N - 1;

    while (i < j)
    {
        if (A[i] + A[j] < M)
            i++;
        else if (A[i] + A[j] > M)
            j--;
        else
        {
            g_count++;
            i++;
            j--;
        }
    }
    
    std::cout << g_count << std::endl;
    return 0;
}