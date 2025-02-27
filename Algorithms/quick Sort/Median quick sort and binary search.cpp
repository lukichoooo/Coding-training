#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

size_t partition(int *arr, size_t l, size_t r)
{
    size_t i = l, j = r, mid = (l + (r - l) / 2);

    swap(arr[mid], arr[r]); // putting out Median-Pivot at last place

    while (i < j)
    {
        while (arr[i] < arr[r] && i < r)
            i++;
        while (arr[j] > arr[r] && j >= l)
            j--;
        if (i < j)
        {
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[r], arr[j]);
    return j;
}

void quickSort(int *arr, size_t l, size_t r)
{
    if (r > l)
    {
        size_t j = partition(arr, l, r);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, r);
    }
}

int binarySearch(int *arr, int target, size_t l, size_t r)
{
    size_t mid = l + (r - l) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, target, l, mid - 1);
    else
        return binarySearch(arr, target, mid + 1, r);
    return -1; // not found
}

int search(int *arr, int target, size_t size)
{
    quickSort(arr, 0, size - 1);

    printArray(arr,size);   // check sorted array

    printArray(arr,size);
    return binarySearch(arr, target, 0, size);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 1};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    cout << search(arr, 5, size);

    return 0;
}