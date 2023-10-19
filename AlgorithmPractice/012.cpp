// 오큰수 구하기 (17298)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

int main(void)
{
    int N;
    std::vector<int> vec;
    std::vector<int> answer;
    std::stack<int> st;

    scanf("%d", &N);
    vec.reserve(N);
    answer.reserve(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vec[i]);
    }

    for (int i = 0; i < N; i++)
    {
        while (!st.empty() && vec[i] > vec[st.top()])
        {
            answer[st.top()] = vec[i];
            st.pop();
        }

        st.push(i); // 인덱스를 넣음.
    }

    while (!st.empty())
    {
        answer[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < N - 1; i++)
    {
            printf("%d ", answer[i]);
    }
    printf("%d", answer[N - 1]);
    return 0;
}