#include "AVL.h"
#include <vector>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <random>
using std::cout;
using std::endl;

int main() {
    AVLTree<int> new_tree;
    std::vector<int> numbers;
    for(int i=0; i<1000; i++)       // add 0-99 to the vector
        numbers.push_back(i);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
    for(int i = 0; i < 1000; i++)
    {
        new_tree.insert_value(i);
    }
    new_tree.in_order(new_tree.get_root());
    cout<<"***************"<<endl;
    new_tree.delete_value(new_tree.get_root(),743);
    new_tree.delete_value(new_tree.get_root(),202);
    new_tree.in_order(new_tree.get_root());
    cout<<"***************"<<endl;
    new_tree.delete_value(new_tree.get_root(),202);
    new_tree.delete_value(new_tree.get_root(),509);
    new_tree.delete_value(new_tree.get_root(),111);
    new_tree.delete_value(new_tree.get_root(),0);
    new_tree.delete_value(new_tree.get_root(), 545454);
    new_tree.delete_value(new_tree.get_root(), 999);
    cout<<"***************"<<endl;
    new_tree.in_order(new_tree.get_root());
    return 0;
}