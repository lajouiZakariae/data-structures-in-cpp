#include <iostream>
#include <cmath>

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
    float number;
    Node* next;

    Node(float);
};

Node::Node(float number) {
    this->number = number;
    this->next = NULL;
}

class LL {
private:
    Node* head; // pointer to first element
    int size;

public:
    LL() { // Empty List
        head = NULL;
        size = 0;
    }

    // Data Manipulation
    void add(float);
    void unshift(float);
    void remove(int);
    void shift();
    void pop();
    void replace(float, float);
    void replaceAll(float, float);
    void insertAfter(int, float);
    void insertBefore(int, float);
    void reverse();
    // Data Access
    int get(float);
    int getLast(float);

    // 
    float** split(int parts);
    void sort(string);
    void displayAll();
};

int main(int argc, char const* argv[]) {
    LL list;

    for (int i = 1; i < 11; i++) list.add(rand());

    list.displayAll();
    list.reverse();
    list.displayAll();
}

void LL::add(float number) {
    Node* newItem = new Node(number);

    if (head == NULL) { // first element
        head = newItem;
    }
    else {
        Node* current = head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newItem;
    }

    size++;
}

void LL::unshift(float number) {
    Node* newItem = new Node(number);

    if (head == NULL) { // first element
        head = newItem;
    }
    else {
        Node* tmp = head;
        head = newItem;
        newItem->next = tmp;
    }
    size++;
}

void LL::remove(int pos) {
    if (pos >= size || pos < 0) { // Out of Scope
        cout << NOT_EXISTED_ERR;
    }
    else if (pos == 0) { // First Element
        this->pop();
    }
    else {
        Node* current = head;

        for (int i = 0; i < pos - 1; i++)
            current = current->next;

        Node* to_delete = current->next;
        current->next = to_delete->next;
        delete to_delete;
        size--;
    }
}

void LL::shift() {
    if (head == NULL) {
        cout << NOT_EXISTED_ERR;
    }
    else {
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
        size--;
    }
}

void LL::pop() {
    if (head == NULL) {
        cout << NOT_EXISTED_ERR;
    }
    else {
        Node* current = head;

        for (int i = 0; i < size - 2; i++)
            current = current->next;

        Node* to_delete = current->next;
        current->next = NULL;
        delete to_delete;
        size--;
    }
}

void LL::insertAfter(int index, float number) {
    Node* current = head;
    for (int i = 0; i <= index; i++) {
        if (i == index) {
            Node* newItem = new Node(number);

            Node* tmp = current->next;
            current->next = newItem;
            newItem->next = tmp;

            size++;
        }
        current = current->next;
    }

}

void LL::insertBefore(int index, float number) {
    Node* current = head;

    for (int i = 0; i <= index; i++) {
        if (i == index - 1) {
            Node* newItem = new Node(number);
            Node* tmp = current->next;
            current->next = newItem;
            newItem->next = tmp;
            cout << current->number << endl;
        }
        current = current->next;
    }

}

void LL::reverse() {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;

        // Move to the next
        prev = current;
        current = next;
    }

    head = prev;
}

int LL::get(float number) {
    Node* current = head;
    for (int i = 0; i < size; i++) {
        if (current->number == number)
            return i;
        current = current->next;
    }
}

int LL::getLast(float number) {
    Node* current = head;
    int found_index = 0;

    for (int i = 0; i < size; i++) {
        if (current->number == number) found_index = i;

        current = current->next;
    }

    return found_index;
}

void LL::replace(float number, float new_number) {
    Node* current = head;

    for (Node* current = head; current != NULL; current = current->next) {
        if (current->number == number) {
            current->number = new_number;
            return;
        };
    }

}

void LL::replaceAll(float number, float new_number) {
    Node* current = head;

    for (Node* current = head; current != NULL; current = current->next)
        if (current->number == number)
            current->number = new_number;
}

float** LL::split(int chunk_size) {
    int number_of_chunks = ceil((float)size / chunk_size);

    float** chunks = new float* [number_of_chunks];

    Node* current = head;

    for (int i = 0; i < number_of_chunks; i++) {
        chunks[i] = new float[chunk_size];
        for (int j = 0; j < chunk_size; j++) {
            if (current != NULL) {
                chunks[i][j] = current->number;
                current = current->next;
            }
            else chunks[i][j] = 0;
        }
    }

    return chunks;
}

void LL::sort(string order) {
    for (int i = 0; i < size - 1; i++) {
        Node* current = head;
        int changes = 0;

        for (int j = 0; j < size - 1 - i; j++) {
            float current_number = current->number;
            float next_number = current->next->number;

            if (
                (current_number > next_number and order == "ASC") or
                (current_number < next_number and order == "DESC")) {
                // Swap
                current->number = next_number;
                current->next->number = current_number;
                changes++;
            }

            current = current->next;
        }

        if (changes == 0)
            break; // No changer = the list in the right order
    }
}

void LL::displayAll() {
    Node* current = head;
    int count = 0;
    cout << "*------------------------*" << endl;
    cout << "Size of List: " << size << endl;
    cout << "*------------------------*" << endl;

    if (current == NULL)
        cout << EMPTY_ERR;

    for (Node* current = head;current != NULL; current = current->next) {
        cout << count << ": " << current->number << endl;
        count++;
    }

    cout << "*------------------------*" << endl;
};
