//#include "AVL.h"
//#include "CoursesManager.h"
//
//using std::cout;
//using std::endl;
//
//int main() {
//
//    auto* DS = Init();
//    auto* DS2 = Init();
//    AddCourse(DS, 2, 20);
//    AddCourse(DS, 6, 7);
//    AddCourse(DS, 5, 8);
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
//    Quit(&DS);
//    cout << "***********" << endl;
//    AddCourse(DS2, 2, 20);
//    AddCourse(DS2, 6, 7);
//    AddCourse(DS2, 5, 8);
//    AddCourse(DS2, 9, 13);
//    AddCourse(DS2, 1, 10);
//    WatchClass(DS2, 2, 3, 14);
//    WatchClass(DS2, 2, 1, 5);
//    WatchClass(DS2, 2, 7, 59);
//    WatchClass(DS2, 2, 4, 13);
//    RemoveCourse(DS2,9);
//    WatchClass(DS2, 6, 1, 65);
//    WatchClass(DS2, 1, 2, 5);
//    WatchClass(DS2, 9, 6, 55);
//    WatchClass(DS2, 2, 12, 59);
//    RemoveCourse(DS2,1);
//    RemoveCourse(DS2,2);
//
//    WatchClass(DS2, 5, 1, 13);
//    WatchClass(DS2, 2, 0, 65);
//
//    int courses2[7] = {0};
//    int classes2[7] = {0};
//    GetMostViewedClasses(DS2, 7, courses2, classes2);
//    for (int i = 0; i < 7; ++i) {
//        cout << "Course : " << courses2[i] << " | Lecture : " << classes2[i] << endl;
//    }
//
//    Quit(&DS2);
//    return 0;
//}