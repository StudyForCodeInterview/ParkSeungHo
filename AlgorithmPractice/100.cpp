// 다각형의 넓이 구하기 (2166) 못품
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

//class Node
//{
//public:
//    long x;
//    long y;
//    double distance;
//};
//
//bool comp(const Node& lhs, const Node& rhs)
//{
//    return lhs.distance < rhs.distance;
//}
//
//vector<Node> vec;
//
//int main(void)
//{
//    int N;
//
//    cin >> N;
//    vec.resize(N);
//    for (int i = 0; i < N; i++)
//    {
//        cin >> vec[i].x >> vec[i].y;
//        vec[i].distance = sqrt(pow(vec[i].x, 2) + pow(vec[i].y, 2));
//    }
//
//    sort(vec.begin(), vec.end(), comp);
//
//    return 0;
//}

long CCW2(long x1, long y1, long x2, long y2)
{
    return x1 * y2 - x2 * y1;
}
int main(void)
{
    int N;
    double sum = 0;
    int x1, y1, x2, y2;
    int firstX, firstY;

    scanf("%d", &N);
    scanf("%d %d", &x2, &y2);
    firstX = x2;
    firstY = y2;
    for (int i = 1; i < N; i++)
    {
        scanf("%d %d", &x1, &y1);
        sum += CCW2(x1, y1, x2, y2);
        x2 = x1;
        y2 = y1;
    }
    sum += CCW2(firstX, firstY, x2, y2);
    sum = abs(sum) / 2.0;
    printf("%.1lf\n", sum);
    return 0;
}