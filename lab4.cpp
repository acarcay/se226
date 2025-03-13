#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* head;
    int num;        
    int capacity;

public:
    Stack(int initialCapacity) {
        head = nullptr;
        num = 0;    
        capacity = initialCapacity;
    }

    void push(int x) {
        if (num >= capacity) {
            increaseCapacity();
        }

        Node* newNode = new Node(x);

        if (isEmpty()) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        num++;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack Underflow" << std::endl;
            return -1;
        }

        int value = head->data;

        Node* temp = head;

        head = head->next;

        delete temp;

        num--;

        return value;
    }

    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            return -1;
        }

        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void increaseCapacity() {
        capacity = capacity * 2;
    }

    bool deleteElement(int val) {
        if (isEmpty()) {
            return false;  
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            num--;
            return true;   
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == val) {
                prev->next = current->next;

                delete current;

                num--;
                return true;   
            }

            prev = current;
            current = current->next;
        }

        return false;  
    }


    int getCapacity() {
        return capacity;
    }

    int getSize() {
        return num;
    }
};

int main() {
    Stack stack(3);

    std::cout << "Pushing elements 10, 20, 30" << std::endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "After pushing 3 elements, capacity: " << stack.getCapacity()
              << ", size: " << stack.getSize() << std::endl;  

    std::cout << "Pushing element 40" << std::endl;
    stack.push(40);
    std::cout << "After pushing 4th element, capacity: " << stack.getCapacity()
              << ", size: " << stack.getSize() << std::endl;  

    std::cout << "Pushing element 50" << std::endl;
    stack.push(50);

    std::cout << "Current stack top: " << stack.peek() << std::endl;

    std::cout << "Deleting element 30" << std::endl;
    stack.deleteElement(30);

    std::cout << "Popping elements:" << std::endl;
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << std::endl;
    }

    return 0;
}
