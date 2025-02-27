

public class LinkedListQueue {
    public static void main(String[] args) {

        LinkedQueue<String> queue = new LinkedQueue<String>();

        queue.enqueue("apple");
        queue.enqueue("orange");
        queue.enqueue("dog");
        queue.enqueue("cool huy");
        queue.enqueue("bear");
        queue.enqueue("cat");

        // System.out.println(queue.peek());
        // System.out.println(queue.dequeue());
        // System.out.println(queue.dequeue());
        // System.out.println(queue.size());
        // System.out.println(queue.isEmpty());

        // System.out.println(queue.search("orange").toString());
        // queue.insert("yle", 4);

        queue.printQueue();

        queue.remove(4);

        queue.printQueue();

        System.out.println(queue.getNodeByIndex(3).toString());


        queue.printQueue();
    }
}

class LinkedQueue<T> {

    private int size = 0;

    int size() {
        return this.size;
    }

    private Node front = null, back = null;

    class Node { // object to store a single node for a linkedList
        private T data; // data
        private Node next; // referance to the next node

        Node(T data) {
            this.data = data;
        }

        @Override
        public String toString() {
            return "{" + data.toString() + "} -> " + (next != null ? next.data.toString() : "null");
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

    // Extra methods

    public Node search(T data) {
        Node search = front;
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }

        for (int i = 0; i < size; i++) {
            if (search.data.equals(data))
                return search;
            search = search.next;
        }
        return null;
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

    public void insert(T data, int index) {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }

        if (index < 0 || index > size) { // Validate index
            throw new IndexOutOfBoundsException(index + " index out of bounds");
        }

        if (index == 0) { // Inserting at the front
            Node newNode = new Node(data);
            newNode.next = front;
            front = newNode;

            if (size == 0) { // If queue was empty, update back
                back = front;
            }
        }

        else if (index == size) { // Insert at the end
            enqueue(data);
            return; // Prevent size++ from running twice
        }

        else {
            Node newNode = new Node(data);
            Node current = front;

            for (int i = 0; i < index - 1; i++) { // Traverse to (index - 1)
                current = current.next;
            }

            newNode.next = current.next; // newNode.next = (index - 1).next
            current.next = newNode; // (index - 1).next = newNode
        }
        size++;

    }

    public Node getNodeByIndex(int index) {
        if (index == 0)
            return front;
        Node current = front;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        return current;
    }

    public void remove(int index) {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }

        if (index >= size || index < 0) { // validate index
            throw new IndexOutOfBoundsException(index + " index out of bounds");
        }

        if (index == 0) {
            dequeue();
            return;
        }

        else {

            Node current = front;

            for (int i = 0; i < index; i++) { // go to (index - 1)
                current = current.next;
            }

            current.next = current.next.next;

            // Handle case where we're removing the last element
            if (index == size - 1) {
                back = current;
            }

            size--;
        }
    }

}