// CCW (11758)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3);

int main(void)
{
    int x1, x2, x3, y1, y2, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    int ret = CCW(x1, y1, x2, y2, x3, y3);
    if (ret < 0)
        cout << -1 << endl;
    else if (ret > 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}

int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int ret;

    ret = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    return ret;
}