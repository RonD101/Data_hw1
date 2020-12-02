#include "AVL.h"
#include "CoursesManager.h"
#include "TemArray.h"
#include "List.h"
#include "ViewData.h"

using std::cout;
using std::endl;

int main() {

    CoursesManager CM;
    CM.AddCourse(1,5);
    CM.WatchClass(1,0,10);
    CM.WatchClass(1,1,20);
    CM.WatchClass(1,3,40);
    CM.WatchClass(1,2,30);
    CM.WatchClass(1,4,50);
    //CM.RemoveCourse(3);
//    CM.AddCourse(2,9);
//    CM.AddCourse(1,8);
//    CM.WatchClass(2,4,50);
//    CM.WatchClass(3,4,50);
//    CM.WatchClass(2,4,60);
//    CM.WatchClass(2,6,60);
//    CM.WatchClass(1,6,70);
    int courses, classes;
    CM.GetMostViewedClasses(2, &courses, &classes);
    return 0;
}