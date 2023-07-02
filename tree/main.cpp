#include<iostream>

using namespace std;

class TreeItem {

private:
    int value;
    TreeItem* left;
    TreeItem* right;

public:
    TreeItem(int);

    int getValue();

    void setLeft(TreeItem*);

    TreeItem getLeft();

    void setRight(TreeItem*);
};

class Tree {

private:
    TreeItem head;

public:
    Tree(int);
    TreeItem gethead();
};



int main(int argc, char const* argv[]) {
    Tree tree(150);
    TreeItem leftItem(130);

    tree.gethead().setLeft(leftItem);
    cout << tree.gethead().getLeft();

    return 0;
}

TreeItem::TreeItem(int val) {
    value = val;
}

int TreeItem::getValue() {
    return value;
}

void TreeItem::setLeft(TreeItem* _left) {
    left = _left;
};

TreeItem* TreeItem::getLeft() {
    return left;
};

void TreeItem::setRight(TreeItem* _right) {
    right = _right;
};

Tree::Tree(int value) : head(value)
{
}

TreeItem Tree::gethead() {
    return head;
}