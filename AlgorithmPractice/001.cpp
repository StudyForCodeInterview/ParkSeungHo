// 11720 ������ �� ���ϱ�
#include <iostream>
#include <string>

int main(void)
{
    std::string str;
    int n;
    int sum;

    std::cin >> n;
    std::cin >> str;

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += str[i] - '0';
    }

    std::cout << sum << std::endl;
    return 0;
}