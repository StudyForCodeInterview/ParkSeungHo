// 문자열 찾기 (트라이) (14425)
#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//
//set<string> dictionary;
//
//int main(void)
//{
//    int N, M;
//    int i, j;
//    char str[501];
//    int cnt;
//    
//    scanf("%d %d", &N, &M);
//    for (i = 0; i < N; i++)
//    {
//        scanf("%s", str);
//        dictionary.insert(str);
//    }
//    
//    cnt = 0;
//    for (int i = 0; i < M; i++)
//    {
//        scanf("%s", str);
//        if (dictionary.find(str) != dictionary.end())
//        {
//            cnt++;
//        }
//    }
//
//    printf("%d\n", cnt);
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node* next[26];
    bool isEnd;
    Node() : isEnd(false) { fill(next, next + 26, nullptr); }
    ~Node() { for (auto& child : next) delete child; }
    void insert(const char* key)
    {
        if (*key == 0)
            isEnd = true;
        else
        {
            int next_index = *key - 'a';
            if (next[next_index] == nullptr)
                next[next_index] = new Node;
            next[next_index]->insert(key + 1);
        }
    }
    Node* find(const char* key)
    {
        if (*key == 0)
            return this;
        int next_index = *key - 'a';

        if (next[next_index] == nullptr)
            return nullptr;
        return next[next_index]->find(key + 1);
    }
};
int main(void)
{
    int N, M;
    char text[501];

    scanf("%d %d", &N, &M);
    Node* root = new Node;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", text);
        root->insert(text);
    }

    int count = 0;

    for (int i = 0; i < M; i++)
    {
        scanf("%s", text);
        Node* result = root->find(text);

        if (result != nullptr && result->isEnd == true)
            count++;
    }

    printf("%d\n", count);
    return 0;
}