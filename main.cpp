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

    auto* DS = Init();
    AddCourse(DS, 2, 5);
    AddCourse(DS, 1, 10);
    WatchClass(DS, 2, 3, 14);
    WatchClass(DS, 2, 1, 5);
    WatchClass(DS, 2, 5, 13);
    WatchClass(DS, 1, 2, 5);

    int courses[15] = {0};
    int classes[15] = {0};

    GetMostViewedClasses(DS, 5, courses, classes);

    Quit(&DS);
//   AVLTree<int> test_order;
//    for(int i = 0; i < 15; i++)
//        test_order.insert_value(i);
//    for(int i = 0; i < 14; i++)
//        test_order.delete_value(test_order.get_root(), i);
//    //weird_in_order(test_order.find_value(test_order.get_root(), 1));
//    test_order.in_order(test_order.get_root());
//
//    CoursesManager CM;
//    CM.AddCourse(1,5);
//    CM.AddCourse(4,6);
//    CM.WatchClass(1,0,10);
//    CM.WatchClass(1,1,30);
//    CM.WatchClass(1,3,50);
//    CM.WatchClass(4,2,10);
//    CM.WatchClass(4,1,50);
//    CM.AddCourse(2,9);
//    CM.AddCourse(1,8);
//    CM.WatchClass(2,1,50);
//    CM.WatchClass(2,1,50);
//
//
//    CM.WatchClass(3,4,50);
//    CM.WatchClass(2,4,60);
//    CM.WatchClass(2,6,60);
//    CM.WatchClass(1,6,70);
//    int courses[5] = {0};
//    int classes[5] = {0};
//    CM.GetMostViewedClasses(5, courses, classes);
//    CM.Quit();
    return 0;
}