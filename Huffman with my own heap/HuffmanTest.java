
// learn compareTo and Map to finish this one















import java.util.Arrays;

public class HuffmanTest {
    public static void main(String[] args) {

    }
}

class Node implements Comparable<Node> {
    private final int frequency;
    private Node leftNode;
    private Node rightNode;

    public int getFrequency() {
        return frequency;
    }

    public Node(Node leftNode, Node righNode) {
        this.frequency = leftNode.getFrequency() + righNode.getFrequency();
        this.leftNode = leftNode;
        this.rightNode = rightNode;
    }

    public Node(int frequency) {
        this.frequency = frequency;
    }

    @Override
    public int compareTo(Node node) {
        return Integer.compare(frequency, node.getFrequency());
    }
}

class Leaf extends Node {
    private final char character;

    public Leaf(char character, int frequency) {
        super(frequency);
        this.character = character;
    }
}

class Huffman {
    private final String text;
    private MinHeap heap;
}

class MinHeap {
    private int capacity = 10;
    private int size = 0;

    Node[] arr = new Leaf[capacity];

    private int getLeftChildIndex(int i) {
        return 2 * i + 1;
    }

    private int getRightChildIndex(int i) {
        return 2 * i + 2;
    }

    private int getParentIndex(int i) {
        return (i - 1) / 2;
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

    private Node leftChild(int index) {
        return arr[getLeftChildIndex(index)];
    }

    private Node rightChild(int index) {
        return arr[getRightChildIndex(index)];
    }

    private Node parent(int index) {
        return arr[getParentIndex(index)];
    }

    private void swap(int i, int j) {
        Node temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private void ensureCapacity() {
        if (capacity > size)
            return;
        capacity *= 2;
        Node[] tempArr = Arrays.copyOf(arr, capacity);
        arr = tempArr;
    }

    public Node peek() {
        if (size == 0)
            throw new IllegalStateException();
        return arr[0];
    }

    public Node poll() {
        if (size == 0)
            throw new IllegalStateException();
        Node temp = arr[0];
        swap(0, size);
        size--;
        heapifyDown();
        return temp;
    }

    public void add(Node item) {
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