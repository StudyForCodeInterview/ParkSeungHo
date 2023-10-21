// 버블 정렬 프로그램1 (1377)
#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//int main(void)
//{
//    int* A;
//    int N;
//    A = new int[500001];
//    
//    scanf("%d", &N);
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", &A[i]);
//    }
//
//    bool changed = false;
//    for (int i = 1; i <= N + 1; i++)
//    {
//        changed = false;
//        for (int j = 1; j <= N - i; j++)
//        {
//            if (A[j] > A[j + 1])
//            {
//                changed = true;
//                int tmp = A[j];
//                A[j] = A[j + 1];
//                A[j + 1] = tmp;
//            }
//        }
//        if (changed == false)
//        {
//            printf("%d\n", i);
//            break;
//        }
//    }
//
//    return 0;
//}