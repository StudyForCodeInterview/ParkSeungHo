// 선분 교차 2 (17387)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3);

int main(void)
{
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;

    long long ret1 = CCW(x1, y1, x2, y2, x3, y3);
    long long ret2 = CCW(x1, y1, x2, y2, x4, y4);
    long long ret3 = CCW(x3, y3, x4, y4, x1, y1);
    long long ret4 = CCW(x3, y3, x4, y4, x2, y2);
    if (ret1 * ret2 < 0 && ret3 * ret4)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    long long ret;

    ret = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    return ret;
}