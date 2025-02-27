import java.util.Arrays;

public class HeapTest {
    public static void main(String[] args) {
        
    }
}

class MinHeap {
    private int capacity = 10;
    private int size = 0;

    int[] arr = new int[capacity];

    private int getLeftChildIndex(int pi) {
        return 2 * pi + 1;
    }

    private int getRightChildIndex(int pi) {
        return 2 * pi + 2;
    }

    private int getParentIndex(int ci) {
        return (ci - 1) / 2;
    }

    private boolean hasLeftChild(int index) {
        return getLeftChildIndex(index) < size;
    }

    private boolean hasRightChild(int index) {
        return getRightChildIndex(index) < size;
    }

    private boolean hasParent(int index) {
        return index > 0;
    }

    private int leftChild(int index) {
        return arr[getLeftChildIndex(index)];
    }

    private int rightChild(int index) {
        return arr[getRightChildIndex(index)];
    }

    private int parent(int index) {
        return arr[getParentIndex(index)];
    }

    private void swap(int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    private void ensureCapacity() {
        if (capacity >= size)
            return;
        capacity *= 2;
        int[] tempArr = Arrays.copyOf(arr, capacity);
        arr = tempArr;
    }

    public int peek() {
        if (size == 0)
            throw new IllegalStateException();
        return arr[0];
    }

    public int poll() {
        if (size == 0)
            throw new IllegalStateException();
        int temp = arr[0];
        swap(0, size);
        size--;
        heapifyDown();
        return temp;
    }

    public void add(int item) {
        ensureCapacity();
        arr[size] = item;
        size++;
        heapifyUp();
    }

    private void heapifyUp() {
        int i = size - 1;
        while (hasParent(i) && arr[i] < arr[getParentIndex(i)]) {
            swap(i, getParentIndex(i));
            i = getParentIndex(i);
        }
    }

    private void heapifyDown() {
        int i = 0;

        while (hasLeftChild(i)) {
            int smallestChildIndex = leftChild(i);
            if (hasRightChild(i) && rightChild(i) < leftChild(i))
                smallestChildIndex = rightChild(i);
            if (parent(i) < arr[smallestChildIndex])
                break;
            swap(smallestChildIndex, getParentIndex(i));
            i = smallestChildIndex;
        }
    }

}