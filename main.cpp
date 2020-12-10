#include "AVL.h"
#include "CoursesManager.h"

using std::cout;
using std::endl;

int main() {
    AVLTree<float> tree;
    tree.insert_value(10);
    tree.insert_value(5);
    tree.insert_value(13);
    tree.insert_value(4);
    tree.insert_value(8);
    tree.insert_value(12);
    tree.insert_value(14);
    tree.insert_value(3);
    tree.insert_value(6);
    tree.insert_value(9);
    tree.insert_value(11);
    tree.insert_value(12.5);

    tree.insert_value(15);
    tree.insert_value(5.5);
    tree.insert_value(7);
    tree.delete_value(tree.get_root(), 12);
    tree.delete_value(tree.get_root(), 13);

    tree.delete_value(tree.get_root(), 5);
    tree.delete_value(tree.get_root(), 6);

    tree.in_order(tree.get_root());


    return 0;
}