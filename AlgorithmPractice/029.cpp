// 원하는 정수 찾기 (1920)
#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool Finding(vector<int> vec, int start, int end, int target);
//int main(void)
//{
//    int N;
//    int M;
//    int num;
//    vector<int> arr;
//
//    scanf("%d", &N);
//    arr.reserve(N);
//    for (int i = 0; i < N; i++)
//    {
//        scanf("%d", &num);
//        arr.push_back(num);
//    }
//    sort(arr.begin(), arr.end());
//    scanf("%d", &M);
//    for (int i = 0; i < M; i++)
//    {
//        scanf("%d", &num);
//        if (Finding(arr, 0, arr.size() - 1, num) == true)
//            printf("1\n");
//        else
//            printf("0\n");
//    }
//
//    return 0;
//}
//
//bool Finding(vector<int> vec, int start, int end, int target)
//{
//    if (start > end)
//        return false;
//    int mid = (start + end) / 2;
//    if (vec[mid] == target)
//        return true;
//    else if (vec[mid] < target)
//        return Finding(vec, mid + 1, end, target);
//    else if (vec[mid] > target)
//        return Finding(vec, start, mid - 1, target);
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    scanf("%d", &N);
    vector<int> A(N);
    int num;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    sort(A.begin(), A.end());
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        bool find = false;
        int target;
        scanf("%d", &target);
        int start = 0;
        int end = A.size() - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (A[mid] > target)
                end = mid - 1;
            else if (A[mid] < target)
                start = mid + 1;
            else
            {
                find = true;
                break;
            }
        }

        if (find)
            printf("1\n");
        else
            printf("0\n");
    }
}