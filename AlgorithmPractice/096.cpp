// 가장 긴 증가하는 부분 수열 5
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>
using namespace std;

//int A[1000001];
//int D[1000001][2];
//
//int main(void)
//{
//    int N;
//    int max;
//    int maxIndex;
//
//    scanf("%d", &N);
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", &A[i]);
//    }
//
//    max = 0;
//    maxIndex = 0;
//    for (int i = 1; i <= N; i++)
//    {
//        for (int j = 1; j < i; j++)
//        {
//            if (max < D[i - j][0])
//            {
//                max = D[i - j][0];
//                D[i][1] = i - j;
//            }
//        }
//        D[i][0] = max + 1;
//        if (D[i][0] > D[maxIndex][0])
//            maxIndex = i;
//    }
//
//    int index = maxIndex;
//    while (1)
//    {
//        if (A[index] == 0)
//            break;
//        printf("%d ", A[index]);
//        index = D[index][1];
//    }
//
//    return 0;
//}

int N, maxLen;
int B[1000001];
int A[1000001];
int D[1000001];
int ans[1000001];
int binarySearch(int l, int r, int now);

int main(void)
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    int index;
    B[++maxLen] = A[1];
    D[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        if (B[maxLen] < A[i])
        {
            B[++maxLen] = A[i];
            D[i] = maxLen;
        }
        else
        {
            index = binarySearch(1, maxLen, A[i]);
            B[index] = A[i];
            D[i] = index;
        }
    }

    cout << maxLen << endl;
    index = maxLen;
    int x = B[maxLen] + 1;

    for (int i = N; i >= 1; i--)
    {
        if (D[i] == index && A[i] < x)
        {
            ans[index] = A[i];
            x = A[i];
            index--;
        }
    }
    for (int i = 1; i <= maxLen; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

int binarySearch(int l, int r, int now)
{
    int mid;

    while (l < r)
    {
        mid = (l + r) / 2;
        if (B[mid] < now)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}