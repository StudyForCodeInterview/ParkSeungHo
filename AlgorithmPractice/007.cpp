// ÁÖ¸ùÀÇ ¸í·É (1940) *****

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main(void)
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    std::cout.tie(NULL);
//
//    int N, M;
//    std::cin >> N >> M;
//    std::vector<int> A(N, 0);
//
//    for (int i = 0; i < N; i++)
//    {
//        std::cin >> A[i];
//    }
//
//    std::sort(A.begin(), A.end());
//
//    int g_count = 0;
//    int i = 0;
//    int j = N - 1;
//
//    while (i < j)
//    {
//        if (A[i] + A[j] < M)
//            i++;
//        else if (A[i] + A[j] > M)
//            j--;
//        else
//        {
//            g_count++;
//            i++;
//            j--;
//        }
//    }
//    
//    std::cout << g_count << std::endl;
//    return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int main(void)
{
    int N, M;
    int index = 0;
    int front, rear;
    int sum;
    int answer = 0;

    scanf("%d", &N);
    scanf("%d", &M);
    A.reserve(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &sum);
        A.push_back(sum);
    }

    sort(A.begin(), A.end());

    front = 0, rear = N - 1;
    while (1)
    {
        sum = A[front] + A[rear];
        if (front == rear)
            break;
        if (sum == M)
        {
            answer++;
            front++;
        }
        else if (sum < M)
        {
            front++;
        }
        else if (sum > M)
        {
            rear--;
        }
    }

    printf("%d\n", answer);

    return 0;
}