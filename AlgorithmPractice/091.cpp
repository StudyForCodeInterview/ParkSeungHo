// 가장 큰 정사각형 찾기 (1915)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int D[1001][1001];
//int GetSerialSize(int row, int col, int size);
//
//int main(void)
//{
//    int i, j;
//    int n, m;
//    int max = 0;
//    string str;
//
//    cin >> n >> m;
//    for (i = 1; i <= n; i++)
//    {
//        cin >> str;
//        for (j = 1; j <= m; j++)
//        {
//            D[i][j] = str[j - 1] - '0';
//        }
//    }
//
//    for (i = 1; i <= n; i++)
//    {
//        for (j = 1; j <= m; j++)
//        {
//            int serialSize = GetSerialSize(i, j, D[i - 1][j - 1] + 1);
//            if (D[i][j] != 0 && serialSize == D[i - 1][j - 1] + 1)
//            {
//                D[i][j] = D[i - 1][j - 1] + 1;
//            }
//            else if (D[i][j] != 0 && D[i-1][j] != 0 &&)
//            {
//                D[i][j] = 
//            }
//            if (D[i][j] > max)
//                max = D[i][j];
//        }
//    }
//
//    cout << max * max << endl;
//    return 0;
//}
//
//int GetSerialSize(int row, int col, int size)
//{
//    int i;
//    int count = 0;
//    for (i = 0; i < size; i++)
//    {
//        if (D[row][col - i] == 0 || D[row - i][col] == 0)
//        {
//            break;
//        }
//        count++;
//    }
//    return count;
//}

int main(void)
{
    int i, j;
    int n, m;
    int max = 0;
    string str;

    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> str;
        for (j = 1; j <= m; j++)
        {
            D[i][j] = str[j - 1] - '0';
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (D[i][j] != 0)
            {
                D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j], D[i][j - 1])) + 1;
            }
            if (D[i][j] > max)
                max = D[i][j];
        }
    }

    cout << max * max << endl;
    return 0;
}