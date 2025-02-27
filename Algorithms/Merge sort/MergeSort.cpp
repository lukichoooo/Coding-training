#include <iostream>
using namespace std;

void merge(int *arr, int *leftArr, int *rightArr, int leftSize, int rightSize)
{
    int i = 0, l = 0, r = 0;

    while (r < rightSize && l < leftSize)
    {
        leftArr[l] < rightArr[r] ? arr[i++] = leftArr[l++] : arr[i++] = rightArr[r++];
    }
    while (l < leftSize)
    {
        arr[i++] = leftArr[l++];
    }
    while (r < rightSize)
    {
        arr[i++] = rightArr[r++];
    }
}

void mergeSort(int *arr, int size)
{
    if (size < 2)
        return;

    int leftSize = size / 2;
    int rightSize = size - size / 2;

    int *leftArr = new int[leftSize];
    int *rightArr = new int[rightSize];

    for (size_t i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[i];
    }
    for (size_t i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[leftSize + i];
    }

    mergeSort(leftArr, leftSize);
    mergeSort(rightArr, rightSize);
    merge(arr, leftArr, rightArr, leftSize, rightSize);

    delete[] leftArr;
    delete[] rightArr;
}

int main()
{
    int arr[] = {12, 53, 52, 1254, 25, 55, 1, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int k : arr)
    {
        cout << k << ", ";
    }

    cout << endl
         << endl;

    mergeSort(arr, size);

    for (int k : arr)
    {
        cout << k << ", ";
    }

    return 0;
}