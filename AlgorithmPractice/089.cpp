// 연속합2 (13398) 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int A[100001];
int D[100001][2];
// D[N][0] = N번째 정수까지 최대 연속합. 중간에 제거한 수 없음.
// D[N][1] = N번째 정수까지 최대 연속합. 중간에 제거한 수 있음.
int main(void)
{
    int n;
    int i;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    D[1][0] = A[1];
    D[1][1] = A[1];
    int ans = A[1];
    for (i = 2; i <= n; i++)
    {
        /*D[i][0] = D[i - 1][0] + A[i];
        if (D[i - 1][0] > D[i - 1][1] + A[i])
            D[i][1] = D[i - 1][0];
        else
            D[i][1] = D[i - 1][1] + A[i];*/
        D[i][0] = max(D[i - 1][0] + A[i], A[i]);    // 여기부터 다시 시작하는 코드를 안넣어서 작동 안됬음.
        D[i][1] = max(D[i - 1][0], D[i - 1][1] + A[i]);
        ans = max(ans, max(D[i][0], D[i][1]));
    }

    printf("%d\n", ans);
    return 0;
}