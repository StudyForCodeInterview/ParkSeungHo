// ���� �� ���ϱ� (1253) *****
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
//    int N;
//    int tmp;
//
//    std::cin >> N;
//    std::vector<int> vec(N, 0);
//
//    // �Է°��� ������ �� �� ����
//    for (int i = 0; i < N; i++)
//    {
//        std::cin >> vec[i];
//    }
//
//    // std::vector<int> vec;
//    // vec.reserve(N); ���� �� �� vec[i]�� �����͸� ������ size�� �������� �ʾƼ� ������ �� �ȵ�.
//    std::sort(vec.begin(), vec.end());
//
//    int result = 0;
//    for (int k = 0; k < N; k++)
//    {
//        long find = vec[k];
//        int i = 0;
//        int j = N - 1;
//
//        while (i < j)
//        {
//            if (vec[i] + vec[j] == find)
//            {
//                if (i != k && j != k)
//                {
//                    result++;
//                    break;
//                }
//                else if (i == k)
//                    i++;
//                else if (j == k)
//                    j--;
//            }
//            else if (vec[i] + vec[j] < find)
//                i++;
//            else
//                j--;
//        }
//    }
//    std::cout << result << std::endl;
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> vec;
//int main(void)
//{
//    int N;
//    int answer = 0;
//
//    cin >> N;
//    vec.reserve(N);
//    for (int i = 0; i < N; i++)
//    {
//        cin >> answer;
//        vec.push_back(answer);
//    }
//
//    sort(vec.begin(), vec.end());
//
//    if (N < 3)
//    {
//        cout << 0 << endl;
//        return 0;
//    }
//
//    answer = 0;
//    for (int k = 0; k < N; k++)
//    {
//        int find = vec[k];
//        int start = 0;
//        int end = 1;
//        while (1)
//        {
//            if (end >= k)
//                break;
//            int sum = vec[start] + vec[end];
//            if (sum == find)
//            {
//                answer++;
//                start++;
//            }
//            else if (sum < find)
//            {
//                end++;
//            }
//            else if (sum > find)
//            {
//                break;
//            }
//        }
//    }
//
//    cout << answer << endl;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
    int N;

    cin >> N;
    vector<long> vec(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int s = 0;
        int e = N - 1;
        while (1)
        {
            long sum = vec[s] + vec[e];
            if (s >= e)
                break;
            if (sum == vec[i])
            {
                if (s != i && e != i)
                {
                    answer++;
                    break;
                }
                else if (s == i)
                    s++;
                else if (e == i)
                    e--;
            }
            else if (sum < vec[i])
            {
                s++;
            }
            else // sum > vec[i]
            {
                e--;
            }
        }
    }

    cout << answer << endl;

    return 0;
}

/*
* �ݷ�
* 
8
1 2 3 5 7 9 11 13
6

4
1 2 2 3
1

4
1 1 2 3
2

5
-1 -2 0 -1 -2
4

5
0 0 0 0 1
4
*/