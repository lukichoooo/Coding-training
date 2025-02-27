public class LinkedListQueueMergeSort {
    public static void main(String[] args) {

        LinkedQueue<Integer> queue = new LinkedQueue<>();

        queue.enqueue(45);
        queue.enqueue(53);
        queue.enqueue(36);
        queue.enqueue(1);
        queue.enqueue(12);
        queue.enqueue(98);
        queue.enqueue(43);
        queue.enqueue(91);


        queue.printQueue();

        LinkedQueue<Integer> sortedQueue = mergeSort(queue);

        sortedQueue.printQueue();
    }

    public static LinkedQueue<Integer> mergeSort(LinkedQueue<Integer> queue) {  // time = O(nlogn)  space = O(n)
        if (queue.size() <= 1)
            return queue; // Base case: already sorted
    
        // Split queue into two halves
        LinkedQueue<Integer> leftHalf = new LinkedQueue<>();
        LinkedQueue<Integer> rightHalf = new LinkedQueue<>();
        int mid = queue.size() / 2;
        
        for (int i = 0; i < mid; i++)
            leftHalf.enqueue(queue.dequeue());
    
        while (!queue.isEmpty())
            rightHalf.enqueue(queue.dequeue());
    
        // Recursively sort both halves
        leftHalf = mergeSort(leftHalf);
        rightHalf = mergeSort(rightHalf);
    
        // Merge sorted halves
        return merge(leftHalf, rightHalf);
    }

    public static LinkedQueue<Integer> merge(LinkedQueue<Integer> queueL, LinkedQueue<Integer> queueR) {

        LinkedQueue<Integer> queue1 = new LinkedQueue<>();

        while (!queueL.isEmpty() && !queueR.isEmpty()) {

            if (queueL.peek() < queueR.peek()) {
                queue1.enqueue(queueL.dequeue());
            } else {
                queue1.enqueue(queueR.dequeue());
            }
        }
        while (!queueL.isEmpty()) {
            queue1.enqueue(queueL.dequeue());
        }
        while (!queueR.isEmpty()) {
            queue1.enqueue(queueR.dequeue());
        }
        
        return queue1;
    }
}

class LinkedQueue<T> {

    private int size = 0;

    int size() {
        return this.size;
    }

    private Node front = null, back = null;

    class Node { // object to store a single node for a linkedList
        private final T data; // data
        private Node next; // referance to the next node

        Node(T data) {
            this.data = data;
        }

        @Override
        public String toString() {
            return "{" + data.toString() + "} -> " + (next != null ? next.data.toString() : "");
        }

    }

    boolean isEmpty() {
        return size == 0;
    }

    public void enqueue(T item) {
        Node newNode = new Node(item);
        if (isEmpty()) {
            front = back = newNode; // First element: front and back point to the same node
        } else {
            back.next = newNode; // Link current back to new node
            back = newNode; // Move back to the new node
        }
        size++;
    }

    public T dequeue() { // get data from front and remove the node
        if (isEmpty())
            throw new IllegalStateException();

        T frontData = front.data;
        front = front.next; // Move front to the next node
        if (front == null) { // If queue becomes empty, update back to null
            back = null;
        }
        size--;
        return frontData;
    }

    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return front.data;
    }

    public void printQueue() {
        Node print = front;
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }

        for (int i = 0; i < size; i++) {
            System.out.println(i + print.toString() + " ");
            print = print.next;
        }
        System.out.println();
    }

    public void setSize(int size) {
        this.size = size;
    }

}
