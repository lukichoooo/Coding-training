#include <iostream>

using namespace std;

template <typename T>
class LinkedQueue
{

    struct Node
    {
    private:
        T data;
        Node *pNext; // pointing to the next node in the list

    public:
        Node(T data) : data(data) {}
        Node() {}
    };

private:
    int size = 0;
    Node front;
    Node back;

public:
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size() == 0;
    }

    void enqueue(T item)
    {
        Node newNode = new Node(item);

        if (isEmpty())
            front = back = newNode;
        size++;
        else
        {
            back->pNext = newNode;
            back = newNode;
            size++;
        }
    }

    T dequeue()
    {
        if (isEmpty())
            throw runtime_error("Queue is empty");
        if (front == NULL)
        {
            back = NULL; // if front is empty back should also be empty
        }
        T frontData = front->data;
        front = front->pNext;
        size--;
        return frontData;
    }

    T peek()
    {
        if (isEmpty())
            return "its empty";
        return front->data;
    }
};

int main()
{
    LinkedQueue<string> queue; // Create a queue of strings

    queue.enqueue("apple");
    queue.enqueue("orange");

    std::cout << "Front element: " << queue.peek() << std::endl;                // apple
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;                  // apple
    std::cout << "Queue size: " << queue.getSize() << std::endl;                // 1
    std::cout << "Is empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl; // No

    return 0;
}
