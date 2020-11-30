#ifndef HW1_COURSESMANAGER_H
#define HW1_COURSESMANAGER_H
#include "library.h"
#include "AVL.h"
#include "Course.h"

class CoursesManager {
    public:
        AVLTree<Course> course_tree;

    void *Init();

    StatusType AddCourse (void *DS, int courseID, int numOfClasses);

    StatusType RemoveCourse(void *DS, int courseID);

    StatusType WatchClass(void *DS, int courseID, int classID, int time);

    StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed);

    StatusType GetMostViewedClasses(void *DS, int numOfClasses, int *courses, int *classes);

    void Quit(void** DS);

};


#endif //HW1_COURSESMANAGER_H
