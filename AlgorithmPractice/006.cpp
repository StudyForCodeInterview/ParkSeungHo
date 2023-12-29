// 투 포인터 (2018) *****

//#include <iostream>
//
//int main(void)
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    std::cout.tie(NULL);
//
//    int N;
//    int answer;
//
//    std::cin >> N;
//    if (N == 1)
//    {
//        std::cout << 1 << std::endl;
//        return 0;
//    }
//
//    answer = 1;
//
//    for (int i = 1; i < N / 2 + 1; i++)
//    {
//        int tmp = 0;
//        for (int j = i; j <= N; j++)
//        {
//            tmp += j;
//            if (tmp == N)
//            {
//                answer++;
//                break;
//            }
//            else if (tmp > N)
//                break;
//        }
//    }
//
//    std::cout << answer << std::endl;
//    return 0;
//}

#include <iostream>
using namespace std;

int main(void)
{
    int N;
    int answer;
    int front, rear;
    int sum;

    cin >> N;

    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    front = 1;
    rear = 2;
    sum = front + rear;
    answer = 0;
    while (1)
    {
        if (front > rear)
            break;
        else if (sum < N)
        {
            rear++;
            sum += rear;
        }
        else if (sum > N)
        {
            sum -= front;
            front++;
        }
        else if (sum == N)
        {
            answer++;
            sum -= front;
            front++;
        }
    }

    cout << answer << endl;
    return 0;
}