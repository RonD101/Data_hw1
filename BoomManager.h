#ifndef HW1_BOOMMANAGER_H
#define HW1_BOOMMANAGER_H
#include "library.h"
#include "AVL.h"
#include "Course.h"

class BoomManager {
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


#endif //HW1_BOOMMANAGER_H
