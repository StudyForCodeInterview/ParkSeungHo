// ±¸°£ÇÕ (11659)
#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    int M;
    int arr[100001];

    std::cin >> N >> M;
    
    arr[0] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        std::cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = 0; i < M; i++)
    {
        int start;
        int end;

        std::cin >> start >> end;

        std::cout << arr[end] - arr[start - 1] << std::endl;
    }
    return 0;
}
