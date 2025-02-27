public class TestJava {
    public static void main(String[] args) {
        LinkedQueue<Integer> queue = new LinkedQueue<>();

        queue.enqueue(99);
        queue.enqueue(221);
        queue.enqueue(2);
        queue.enqueue(11);
        queue.enqueue(12);
        queue.enqueue(42);
        queue.enqueue(21);
        queue.enqueue(66);

        queue.printQueue();

        mergeSort(queue);

        queue.printQueue();
    }

    private static void mergeSort(LinkedQueue<Integer> queue) {
        if (queue.size() > 1) {

            int mid = queue.size()/2;

            LinkedQueue<Integer> lqueue = new LinkedQueue<>();
            LinkedQueue<Integer> rqueue = new LinkedQueue<>();

            for (int i = 0; i < mid; i++) {
                lqueue.enqueue(queue.dequeue());
            }
            while (!queue.isEmpty()) {
                rqueue.enqueue(queue.dequeue());
            }

            mergeSort(lqueue);
            mergeSort(rqueue);
            merge(queue, lqueue, rqueue);
        }
    }

    private static void merge(LinkedQueue<Integer> queue, LinkedQueue<Integer> lqueue, LinkedQueue<Integer> rqueue) {

        while (!lqueue.isEmpty() && !rqueue.isEmpty())
            if (lqueue.peek() < rqueue.peek()) {
                queue.enqueue(lqueue.dequeue());
            } else {
                queue.enqueue(rqueue.dequeue());
            }
        while (!lqueue.isEmpty()) {
            queue.enqueue(lqueue.dequeue());
        }
        while (!rqueue.isEmpty()) {
            queue.enqueue(rqueue.dequeue());
        }
    }

    static class LinkedQueue<T> {
        private int size = 0;
        private Node back = null, front = null;

        class Node {
            private final T data;
            private Node next;

            Node(T data) {
                this.data = data;
            }

            @Override
            public String toString() {
                return "{" + data.toString() + "} -> " + (next != null ? next.data.toString() : "null");
            }
        }

        int size() {
            return this.size;
        }

        Node getFront() {
            return front;
        }

        boolean isEmpty() {
            return size == 0;
        }

        public void enqueue(T item) {
            Node newNode = new Node(item);
            if (isEmpty()) {
                front = back = newNode;
            } else {
                back.next = newNode;
                back = newNode;
            }
            size++;
        }

        public T dequeue() {
            if (isEmpty()) {
                throw new IllegalStateException("Queue is empty");
            }

            T frontData = front.data;
            front = front.next;
            if (front == null) {
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
            if (isEmpty()) {
                System.out.println("Queue is empty");
                return;
            }

            Node print = front;
            while (print != null) {
                System.out.print(print.toString() + " ");
                print = print.next;
            }
            System.out.println();
        }
    }
}