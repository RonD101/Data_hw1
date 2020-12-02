#include "AVL.h"
#include "CoursesManager.h"

using std::cout;
using std::endl;

void weird_in_order(AVLNode<int>* root)
{
    if(root == nullptr)
        return;
    std::cout << root->data;
    weird_in_order(root->get_parent());
    weird_in_order(root->get_right());

}

int main() {

//    AVLTree<int> test_order;
//    test_order.insert_value(1);
//    test_order.insert_value(2);
//    test_order.insert_value(3);
//    test_order.insert_value(4);
//    test_order.insert_value(5);
//    test_order.delete_value(test_order.get_root(), 1);
//    //weird_in_order(test_order.find_value(test_order.get_root(), 1));
//    test_order.in_order(test_order.get_root());
    CoursesManager CM;
    CM.AddCourse(1,5);
//    CM.AddCourse(4,6);
//    CM.WatchClass(1,0,10);
//    CM.WatchClass(1,1,30);
//    CM.WatchClass(1,3,50);
//    CM.WatchClass(4,2,10);
//    CM.WatchClass(4,1,50);
     CM.RemoveCourse(1);
//    CM.AddCourse(2,9);
//    CM.AddCourse(1,8);
//    CM.WatchClass(2,4,50);
//    CM.WatchClass(3,4,50);
//    CM.WatchClass(2,4,60);
//    CM.WatchClass(2,6,60);
//    CM.WatchClass(1,6,70);
    int courses[10] = {0};
    int classes[10] = {0};
    CM.GetMostViewedClasses(10, courses, classes);
    return 0;
}