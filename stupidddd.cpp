#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// aaaaaaaaaaaaaaaaaaaaaa
void sillySort(int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
                swap(arr[i], arr[j]);
        }
    }
}
// aaaaaaaaaaaaaaaaaaaaaa
size_t locOfSmallest(int *arr, size_t s, size_t e)
{
    size_t i = s;
    size_t j = i;
    while (i <= e)
    {
        if (arr[i] < arr[j])
        {
            j = i;
        }
        i++;
    }
    return j;
}

void selSort(int *arr, size_t size)
{
    size_t i = 0;
    while (i < size - 1)
    {
        size_t j = locOfSmallest(arr, i, size - 1);
        swap(arr[i], arr[j]);
        i++;
    }
}
// Bubble sort
void bblSort(int *arr, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
// isertion sort
void insSort(int *arr, size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

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

    arr[0] = 88;

    // Print the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}