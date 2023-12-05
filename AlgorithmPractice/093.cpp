// DDR을 해보자 (2342)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>
using namespace std;

//int leftfoot;
//int rightfoot;
//
//char arr[100001];
//int D[100001];
//
//int GetCost(int diff)
//{
//    if (diff == 1 || diff == 3)
//        return 3;
//    else if (diff == 2)
//        return 4;
//    else if (diff == 0)
//        return 1;
//    else
//        assert(false);
//}
//
//int GetMinCost(int i, int arrival)
//{
//    if (leftfoot == 0 && rightfoot == 0)
//    {
//        leftfoot = arrival;
//        return 2;
//    }
//    else if (leftfoot == 0)
//    {
//        if (rightfoot == arrival)
//            return 1;
//        leftfoot = arrival;
//        return 2;
//    }
//    else if (rightfoot == 0)
//    {
//        if (leftfoot == arrival)
//            return 1;
//        rightfoot = arrival;
//        return 2;
//    }
//    else
//    {
//        int val1 = GetCost(abs(leftfoot - arrival));
//        int val2 = GetCost(abs(rightfoot - arrival));
//        if (val1 < val2)
//        {
//            leftfoot = arrival;
//            return val1;
//        }
//        else
//        {
//            rightfoot = arrival;
//            return val2;
//        }
//    }
//}
//
//int main(void)
//{
//    int i;
//    int cnt = 1;
//
//    while (1)
//    {
//        scanf("%d", &i);
//        if (i == 0)
//            break;
//        arr[cnt++] = i;
//    }
//    cnt--;
//
//    for (i = 1; i <= cnt; i++)
//    {
//        int cost = GetMinCost(i, arr[i]);
//        D[i] = D[i - 1] + cost;
//    }
//
//    printf("%d\n", D[cnt]);
//    return 0;
//}

int D[100001][5][5] = { 2147483647, };
int arr[100001];
int map[5][5];

void mapInit(void)
{
    map[0][1] = 2; map[0][2] = 2; map[0][3] = 2; map[0][4] = 2;
    map[1][1] = 1; map[1][2] = 3; map[1][3] = 4; map[1][4] = 3;
    map[2][1] = 3; map[2][2] = 1; map[2][3] = 3; map[2][4] = 4;
    map[3][1] = 4; map[3][2] = 3; map[3][3] = 1; map[3][4] = 3;
    map[4][1] = 3; map[4][2] = 4; map[4][3] = 3; map[4][4] = 1;
}
int main(void)
{
    int n = 0, s = 1;
    mapInit();

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 100001; k++)
            {
                D[k][i][j] = 100001 * 4;
            }
        }
    }

    D[0][0][0] = 0;

    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < 5; i++)
        {
            if (n == i)
                continue;
            for (int j = 0; j < 5; j++)
            {
                // 오른발을 옮겨서 현재 모습이 되었을 때
                D[s][i][n] = min(D[s - 1][i][j] + map[j][n], D[s][i][n]);
            }
        }
        for (int j = 0; j < 5; j++)
        {
            if (n == j)
                continue;
            for (int i = 0; i < 5; i++)
                D[s][n][j] = min(D[s - 1][i][j] + map[i][n], D[s][n][j]);
        }
        s++;
    }
    s--;
    long minVal = 2147483647;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            minVal = min(minVal, (long)D[s][i][j]);
        }
    }

    cout << minVal << endl;
    return 0;
}