#include <iostream>
#include <algorithm>

using namespace std;

size_t partition(int arr[], size_t l, size_t r)
{
    swap(arr[r], arr[(l + r) / 2]); // choosing pivot as mid element and moving it at arr[r]

    size_t lw = l; // left wall

    for (size_t i = l; i < r; i++)
    {
        if (arr[r] > arr[i]) // pivot < arr[i]
        {
            swap(arr[i], arr[lw]);
            lw++;
        }
    }
    swap(arr[lw], arr[r]);
    return lw;
}


void quickSort(int arr[], size_t l, size_t r)
{
    if (l < r)
    {
        size_t i = partition(arr, l, r);
        quickSort(arr, i + 1, r);
        quickSort(arr, l, i - 1);
    }
}

int main()
{
    int arr[] = {12, 53, 52, 1254, 25, 55, 1, 2, 4};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    for (int k : arr)
    {
        cout << k << ", ";
    }

    cout << endl
         << endl;

    quickSort(arr, 0, size - 1);

    for (int k : arr)
    {
        cout << k << ", ";
    }

    return 0;
}