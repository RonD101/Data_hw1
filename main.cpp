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
    for(int i=0; i<100; i++)       // add 0-99 to the vector
        numbers.push_back(i);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
    for (int i = 0; i < 100; ++i) {
        int x;
        std::cin >> x;
        new_tree.insert_value(numbers[i]);
    }
    new_tree.delete_value(new_tree.get_root(),5);
    //    for(auto i : numbers)
//    {
////        new_tree.insert_value(i);
//        cout << i << endl;
//    }

    new_tree.in_order(new_tree.get_root());
    return 0;
}