    // ±¸°£ÇÕ2(11660) ***
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//
//int main(void)
//{
//    int N;
//    int M;
//    int* a;
//    int* d;
//    std::vector<int> answer;
//
//    scanf("%d %d", &N, &M);
//    a = new int[sizeof(int) * 1025 * 1025];
//    d = new int[sizeof(int) * 1025 * 1025];
//    memset(a, 0, sizeof(int) * 1025 * 1025);
//    memset(d, 0, sizeof(int) * 1025 * 1025);
//
//    int(*A)[1025] = (int(*)[1025])a;
//    int(*D)[1025] = (int(*)[1025])d;
//
//    for (int i = 1; i <= N; i++)
//    {
//        for (int j = 1; j <= N; j++)
//        {
//            scanf("%d", &A[i][j]);
//            D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + A[i][j];
//        }
//    }
//
//    for (int i = 0; i < M; i++)
//    {
//        int x1, y1, x2, y2;
//        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//        int tmp = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
//        answer.push_back(tmp);
//    }
//
//    for (int i = 0; i < answer.size(); i++)
//    {
//        printf("%d\n", answer[i]);
//    }
//    return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int S[1025][1025];
int A[1025][1025];

int main(void)
{
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &A[i][j]);
            S[i][j] = S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1] + A[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1]);
    }

    return 0;
}