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
    new_tree.delete_value(9);
//    cout << new_tree.get_tree_height(new_tree.get_root()) << endl;
//    new_tree.inorder(new_tree.get_root());
    return 0;
}