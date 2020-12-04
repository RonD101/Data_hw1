#ifndef HW1_COURSESMANAGER_H
#define HW1_COURSESMANAGER_H
#include "library.h"
#include "AVL.h"
#include "Course.h"
#include "List.h"
#include "ViewData.h"
#include <memory>
#include "EmptyCourse.h"

class CoursesManager {
public:
    ~CoursesManager() = default;
    AVLTree<Course> course_tree;
    AVLTree<ViewData> watched_lecture_tree;
//    AVLTree<int> empty_courses_id;
    AVLTree<EmptyCourse> empty_courses_id;
    AVLNode<EmptyCourse>* smallest_empty_course = nullptr;
    int lectures_counter = 0;
    StatusType AddCourse (int courseID, int numOfClasses);

    StatusType RemoveCourse(int courseID);

    StatusType WatchClass(int courseID, int classID, int time);

    StatusType TimeViewed(int courseID, int classID, int *timeViewed);

    StatusType GetMostViewedClasses(int numOfClasses, int *courses, int *classes);

    void Quit();

};

#endif //HW1_COURSESMANAGER_H