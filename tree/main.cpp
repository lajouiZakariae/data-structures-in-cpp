#include<iostream>

using namespace std;

class TreeItem {
public:
    int value ;
    TreeItem* left;
    TreeItem* right;
public:
    TreeItem(int _value){
        value=_value;
    };
};

class Tree {

public:
    TreeItem* head;

public:
    Tree(int _value){
        head = new TreeItem(_value);
    };
      
    void setLeft(int _value){
        TreeItem* treeItem = new TreeItem(_value);
        head->left = treeItem;
    }

    void setRight(int _value){
        TreeItem* treeItem = new TreeItem(_value);
        head->right = treeItem;
    }
}; 

int main(int argc, char const* argv[]) {
    Tree tree(23);

    tree.setLeft(150);

    tree.setRight(79);

    cout << tree.head->right->value << endl;

    return 0;
}