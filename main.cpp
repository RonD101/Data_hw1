#include "AVL.h"
#include "CoursesManager.h"

using std::cout;
using std::endl;

int main() {

    AVLTree<int> tree;
    tree.insert_value(20);
    tree.insert_value(11);
    tree.insert_value(30);
    tree.insert_value(8);
    tree.insert_value(13);
    tree.insert_value(25);
    tree.insert_value(31);
    tree.insert_value(1);
    tree.insert_value(9);
    tree.insert_value(12);
    tree.insert_value(15);
    tree.insert_value(22);
    tree.insert_value(26);
    tree.insert_value(59);
    tree.insert_value(0);
    tree.insert_value(7);
    ///////////////////////////////////////
//    tree.insert_value(11);
    tree.insert_value(10);
    ////////////////////////////////////////
    tree.insert_value(14);
    tree.insert_value(17);
    tree.insert_value(21);
    tree.insert_value(23);
    tree.insert_value(27);
    tree.insert_value(19);
    tree.delete_value(tree.get_root(),14);
    tree.delete_value(tree.get_root(),22);
    tree.delete_value(tree.get_root(),25);
    tree.delete_value(tree.get_root(),27);
    tree.in_order(tree.get_root());
//    auto* DS = Init();
//    AddCourse(DS, 2, 20);
//    AddCourse(DS, 6, 7);
//    AddCourse(DS, 5, 3);
//    AddCourse(DS, 9, 13);
//    AddCourse(DS, 1, 10);
//    WatchClass(DS, 2, 3, 14);
//    WatchClass(DS, 2, 1, 5);
//    WatchClass(DS, 2, 7, 59);
//    WatchClass(DS, 2, 4, 13);
//    RemoveCourse(DS,9);
//    WatchClass(DS, 6, 1, 65);
//    WatchClass(DS, 1, 2, 5);
//    WatchClass(DS, 9, 6, 55);
//    WatchClass(DS, 2, 12, 59);
//    RemoveCourse(DS,1);
//    RemoveCourse(DS,2);
//
//    WatchClass(DS, 5, 1, 13);
//    WatchClass(DS, 2, 0, 65);
//
//    int courses[7] = {0};
//    int classes[7] = {0};
//    GetMostViewedClasses(DS, 7, courses, classes);
//    for (int i = 0; i < 7; ++i) {
//        cout << "Course : " << courses[i] << " | Lecture : " << classes[i] << endl;
//    }
//
//    Quit(&DS);
    return 0;
}