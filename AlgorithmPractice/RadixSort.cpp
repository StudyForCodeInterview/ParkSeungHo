#include <stdio.h>
#include <vector>

#define BUCKET_NUM  10

void RadixSort(int arr[], int num, int maxLen)
{
    // 매개변수 maxLen에는 정렬대상 중 가장 긴 데이터의 길이 정보가 전달
    std::vector<int> buckets[BUCKET_NUM];
    int i;
    int pos;
    int divfac = 1;
    int radix;

    for (i = 0; i < BUCKET_NUM; i++)
        buckets[i].reserve(num);

    // 가장 긴 데이터의 길이만큼 반복
    for (pos = 0; pos < maxLen; pos++)
    {
        // 정렬대상의 수만큼 반복
        for (i = 0; i < num; i++)
        {
            // N번째 자리의 숫자 추출
            radix = (arr[i] / divfac) % 10;
            // 추출한 숫자를 근거로 버킷에 데이터 저장
            buckets[radix].push_back(arr[i]);
        }

        int cnt = 0;
        // 버킷 수만큼 반복
        for (i = 0; i < BUCKET_NUM; i++)
        {
            int size = buckets[i].size();
            for (int j = 0; j < size; j++)
            {
                arr[cnt++] = buckets[i][j]; /// ?!?!
            }
            buckets[i].clear();
        }

        divfac *= 10;
    }
}

int main(void)
{
    int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

    int len = sizeof(arr) / sizeof(int);
    int i;

    RadixSort(arr, len, 5);

    for (i = 0; i < len; i++)
        printf("%d\n", arr[i]);
    return 0;
}