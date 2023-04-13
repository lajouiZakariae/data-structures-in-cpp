#include<iostream>

using namespace std;

string const NOT_FOUND_ERR = "The item is out of scope\n";

class Array {
private:
    float arr[7] = { 1,2,3,7,6,9,20 };
    int length = 7;

public:
    Array(int);
    int getLength();
    void del(int);
    float get(int);
    int find(float);
    int findLast(float);
    void displayAll();
};

Array::Array(int length = 5) {
    // this->arr = new float[length];
    // this->length = length;
}

int main(int argc, char const* argv[]) {
    Array notes;

    notes.displayAll();

    return 0;
}

void Array::del(int index) {
    if (index < 0 or index >= length) {
        cout << NOT_FOUND_ERR;
    }
    else {
        for (int i = 0; i < length; i++) {
            if (i == index) {
                for (int j = index; j < length; j++) {
                    cout << arr[j] << endl;
                    if (j == length - 1) {
                        arr[j] = 0;
                    }
                    else {
                        arr[j] = arr[j + 1];
                    }
                }
                length--;
            }
        }

    }
}

int Array::getLength() {
    return length;
}

float Array::get(int index) {
    for (int i = 0; i < length; i++) if (index == i) return arr[i];
}

int Array::find(float note) {
    for (int i = 0; i < length; i++) if (arr[i] == note) return i;
}

int Array::findLast(float note) {
    int index_of_note;
    for (int i = 0; i < length; i++) if (arr[i] == note) index_of_note = i;
    return index_of_note;
}

void Array::displayAll() {
    cout << "*-------------------------*" << endl;
    cout << "Length of Array: " << length << endl;
    cout << "*-------------------------*" << endl;
    for (int i = 0; i < length; i++) {
        cout << i << ": " << this->arr[i] << endl;
    }
    cout << "*-------------------------*" << endl;
}