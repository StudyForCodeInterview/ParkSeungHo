#include <iostream>
#include <vector>

int main(void)
{
    int N;
    int tmp;
    int maxScore = 0;
    double sum = 0;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp;
        if (maxScore < tmp)
            maxScore = tmp;
        sum += tmp;
    }

    std::cout << (sum / maxScore * 100 / N) * 1.0 << std::endl;
    return 0;
}