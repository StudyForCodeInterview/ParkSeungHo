// 스택으로 수열 만들기 (1874)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

int main(void)
{
    int n;
    int tmp;
    std::stack<int> st;
    std::vector<int> vec;
    std::vector<char> answer;

    scanf("%d", &n);
    vec.reserve(n);
    answer.reserve(1000000);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
    }

    int i = 0;
    int cnt = 1;
    while (1)
    {
        if (cnt > n)
            break;
        if (vec[i] == cnt)
        {
            // st.push(cnt);
            // st.pop();    push했다 pop한것으로 침
            answer.push_back('+');
            answer.push_back('-');
            i++;
            cnt++;
            continue;
        }
        else if (vec[i] < cnt)
        {
            if (vec[i] != st.top())
            {
                printf("NO\n");
                return 0;
            }
            st.pop();
            answer.push_back('-');
            i++;
            continue;
        }

        // vec[i] > cnt
        answer.push_back('+');
        st.push(cnt);
        cnt++;
    }

    while (!st.empty())
    {
        if (st.top() != vec[i])
        {
            printf("NO\n");
            return 0;
        }
        else
        {
            st.pop();
            answer.push_back('-');
            i++;
        }
    }

    for (unsigned int i = 0; i < answer.size(); i++)
        printf("%c\n", answer[i]);

    return 0;
}