#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


class Queue {
private:
    Node* front;
    Node* rear;
    int count; 

public:
    Queue() {
        front = rear = nullptr;
        count = 0;
    }

    
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
    }

    
    int top() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1; 
        }
        return front->data;
    }

    
    bool isEmpty() {
        return front == nullptr;
    }

    
    int size() {
        return count;
    }

    
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};


int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.top() << endl;
    cout << "Queue size: " << q.size() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.top() << endl;
    cout << "Queue size after dequeue: " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue(); 

    return 0;
}
