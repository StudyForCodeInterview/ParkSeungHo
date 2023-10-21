// 내림차순으로 자릿수 정렬하기 (1427)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void)
{
    std::string str;

    std::cin >> str;

    int strlen = str.size();
    bool changed = false;
    for (int i = 0; i < strlen - 1; i++)
    {
        changed = false;
        for (int j = 0; j < strlen - 1 - i; j++)
        {
            if (str[j] < str[j + 1])
            {
                changed = true;
                char tmp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
        }
        if (changed == false)
            break;
    }

    std::cout << str << std::endl;
    return 0;
}