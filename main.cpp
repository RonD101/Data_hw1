#include <iostream>

#include "AVL.h"

using std::cout;
using std::endl;

int main() {
    AVLTree<int> new_tree;
    new_tree.insert_value(5);
    new_tree.insert_value(4);
    new_tree.insert_value(3);
    new_tree.insert_value(6);
    new_tree.insert_value(7);
    new_tree.in_order(new_tree.get_root());
    new_tree.delete_value(new_tree.get_root(), 6);
    cout << endl << "****" << endl;
    new_tree.in_order(new_tree.get_root());
    return 0;
}