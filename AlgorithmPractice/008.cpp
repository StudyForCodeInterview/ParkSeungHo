// 좋은 수 구하기 (1253) *****
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
//    // 입력값이 음수도 될 수 있음
//    for (int i = 0; i < N; i++)
//    {
//        std::cin >> vec[i];
//    }
//
//    // std::vector<int> vec;
//    // vec.reserve(N); 으로 할 시 vec[i]로 데이터를 넣으면 size가 증가하지 않아서 정렬이 잘 안됨.
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


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int main(void)
{
    int N;
    int answer = 0;

    cin >> N;
    vec.reserve(N);
    for (int i = 0; i < N; i++)
    {
        cin >> answer;
        vec.push_back(answer);
    }

    sort(vec.begin(), vec.end());

    if (N < 3)
    {
        cout << 0 << endl;
        return 0;
    }

    answer = 0;
    for (int k = 0; k < N; k++)
    {
        int find = vec[k];
        int start = 0;
        int end = 1;
        while (1)
        {
            if (end >= k)
                break;
            int sum = vec[start] + vec[end];
            if (sum == find)
            {
                answer++;
                start++;
            }
            else if (sum < find)
            {
                end++;
            }
            else if (sum > find)
            {
                break;
            }
        }
    }

    cout << answer << endl;
    return 0;
}