// K번째 수 구하기 (11004) 퀵정렬
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

void sort(int* vec, int N);
void MergeTwoArea(int* arr, int left, int mid, int right);
void MergeSort(int* arr, int left, int right);
void swap(int arr[], int idx1, int idx2);
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);

int K;

int main(void)
{
    int N;    

    scanf("%d %d", &N, &K);
    //std::vector<int> vec(N, 0);
    int* vec = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vec[i]);
    }

    //std::sort(vec.begin(), vec.end());
    sort(vec, N);

    printf("%d\n", vec[K - 1]);

    return 0;
}

void sort(int* vec, int N)
{
    //MergeSort(vec, 0, N - 1);
    QuickSort(vec, 0, N - 1);
}

void MergeTwoArea(int* arr, int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    // 아예 새로운 배열 만듦.
    int* sortArr = new int[right + 1];
    int sIdx = left;

    while (fIdx <= mid && rIdx <= right)
    {
        if (arr[fIdx] <= arr[rIdx])
            sortArr[sIdx++] = arr[fIdx++];
        else
            sortArr[sIdx++] = arr[rIdx++];
    }

    if (fIdx > mid)
    {
        for (int i = rIdx; i <= right; i++)
            sortArr[sIdx++] = arr[i];
    }
    else
    {
        for (int i = fIdx; i <= mid; i++)
            sortArr[sIdx++] = arr[i];
    }

    for (i = left; i <= right; i++)
        arr[i] = sortArr[i];

    delete sortArr;
}
void MergeSort(int* arr, int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        MergeTwoArea(arr, left, mid, right);
    }
}

void swap(int arr[], int idx1, int idx2)
{
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}
int Partition(int arr[], int left, int right)
{
    int pivot = arr[left];  // 가장 왼쪽을 피벗으로 함.
    int low = left + 1;
    int high = right;

    while (low <= high)
    {
        while (pivot >= arr[low] && low <= right)
            low++;
        while (pivot <= arr[high] && high >= (left + 1))
            high--;
        if (low <= high)
            swap(arr, low, high);
    }

    swap(arr, left, high);  // 피벗과 high가 가리키는 대상 교환.
    return high;
}
void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        /*int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);*/
        int pivot = Partition(arr, left, right);
        if (pivot == K - 1)
            return;
        else if (K - 1 < pivot)
            QuickSort(arr, left, pivot - 1);
        else
            QuickSort(arr, pivot + 1, right);
    }
}