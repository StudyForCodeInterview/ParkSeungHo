// 문자열 찾기 (트라이) (14425)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> tree;

int main(void)
{
    int N, M;
    int i, j;
    char str[501];
    tree.resize(27);    // tree[26]을 루트로 함.
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        scanf("%s", str);
        while (str[j] != '\0')
        {
            char c = str[j] - 'a';
            tree[c].push_back()
        }
    }
    for (int i = 0; i < M; i++)
    {

    }
    return 0;
}