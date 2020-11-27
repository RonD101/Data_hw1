#include <iostream>

#include "AVL.h"
int main() {
    std::cout << "Hey" << std::endl;
    AVLTree<int> new_tree;
    new_tree.Insert(5);
    new_tree.Insert(4);
    std::cout << new_tree.get_tree_height((new_tree.GetRoot())) << std::endl;
    new_tree.inorder(new_tree.GetRoot());
    return 0;
}