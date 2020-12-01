#include "CoursesManager.h"


StatusType CoursesManager::AddCourse(int courseID, int numOfClasses) {
    auto* new_course = new Course(courseID, numOfClasses);
    for (int i = 0; i < numOfClasses; ++i) {
        new_course->lectures[i] = Lecture(i, 0);
    }

    if(course_tree.insert_value(*new_course))
        return SUCCESS;
    return FAILURE;
}

StatusType CoursesManager::RemoveCourse(int courseID) {
    Course temp_course(courseID);
    if(course_tree.delete_value(course_tree.get_root(), temp_course) == nullptr)
        return  FAILURE;
    return SUCCESS;
}

StatusType CoursesManager::WatchClass(int courseID, int classID, int time) {

    return INVALID_INPUT;
}
