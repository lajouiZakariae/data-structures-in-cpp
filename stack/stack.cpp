#include<iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* next;
public:
    Node(int _value);
};

Node::Node(int _value) {
    value = _value;
}

class Stack {
private:
    Node* head;
    int size;
public:
    Stack(/* args */);
    void printAll();
    int pop();
    void push(int);
};

int main(int argc, char const* argv[]) {
    Stack stack;

    stack.push(12);

    stack.push(16);

    stack.pop();

    stack.push(32);

    stack.push(21);

    stack.pop();

    stack.printAll();

    return 0;
}

Stack::Stack() {
    head = NULL;
    size = 0;
}

void Stack::printAll() {
    Node* cursor = head;
    int i = 1;
    cout << "----- Stack Items (" << size << ")-----" << endl;
    while (cursor != NULL) {
        cout << "Item number " << i << ": " << cursor->value << endl;
        cursor = cursor->next;
        i++;
    }
    cout << "--------------------------" << endl;

};

int Stack::pop() {
    Node* cursor = head;

    while (cursor->next->next != NULL) {
        cursor = cursor->next;
    }

    delete cursor->next;
    cursor->next = NULL;
    size--;
};

void Stack::push(int _value) {
    Node* newNode = new Node(_value);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* cursor = head;

        while (cursor->next != NULL) {
            cursor = cursor->next;
        }

        cursor->next = newNode;
    }
    size++;
};