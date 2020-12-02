#include "AVL.h"
#include "CoursesManager.h"
#include "TemArray.h"
#include "List.h"
#include "ViewData.h"

using std::cout;
using std::endl;

int main() {

    CoursesManager CM;
    CM.AddCourse(3,6);
//    CM.AddCourse(2,9);
//    CM.AddCourse(1,8);
//    CM.WatchClass(2,4,50);
//    CM.WatchClass(3,4,50);
//    CM.WatchClass(2,4,60);
//    CM.WatchClass(2,6,60);
//    CM.WatchClass(1,6,70);
    CM.WatchClass(3,4,50);
    CM.watchedTree.in_order(CM.watchedTree.get_root());

    ////////////
//    AVLTree<ViewData> v;
//    v.insert_value(ViewData(2,4,5));
//    v.insert_value(ViewData(3,4,5));
//    v.insert_value(ViewData(2,4,6));
//    v.insert_value(ViewData(2,6,6));
//    v.insert_value(ViewData(1,6,7));
//    v.in_order(v.get_root());
    ////////////
//    List<int> l;
//    l.addAtStart(5);
//    l.addAtStart(6);
//    l.addAtStart(4);
//    CoursesManager boom;
//    boom.AddCourse(1, 5);
//    boom.AddCourse(2, 7);
//    boom.RemoveCourse(2);
//    boom.course_tree.in_order(boom.course_tree.get_root());
//    CoursesManager boom;
//    boom.AddCourse(1, 5);
//    boom.AddCourse(2, 7);
//    int time = -5;
//    boom.TimeViewed(1,3,&time);
//    cout << time;
//    boom.course_tree.in_order(boom.course_tree.get_root());
    return 0;
}