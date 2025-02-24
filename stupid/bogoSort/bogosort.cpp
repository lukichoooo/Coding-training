#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void bogosort(int *arr, size_t size);
bool isSorted(int *arr, size_t size);

int getRand(int SIZE)
{
    return rand() % SIZE;
}

int main()
{
    // Seed the random number generator
    srand(time(0));
    
    int arr[] = {99, 15, 23, 1, 44};

    cout << "Original array: ";
    for (int k : arr)
        cout << k << " ";
    cout << endl;

    bogosort(arr, 5);

    cout << "Sorted array: ";
    for (int k : arr)
        cout << k << " ";
    cout << endl;
    
    return 0;
}

void bogosort(int *arr, size_t size)
{
    while (!is_sorted(arr, arr + size))
    {
        // Randomly shuffle the array
        for (size_t i = 0; i < size; i++)  // n
        {
            int j = getRand(size);
            swap(arr[i], arr[j]);
        }
    }
}
