// 나머지 합 구하기 (10986) *****

//#include <iostream>
//
//int main(void)
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    std::cout.tie(NULL);
//    int N;
//    int M;
//    long *A;
//    long C[1001] = { 0, };
//    long cnt;
//
//    A = (long*)malloc(sizeof(long) * 1000001);
//    if (A == nullptr)
//        return -1;
//
//    std::cin >> N >> M;
//
//    A[0] = 0;
//    cnt = 0;
//    for (int i = 1; i <= N; i++)
//    {
//        std::cin >> A[i];
//        A[i] = (A[i] + A[i - 1]) % M;
//        if (A[i] == 0)
//            cnt++;
//        C[A[i]] += 1;
//    }
//
//    for (int i = 0; i <= M; i++)
//    {
//        cnt += (C[i] * (C[i] - 1) / 2);
//    }
//
//    std::cout << cnt << std::endl;
//    return 0;
//}

// 왜안됨
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long S[1000001];
long D[1000];

int main(void)
{
    int N, M;
    long ret = 0;

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        long tmp;
        scanf("%d", &tmp);
        S[i] = S[i - 1] + tmp;
    }

    for (int i = 1; i <= N; i++)
    {
        S[i] %= M;
        if (S[i] == 0)  // 0~i까지의 구간 합 자체가 0일 때 정답에 더하기
            ret++;
        D[S[i]]++;  // 나머지가 같은 인덱스의 개수 세기
    }

    for (int i = 0; i < M; i++)
    {
        if (D[i] > 1)
        {
            ret += (D[i] * (D[i] - 1) / 2); // nC2
        }
    }

    printf("%d\n", ret);
    return 0;
}