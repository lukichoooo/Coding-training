#include <iostream>
#include <algorithm>

using namespace std;

class MinIntHeap
{
private:
    size_t capacity = 10;
    size_t size = 0;

    int *items;

    size_t getLeftChildIndex(size_t i) { return 2 * i + 1; }
    size_t getRightChildIndex(size_t i) { return 2 * i + 2; }
    size_t getParentIndex(size_t i) { return (i - 1) / 2; }

    bool hasLeftChild(size_t i) { return getLeftChildIndex(i) < size; }
    bool hasRightChild(size_t i) { return getRightChildIndex(i) < size; }
    bool hasParent(size_t i) { return i > 0; }

    int leftChild(size_t i) { return items[getLeftChildIndex(i)]; }
    int rightChild(size_t i) { return items[getRightChildIndex(i)]; }
    int parent(size_t i) { return items[getParentIndex(i)]; }

    // id implement a swap method but C++ has a better one

    void ensureExtraCapacity()
    {
        if (size == capacity)
        {
            capacity *= 2;
            int *newItems = new int[capacity];
            for (size_t i = 0; i < size; i++)
            {
                newItems[i] = items[i];
            }
            delete[] items;
            items = newItems;
        }
    }

public:
    size_t peek()
    {
        if (size == 0)
            throw runtime_error("Heap is empty");
        return items[0];
    }

    size_t poll()
    { // remove root element (min)
        if (size == 0)
            throw runtime_error("Heap is empty");
        int item = items[0];        // get root
        items[0] = items[size - 1]; // replace root with the last right element in the tree and in array
        size--;
        heapifyDown(); // fix the heap after removal of root element
                       // Down because we have replaced the first element items[0] (root)
        return item;
    }

    void add(int item)
    {
        ensureExtraCapacity();
        items[size] = item; // add item to the last spot
        size++;
        heapifyUp(); // Up because we added a new last element items[size] (child)
    }

    void heapifyUp() // last element to first
    {
        size_t i = size - 1;                         // starting index of heapifyUp()
        while (hasParent(i) && parent(i) > items[i]) // since its min heap we move small items up
        {
            swap(items[i], items[getParentIndex(i)]); // swap item and its parent
            i = getParentIndex(i);                    // change i index since it has been changed by the swap
        }
    }

    void heapifyDown() // first element to last
    {
        size_t i = 0;
        while (hasLeftChild(i)) // chekc only lef coz, if we dont have left we def dont have right in heap
        {
            int smallerChildIndex = getLeftChildIndex(i); // set it as left before checking if we even have right
            if (hasRightChild(i))
                smallerChildIndex = (rightChild(i) < leftChild(i) ? getRightChildIndex(i) : getLeftChildIndex(i));
            if (items[smallerChildIndex] > items[i])
                break; // if its already at the right place break
            else
            {
                swap(items[smallerChildIndex], items[i]);
                i = smallerChildIndex;
            }
        }
    }
};

class MaxIntHeap
{
private:
    size_t capacity = 10;
    size_t size = 0;

    int *arr;

    size_t getLeftChildIndex(size_t i) { return 2 * i + 1; }
    size_t getRightChildIndex(size_t i) { return 2 * i + 2; }
    size_t getParentIndex(size_t i) { return (i - 1) / 2; }

    bool hasLeftChild(size_t i) { return getLeftChildIndex(i) < size; }
    bool hasRightChild(size_t i) { return getRightChildIndex(i) < size; }
    bool hasParent(size_t i) { return i > 0; }

    int leftChild(size_t i) { return arr[getLeftChildIndex(i)]; }
    int rightChild(size_t i) { return arr[getRightChildIndex(i)]; }
    int parent(size_t i) { return arr[getParentIndex(i)]; }

    int peek()
    {
        if (size == 0)
            throw runtime_error("Heap is empty");
        return arr[0];
    }

    void ensureCapacity()
    {
        if (capacity > size)
            return;
        capacity *= 2;
        int *newArr = new int[capacity];
        for (size_t i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
            if (capacity <= size)
                delete[] arr;
            arr = newArr;
        }
    }

public:
    void add(int item)
    {
        ensureCapacity();
        arr[size] = item;
        size++;
        heapifyUp();
    }

    void poll()
    {
        if (size == 0)
            throw runtime_error("Heap is empty");
        swap(arr[size - 1], arr[0]);
        size--;
        heapifyDown();
    }

    void heapifyUp()
    {
        size_t i = size - 1;
        while (hasParent(i) && arr[i] > parent(i))
        {
            swap(arr[i], arr[getParentIndex(i)]);
            i = getParentIndex(i);
        }
    }

    void heapifyDown()
    {
        size_t i = 0;
        while (hasLeftChild(i))
        {
            size_t biggerChildIndex = getLeftChildIndex(i);
            if (hasRightChild(i) && rightChild(i) > leftChild(i))
                biggerChildIndex = getRightChildIndex(i);
            if (arr[i] > arr[biggerChildIndex])
                break;
            swap(arr[i], arr[biggerChildIndex]);
            i = biggerChildIndex;
        }
    }
};

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}