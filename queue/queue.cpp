#include<iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;
public:
    Node(int);
};

Node::Node(int _value) {
    this->value = _value;
}

class Queue {

private:
    Node* head;
    int size;
public:
    Queue();
    void printAll();
    void enqueue(int);
    void dequeue();

};

int main(int argc, char const* argv[])
{
    Queue queue;

    queue.enqueue(12);

    queue.enqueue(15);

    queue.dequeue();

    queue.enqueue(18);

    queue.enqueue(20);

    queue.dequeue();

    queue.printAll();

    return 0;
}


Queue::Queue() {
    head = NULL;
    size = 0;
}

void Queue::printAll() {
    cout << "---- Queue Items (" << size << ") -----" << endl;
    int i = 1;
    Node* cursor = head;
    while (cursor != NULL) {
        cout << "Item number " << i << " in Queue: " << cursor->value << endl;
        cursor = cursor->next;
        i++;
    }
    cout << "--------------------------" << endl;

}

void Queue::enqueue(int _value) {
    Node* newNode = new Node(_value);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* cursor = head;

        while (cursor->next != NULL) {
            cursor = cursor->next;
        };

        cursor->next = newNode;
    }
    this->size++;
};

void Queue::dequeue() {
    Node* nextNode = head->next;
    delete head;
    head = nextNode;
    size--;
}
