#ifndef HW1_COURSESMANAGER_H
#define HW1_COURSESMANAGER_H
#include "library.h"
#include "AVL.h"
#include "Course.h"
#include "List.h"
#include "ViewData.h"

class CoursesManager {
public:
    AVLTree<Course> course_tree;
    AVLTree<ViewData> watched_lecture_tree;
    AVLTree<int> empty_courses_id;

    StatusType AddCourse (int courseID, int numOfClasses);

    StatusType RemoveCourse(int courseID);

    StatusType WatchClass(int courseID, int classID, int time);

    StatusType TimeViewed(int courseID, int classID, int *timeViewed);

    StatusType GetMostViewedClasses(int numOfClasses, int *courses, int *classes);

    void Quit(void** DS);

};


#endif //HW1_COURSESMANAGER_H
