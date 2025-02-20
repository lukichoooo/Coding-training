#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

bool binarySearch(int *arr, int target, int size);
bool altBinarySearch(int *arr, int left, int right, int target);

int main()
{
    const int size = 20;
    int arr[size];

    // Seed the random number generator
    srand(time(0));

    // Fill the array with random elements between 1 and 100
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    arr[0] = 77;

    sort(arr, arr + size);

    // Print the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << (altBinarySearch(arr, 0, size - 1, 77) ? "yes" : "no");

    return 0;
}

bool binarySearch(int *arr, int target, int size)
{
    size_t left = 0, right = size - 1, mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] < target)
            left = mid + 1;
        else if (arr[mid] > target)
            right = mid - 1;
        else
            return true;
    }
    return false;
}

// uses more space,  Space Complexity: O(log n)
// this is because it has to give the return value to the previous call of recursive function
bool altBinarySearch(int *arr, int left, int right, int target)
{
    if (left > right)
    {
        return false; // Not found
    }

    size_t mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return true; // Found target
    else if (arr[mid] > target)
    {
        return altBinarySearch(arr, left, mid - 1, target);
    }
    else
        return altBinarySearch(arr, mid + 1, right, target);
}
