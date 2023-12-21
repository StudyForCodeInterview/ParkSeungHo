// 11720 숫자의 합 구하기
//#include <iostream>
//#include <string>
//
//int main(void)
//{
//    std::string str;
//    int n;
//    int sum;
//
//    std::cin >> n;
//    std::cin >> str;
//
//    sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += str[i] - '0';
//    }
//
//    std::cout << sum << std::endl;
//    return 0;
//}

/*
* [string -> Number(int, long, double, float)]
* string sNum = "1234"; string sNum_d = "1234.56";
*
* int inum = stoi(sNum);
* long lnum = stol(sNum);
* double dnum = stod(sNum_d);
* float fnum = stof(sNum_d);
*
* [Number(int, long, double, float) -> string]
* int inum = 1234; long lnum = 1234; double dnum = 1234.56; float fnum = 1234.56f;
*
* string intToString = to_string(inum);
* 다른것들도 똑같음....
*/

#include <iostream>

using namespace std;
int main(void)
{
    string str;
    int N;
    int sum = 0;
    cin >> N;
    cin >> str;

    for (int i = 0; i < N; i++)
    {
        sum += str[i] - '0';
    }
    cout << sum << endl;
    return 0;
}