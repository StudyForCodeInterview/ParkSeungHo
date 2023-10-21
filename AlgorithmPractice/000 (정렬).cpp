#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>

#define TEST

void QuickSort(int* arr, int N);
void BubbleSort(int* arr, int N);
void SelectionSort(int* arr, int N);
void PrintArray(int* arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}
void test();

int main(void)
{
#ifndef TEST
    int N;
    scanf_s("%d", &N);
    int* arr = (int*)malloc(sizeof(N));
    if (arr == nullptr)
        return -1;

    for (int i = 0; i < N; i++)
    {
        scanf_s("%d", &arr[i]);
    }
#else
    test();
#endif
    
    return 0;
}

void QuickSort(int* arr, int N)
{
    //QuickSortRecursive(0, N - 1, )
}

void BubbleSort(int* arr, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void SelectionSort(int* arr, int N)
{
    int minIndex;

    for (int i = 0; i < N - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void InsertSort(int* arr, int N)
{
    int tmp;
    for (int i = 1; i < N; i++)
    {
        tmp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > tmp)
                arr[j + 1] = arr[j];
            else
            {
                arr[j + 1] = tmp;
                break;
            }
        }
    }
}

//void InsertSort2(int arr[], int N)
//{
//    int i, j;
//    int insData;
//
//    for (i = 1; i < N; i++)
//    {
//        insData = arr[i];
//        for (j = i - 1; j >= 0; j--)
//        {
//            if (arr[j] > insData)
//                arr[j + 1] = arr[j];
//            else
//                break;
//        }
//        arr[j + 1] = insData;
//    }
//}

void test()
{
    const int N = 10;
    int arr[N];
    int cpy[N];
    int cpy2[N];

    srand(NULL);
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }
    memcpy(cpy, arr, sizeof(int) * N);
    memcpy(cpy2, arr, sizeof(int) * N);

    std::cout << "Bubble Sort" << std::endl;
    PrintArray(arr, N);

    BubbleSort(arr, N);
    PrintArray(arr, N);
    std::cout << std::endl;

    std::cout << "Selection Sort" << std::endl;
    PrintArray(cpy, N);

    SelectionSort(cpy, N);
    PrintArray(cpy, N);
    std::cout << std::endl;

    assert(memcmp(arr, cpy, sizeof(int) * N) == 0);

    std::cout << "Insertion Sort" << std::endl;
    PrintArray(cpy2, N);

    InsertSort(cpy2, N);
    PrintArray(cpy2, N);
    std::cout << std::endl;

    assert(memcmp(arr, cpy2, sizeof(int) * N) == 0);

}

static void CopyArray(int* src, int* dst, int N)
{
    for (int i = 0; i < N; i++)
    {
        dst[i] = src[i];
    }
}

//// HeapSort.c (+ UsefulHeap.c)
//typedef int HData;
//int PriComp(int n1, int n2)
//{
//    return n2 - n1; // �������� ������ ���� ����
//    // return n1 - n2;
//}
//
//void HeapSort(int arr[], int n, PriorityComp pc)
//{
//    Heap heap;
//    int i;
//
//    HeapInit(&heap, pc);
//
//    // ���Ĵ���� ������ ���� �����Ѵ�.
//    for (i = 0; i < n; i++)
//        HInsert(&heap, arr[i]);
//
//    // ������� �ϳ��� ������ ������ �ϼ��Ѵ�.
//    for (i = 0; i < n; i++)
//        arr[i] = HDelete(&heap);
//}

// MergeSort
// 1�ܰ� - ����(Divide)
// 2�ܰ� - ����(Conquer)
// 3�ܰ� - ����(Combine)

void MergeTwoArea(int* arr, int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    // �ƿ� ���ο� �迭 ����.
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

// QuickSort
void swap(int arr[], int idx1, int idx2)
{
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left];  // ���� ������ �ǹ����� ��.
    int low = left + 1;
    int high = right;

    // [3, 3, 3] �۵� ����
    //while (low <= high)
    //{
    //    // �ǹ����� ū ���� ã�� ����
    //    while (pivot > arr[low])
    //        low++;
    //    // �ǹ����� ���� ���� ã�� ����
    //    while (pivot < arr[high])
    //        high--;
    //    if (low <= high)
    //        swap(arr, low, high);
    //}
    while (low <= high)
    {
        while (pivot >= arr[low] && low <= right)
            low++;
        while (pivot <= arr[high] && high >= (left + 1))
            high--;
        if (low <= high)
            swap(arr, low, high);
    }

    swap(arr, left, high);  // �ǹ��� high�� ����Ű�� ��� ��ȯ.
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
        // K��° �� (A[K-1])�� ���ϴ� ���̶�� �̷��� ����ȭ ����.
        /*int pivot = Partition(arr, left, right);
        if (pivot == K - 1)
            return;
        else if (K - 1 < pivot)
            QuickSort(arr, left, pivot - 1);
        else
            QuickSort(arr, pivot + 1, right);*/
    }
}