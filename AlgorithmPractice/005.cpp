// 나머지 합 구하기 (10986)

#include <iostream>

// 시간 초과
//int main(void)
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    std::cout.tie(NULL);
//
//    int N;
//    int M;
//    int cnt = 0;
//    int A[1000001];
//
//    A[0] = 0;
//    std::cin >> N >> M;
//    for (int i = 1; i <= N; i++)
//    {
//        std::cin >> A[i];
//        A[i] = (A[i] + A[i - 1]) % M;
//    }
//
//    for (int j = 0; j < N - 1; j++)
//    {
//        for (int i = 0; i < N - j; i++)
//        {
//            if ((A[N - j] - A[i]) % M == 0)
//                cnt++;
//        }
//    }
//
//    std::cout << cnt << std::endl;
//    return 0;
//}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    int M;
    long *A;
    long C[1001] = { 0, };
    long cnt;

    A = (long*)malloc(sizeof(long) * 1000001);
    if (A == nullptr)
        return -1;

    std::cin >> N >> M;

    A[0] = 0;
    cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> A[i];
        A[i] = (A[i] + A[i - 1]) % M;
        if (A[i] == 0)
            cnt++;
        C[A[i]] += 1;
    }

    for (int i = 0; i <= M; i++)
    {
        cnt += (C[i] * (C[i] - 1) / 2);
    }

    std::cout << cnt << std::endl;
    return 0;
}