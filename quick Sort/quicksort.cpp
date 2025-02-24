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
    int p = arr[l]; // Pivot
    size_t i = l, j = r;

    while (i < j)
    {
        while (i <= r && arr[i] <= p) i++; // Find element > pivot
        while (j >= l && arr[j] > p) j--;  // Find element <= pivot

        if (i < j)
            swap(arr[i], arr[j]); // Swap misplaced elements
    }

    swap(arr[l], arr[j]); // Place pivot at correct position
    return j; // Return pivot index
}

void quickSort(int *arr, size_t l, size_t r)
{
    if (l < r)
    {
        size_t j = partition(arr, l, r);
        if (j > l) quickSort(arr, l, j - 1);
        if (j + 1 < r) quickSort(arr, j + 1, r);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}