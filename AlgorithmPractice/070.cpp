// 트리 순회하기 (이진트리) (1991)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

char tree[26][2];

void PreorderTraverse(int nodeNum);
void InorderTraverse(int nodeNum);
void PostorderTraverse(int nodeNum);

int main(void)
{
    int N;
    int i;
    char c1[2], c2[2], c3[2];
    
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s %s %s", &c1, &c2, &c3);
        if (c2[0] != '.')
            tree[c1[0] - 'A'][0] = c2[0] - 'A';
        else
            tree[c1[0] - 'A'][0] = -1;
        if (c3[0] != '.')
            tree[c1[0] - 'A'][1] = c3[0] - 'A';
        else
            tree[c1[0] - 'A'][1] = -1;
    }

    PreorderTraverse(0);
    printf("\n");
    InorderTraverse(0);
    printf("\n");
    PostorderTraverse(0);
    return 0;
}

void PreorderTraverse(int nodeNum)
{
    if (nodeNum == -1)
        return;

    printf("%c", nodeNum + 'A');
    PreorderTraverse(tree[nodeNum][0]);
    PreorderTraverse(tree[nodeNum][1]);
}
void InorderTraverse(int nodeNum)
{
    if (nodeNum == -1)
        return;

    InorderTraverse(tree[nodeNum][0]);
    printf("%c", nodeNum + 'A');
    InorderTraverse(tree[nodeNum][1]);
}
void PostorderTraverse(int nodeNum)
{
    if (nodeNum == -1)
        return;

    PostorderTraverse(tree[nodeNum][0]);
    PostorderTraverse(tree[nodeNum][1]);
    printf("%c", nodeNum + 'A');
}