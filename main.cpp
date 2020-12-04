#include "AVL.h"
#include "CoursesManager.h"

using std::cout;
using std::endl;

int main() {

    auto* DS = Init();
    AddCourse(DS, 2, 20);
    AddCourse(DS, 6, 7);
    AddCourse(DS, 5, 3);
    AddCourse(DS, 9, 13);
    AddCourse(DS, 1, 10);
    WatchClass(DS, 2, 3, 14);
    WatchClass(DS, 2, 1, 5);
    WatchClass(DS, 2, 7, 59);
    WatchClass(DS, 2, 4, 13);
    RemoveCourse(DS,9);
    WatchClass(DS, 6, 1, 65);
    WatchClass(DS, 1, 2, 5);
    WatchClass(DS, 9, 6, 55);
    WatchClass(DS, 2, 12, 59);
    RemoveCourse(DS,1);
    RemoveCourse(DS,2);

    WatchClass(DS, 5, 1, 13);
    WatchClass(DS, 2, 0, 65);

    int courses[7] = {0};
    int classes[7] = {0};
    GetMostViewedClasses(DS, 7, courses, classes);
    for (int i = 0; i < 7; ++i) {
        cout << "Course : " << courses[i] << " | Lecture : " << classes[i] << endl;
    }

    Quit(&DS);
    return 0;
}