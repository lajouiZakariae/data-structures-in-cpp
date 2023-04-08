#include <iostream>

using namespace std;

/**
 * A Linked-List implementation in c++
 * with the following methods:
 *  - add new element to the list
 *  - remove an element from the list
 *  - unshift: add to the beginning
 *  - shift: remove the first one
 *  - pop: remove the last one
*/

// Error Messages
string const EMPTY_ERR = "List is empty\n";
string const NOT_EXISTED_ERR = "Node does not exist\n";

class Node {
    public:
        string name;
        Node *next;
    
        Node(string);
};

Node::Node(string name){
    this->name = name;
    this->next = NULL;
}

class LL {
    private:
        Node* head; // pointer to first element
        int size;

    public:
        LL(){ // Empty List
            head = NULL;
            size = 0;
        }

        void add(string);
        void unshift(string);
        void remove(int);
        void shift();
        void pop();
        void displayAll();
};

int main(int argc, char const *argv[]){
    LL list;
    
    list.add("Zakariae");
    list.add("Belly");
    list.add("John");

    list.unshift("Silly");
    list.unshift("Lores");

    list.displayAll();

    list.shift();

    list.displayAll();
}


void LL::add(string name){
    Node* newItem = new Node(name);
    
    if (head == NULL) { // first element
        head = newItem;
    } else {
        Node* current = head;
        
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newItem;
    }

    size++;
}

void LL::unshift(string name){
    Node* newItem = new Node(name);
    
    if (head == NULL) { // first element
        head = newItem;
    } else {
        Node* tmp = head;
        head = newItem;
        newItem->next = tmp;
    }
    size++;
}

void LL::remove(int pos){    
    if (pos >= size || pos < 0) { // Out of Scope
        cout << NOT_EXISTED_ERR;
    } else if( pos == 0 ) { // First Element
        this->pop();
    } else {
        Node* current = head;

        for (int i = 0; i < pos - 1 ; i++)
            current = current->next;
        
        Node* to_delete = current->next;
        current->next = to_delete->next;
        delete to_delete;
        size--;
    }
}

void LL::shift(){
    if (head == NULL){
        cout << NOT_EXISTED_ERR;
    }else{
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
        size--;
    }
}

void LL::pop(){
    if (head == NULL){
        cout << NOT_EXISTED_ERR;
    }else{
        Node* current = head;

        for (int i = 0; i < size - 2; i++)
            current = current->next;
        
        Node* to_delete = current->next;
        current->next = NULL;
        delete to_delete;
        size--;
    }
}

void LL::displayAll(){
    Node* current = head;
    int count = 0;
    cout << "-------------------" << endl;
    cout << "Size of List: " << size << endl;
    cout << "-------------------" << endl;

    if (current == NULL)
        cout << EMPTY_ERR;
    
    while (current != NULL) {
        cout << count << ": " << current->name << endl ;
        current = current->next;
        count++;
    }

    cout << "-------------------" << endl;
};