// 최장 공통부분 수열 찾기 (LCS 2)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

//int i, j;
//string str1;
//string str2;
//bool map[1001][1001];
//int maxLen;
//string answer;
//string D[1001][1001];
//string LCS();
//
//int main(void)
//{
//    answer.reserve(1001);
//    cin >> str1;
//    cin >> str2;
//
//    for (i = 1; i <= str1.length(); i++)
//    {
//        for (j = 1; j <= str2.length(); j++)
//        {
//            if (str1[i] == str2[j])
//            {
//                map[j][i] = true;
//            }
//        }
//    }
//
//    answer = LCS();
//    cout << answer.length() << endl;
//    cout << answer << endl;
//    return 0;
//}
//
//string GetMaxLenString(int colNum, int rowNum)
//{
//    for (i = colNum; i >= 0; i--)
//    {
//        for (j = rowNum; j >= 0; j--)
//        {
//            if ()
//        }
//    }
//}
//
//string LCS()
//{
//    for (i = 1; i < str1.length(); i++)
//    {
//        for (j = 1; j < str2.length(); j++)
//        {
//            if (map[j][i] == true)
//            {
//                D[j][i] = GetMaxLenString(i - 1, j - 1);
//            }
//        }
//    }
//}

int N;
int DP[1001][1001];
string A, B;
vector<char> Path;
void getText(int r, int c);
int i, j;
int main(void)
{
    cin >> A >> B;

    for (i = 1; i <= A.size(); i++)
    {
        for (j = 1; j <= B.size(); j++)
        {
            if (A[i - 1] == B[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;    // 같은 문자열일 경우 왼쪽 대각선 값 + 1
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]); // 다르면 왼쪽과 위의 값 중 큰 수
        }
    }

    cout << DP[A.size()][B.size()] << endl;
    getText(A.size(), B.size());

    for (i = Path.size() - 1; i >= 0; i--)
        cout << Path[i];
    cout << endl;
    return 0;
}

void getText(int r, int c)
{
    if (r == 0 || c == 0)
        return;

    if (A[r - 1] == B[c - 1])   // 같으면 LCS에 기록하고 왼쪽 위로 이동
    {
        Path.push_back(A[r - 1]);
        getText(r - 1, c - 1);
    }
    else
    {
        if (DP[r - 1][c] > DP[r][c - 1])    // 다르면 왼쪽과 위쪽 중 큰 수로 이동
            getText(r - 1, c);
        else
            getText(r, c - 1);
    }
}