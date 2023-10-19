// Àý´ñ°ª Èü ±¸ÇöÇÏ±â (11286)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    unsigned int index;
    int value;
    Node(unsigned int index, int value) : index(index), value(value) {}
};

struct cmp
{
    bool operator()(Node n1, Node n2)
    {
        if (n1.index == n2.index)
        {
            return n1.value > n2.value;
        }
        return n1.index > n2.index;
    }
};

int main(void)
{
    int N;
    int tmp;
    std::vector<int> answer;
    std::priority_queue<Node, std::vector<Node>, cmp> pq;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        if (tmp == 0)
        {
            int v = 0;
            if (pq.empty() != true)
            {
                Node node = pq.top();
                pq.pop();
                v = node.value;
            }
            answer.push_back(v);
        }
        else
        {
            pq.push(Node(abs(tmp), tmp));
        }
    }

    for (unsigned int i = 0; i < answer.size(); i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}