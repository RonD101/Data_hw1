#include <iostream>

#include "AVL.h"
int main() {
    AVLTree<int> new_tree;
    new_tree.insert_value(5);
    new_tree.insert_value(4);

    new_tree.inorder(new_tree.get_root());
    return 0;
}