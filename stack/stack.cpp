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
    next = NULL;
}

class Stack {
public:
    Node* top;
    int size;
public:
    Stack(/* args */);
    void printAll();
    int pop();
    void push(int);
    void clear();
    void  traverse();
};

void show(int _value){
    cout << _value << endl;
}

int main(int argc, char const* argv[]) {
    Stack stack;

    stack.push(12);

    stack.push(16);

    stack.push(8);

    cout << stack.pop() << endl; 

    stack.traverse();

    return 0;
}

Stack::Stack() {
    top = NULL;
    size = 0;
}

void Stack::printAll() {
    Node* cursor = top;
    int i = 1;
    cout << "----- Stack Items (" << size << ")-----" << endl;
    while (cursor) {
        cout << "Item number " << i << ": " << cursor->value << endl;
        cursor = cursor->next;
        i++;
    }
    cout << "--------------------------" << endl;

};

int Stack::pop() {
    int value = top->value;

    Node* topNode = top;
    top = top->next;
    delete topNode;
    size--;

    return value;
};

void Stack::push(int _value) {
    Node* newNode = new Node(_value);
    newNode->value = _value;
    newNode->next = top;
    top = newNode;
    size++;
};

void Stack::clear(){
    Node* cursor = top;

    while(cursor){  
        Node* nextPos = cursor->next;
        delete cursor;
        cursor = nextPos;
    }

    top = NULL;
    size = 0;
}

void Stack::traverse(){
    Node* cursor = top;

    while( cursor ){
        // Call the handler
        cursor = cursor->next;
    }
}