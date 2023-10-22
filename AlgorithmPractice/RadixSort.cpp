#include <stdio.h>
#include <vector>

#define BUCKET_NUM  10

void RadixSort(int arr[], int num, int maxLen)
{
    // �Ű����� maxLen���� ���Ĵ�� �� ���� �� �������� ���� ������ ����
    std::vector<int> buckets[BUCKET_NUM];
    int i;
    int pos;
    int divfac = 1;
    int radix;

    for (i = 0; i < BUCKET_NUM; i++)
        buckets[i].reserve(num);

    // ���� �� �������� ���̸�ŭ �ݺ�
    for (pos = 0; pos < maxLen; pos++)
    {
        // ���Ĵ���� ����ŭ �ݺ�
        for (i = 0; i < num; i++)
        {
            // N��° �ڸ��� ���� ����
            radix = (arr[i] / divfac) % 10;
            // ������ ���ڸ� �ٰŷ� ��Ŷ�� ������ ����
            buckets[radix].push_back(arr[i]);
        }

        int cnt = 0;
        // ��Ŷ ����ŭ �ݺ�
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