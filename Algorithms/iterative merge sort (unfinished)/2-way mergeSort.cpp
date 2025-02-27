#include <iostream>
#include <cmath> // Include cmath for logarithm functions
using namespace std;

void merge(int *arr, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Create temporary arrays
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Merge the two sorted arrays back into arr
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    // Copy remaining elements (if any)
    while (i < leftSize)
        arr[k++] = leftArr[i++];
    while (j < rightSize)
        arr[k++] = rightArr[j++];

    // Free memory
    delete[] leftArr;
    delete[] rightArr;
}

void IMergeSort(int *arr, int size)
{
    int cSize = 1;
    for (cSize = 2; cSize < size; cSize *= 2) // currentSIze shows size of each mini array
    {
        for (int i = 0; i + cSize - 1 < size; i += cSize) // i iterates over each sub arrays first value
        {
            int left = i;   // first element
            int right = i + cSize - 1;  // last element in sub arrays
            int mid = (left + right) / 2;   // middle element it sub arrays

            merge(arr, left, mid, right);
        }
    }
    if (cSize / 2 < size)
        merge(arr, 0, cSize / 2, size - 1);
}

// current is the size of each array
// for each arr we want to sort them while merging
// 1)   compare array[0] to array[1] and swap if neccesery
//  array[2] to array[3], [4] to [5] .... [6] to [7].

// 2)   now we should merge them again
//  compare [0][1] to [2][3], [4][5] to [6][7]
//  merge again to get [0][1][2][3] and [4][5][6][7] and do the same ...

// outer loop current should loop for (log n) times (n = numbers)

// now we have to repeat over each array,
//  1st - [0], [1], [2] .... [7]

//  2nd - [0][1], [2][3], [4][5], [6][7].
//  3th - [0][1][2][3], [4][5][6][7]
//  4th - [0][1][2][3][4][5][6][7]

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

    IMergeSort(arr, size);

    for (int k : arr)
    {
        cout << k << ", ";
    }

    return 0;
}
