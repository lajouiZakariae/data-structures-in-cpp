#include <iostream>

using namespace std;

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

    // list.shift();
    list.displayAll();

    list.remove(3);

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
    if (pos >= size || pos < 0){
        cout << NOT_EXISTED_ERR;
    } else if( pos == 0 ) {
        head = head->next;
    } else {
        Node* current = head;
        int index = 0;
        
        while (index != pos - 1){
            current = current->next;
            index++;
        }

        current->next = current->next->next;
    }
    
}

void LL::shift(){
    if (head == NULL){
        cout << NOT_EXISTED_ERR;
    }else{
        head = head->next;
    }
}

void LL::pop(){
    if (head == NULL){
        cout << NOT_EXISTED_ERR;
    }else{
        Node* current = head;

        while (current->next->next != NULL) {
            current = current->next;
        }
        
        current->next = NULL ;
    }
}

void LL::displayAll(){
    Node* current = head;
    int count = 0;
    cout << "------------------" << endl;
    if (current == NULL){
        cout << EMPTY_ERR;
    }
    
    while (current != NULL) {
        cout << count << ": " << current->name << endl ;
        current = current->next;
        count++;
    }

    cout << "------------------" << endl;
};