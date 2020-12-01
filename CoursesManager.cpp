#include "CoursesManager.h"


StatusType CoursesManager::AddCourse(int courseID, int numOfClasses) {
    auto* new_course = new Course(courseID);
    for (int i = 0; i < numOfClasses; ++i) {
        new_course->lectures_tree.insert_value(Lecture(i,0));
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
    Course temp_course(courseID);
    Lecture temp_lecture(classID, 0);
    temp_course = course_tree.find_value(course_tree.get_root(), temp_course)->data;
    temp_lecture = temp_course.lectures_tree.find_value(temp_course.lectures_tree.get_root(), temp_lecture)->data;
    temp_lecture.add_time(time);
    return INVALID_INPUT;
}
