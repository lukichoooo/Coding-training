#include <iostream>

using namespace std;

template <typename T>
class LinkedQueue
{
    class Node
    {
    public:
        Node(T data) : data(data), next(nullptr) {};
        T data;
        Node *next;
    };

private:
    Node *front = nullptr;
    Node *back = nullptr;

    size_t size = 0;

public:
    void enqueue(T data)
    {
        Node *newNode = new Node(data);
        if (size == 0)
            back = front = newNode;
        else
        {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    T dequeue()
    {
        if (size == 0)
        {
            throw out_of_range("Queue is empty");
        }
        else
        {
            T temp = front->data;
            Node* oldFront = front;
            front = front->next;
            delete oldFront;
            size--;
            if (size == 0)
            {
                back = nullptr;
            }
            return temp;
        }
    }

    size_t getSize()
    {
        return size;
    }
    T peek() { return front->data; };


    void printList(LinkedQueue<string> queue){
        Node current = new Node();
        back->next = current;
        for (size_t i = 0; i < size; i++)
        {
            cout<<
        }
        
    }
};



int main()
{
    LinkedQueue<string> queue; // Create a queue of strings

    queue.enqueue("apple");
    queue.enqueue("orange");

    cout << "Dequeued: " << queue.dequeue() << endl; // apple
    cout << "Dequeued: " << queue.dequeue() << endl; // apple

    return 0;
}
