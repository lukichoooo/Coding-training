#include <iostream>

using namespace std;

void merge(int *arr, size_t start, size_t mid, size_t end)
{
    int *temp = new int[end - start + 1];

    size_t l = start, r = mid + 1, i = 0; // 'l' will copy from left "sub array" and 'r' from right, they will copy into arr[i]
    while (l <= mid && r <= end)
        temp[i++] = (arr[l] < arr[r]) ? arr[l++] : arr[r++];
    while (l <= mid)
        temp[i++] = arr[l++];
    while (r <= end)
        temp[i++] = arr[r++];

    i = 0;
    while (i <= (end - start))
    {
        arr[start + i] = temp[i]; // if anyones reading this shit for some reason, when u replace the i++; with psot increment inside temp[i++] it doesnt work
        i++;
    }
    delete[] temp;
}

void mergeSort(int *arr, size_t l, size_t r) // left and right index
{
    if (l >= r) // base case
        return;

    size_t mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);     // left array
    mergeSort(arr, mid + 1, r); // right array
    merge(arr, l, mid, r);      // full Array, start of left array, mid point, end of right array
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

    mergeSort(arr, 0, size - 1);

    for (int k : arr)
    {
        cout << k << ", ";
    }

    return 0;
}