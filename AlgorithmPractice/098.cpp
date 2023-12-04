// ���� ���� 2 (17387)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>
using namespace std;

int proc(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4);
long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3);

int main(void)
{
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    /*cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    cout << proc(x1, y1, x2, y2, x3, y3, x4, y4) << endl;*/

    assert(proc(1, 1, 5, 5, 1, 5, 5, 1) == 1);
    assert(proc(1, 1, 5, 5, 6, 10, 10, 6) == 0);
    assert(proc(1, 1, 5, 5, 5, 5, 1, 1) == 1);
    assert(proc(1, 1, 5, 5, 3, 3, 5, 5) == 1);
    assert(proc(1, 1, 5, 5, 3, 3, 1, 3) == 1);
    assert(proc(1, 1, 5, 5, 5, 5, 9, 9) == 1);
    assert(proc(1, 1, 5, 5, 6, 6, 9, 9) == 0);
    assert(proc(1, 1, 5, 5, 5, 5, 1, 5) == 1);
    assert(proc(1, 1, 5, 5, 6, 6, 1, 5) == 0);
    assert(proc(1, 1, 2, 2, 3, 3, 4, 4) == 0);
    assert(proc(1, 1, 3, 3, 2, 2, 4, 4) == 1);
    assert(proc(-3, -3, -1, -1, -2, -2, 0, 0) == 1);
    assert(proc(1, 1, 10, 10, 2, 2, 3, 3) == 1);
    assert(proc(2, 2, 3, 3, 1, 1, 4, 4) == 1);
    assert(proc(0, 0, 0, 10, 0, 1, 0, 9) == 1); // ��� ���� ������ ��, x�� �Ӹ� �ƴ϶� y���� ���ؾ� �ϴ� ���� 
    assert(proc(0, 0, 0, 3, 0, 1, 0, 4) == 1);
    assert(proc(0, 1, 0, 2, 0, 0, 0, 3) == 1);  
    assert(proc(0, 0, 0, 1, 0, 2, 0, 3) == 0);  // ��� ���� ������ ��, x�� �Ӹ� �ƴ϶� y���� ���ؾ� �ϴ� ����
    assert(proc(0, 0, 10, 0, 1, 0, 2, 0) == 1);
    assert(proc(0, 0, 2, 0, 1, 0, 3, 0) == 1);
    return 0;
}

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    long long ret;

    ret = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    if (ret > 0)
        return 1;
    else if (ret < 0)
        return -1;
    else
        return 0;
}

int proc(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4)
{
    if ((x1 == x3 && y1 == y3) || (x1 == x4 && y1 == y4) || (x2 == x3 && y2 == y3) || (x2 == x4 && y2 == y4))
    {
        return 1;
    }

    long long ret1 = CCW(x1, y1, x2, y2, x3, y3);
    long long ret2 = CCW(x1, y1, x2, y2, x4, y4);
    long long ret3 = CCW(x3, y3, x4, y4, x1, y1);
    long long ret4 = CCW(x3, y3, x4, y4, x2, y2);

    if (ret1 * ret2 == 0 && ret3 * ret4 == 0)
    {
        /// ***** �ֵǴ��� �𸣰ڴµ� �ϴ� ��. 
        /// Ư�� ���а� ��ǥ�� max���� Ÿ ������ min������ �׻� ũ�ų� ������ ���� ����.
        if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2)
            && min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2))
            return 1;

        return 0;
    }
    else if (ret1 * ret2 <= 0 && ret3 * ret4 <= 0)
        return 1;
    else
        return 0;
}