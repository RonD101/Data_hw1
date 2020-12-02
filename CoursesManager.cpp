#include <memory>
#include "CoursesManager.h"

StatusType CoursesManager::AddCourse(int courseID, int numOfClasses) {
    auto* new_course = new Course(courseID, numOfClasses);
    for (int i = 0; i < numOfClasses; ++i)
        new_course->lectures[i] = Lecture(i, 0, courseID);

    if(course_tree.insert_value(*new_course) && empty_courses_id.insert_value(courseID))
        return SUCCESS;

    return FAILURE;
}

StatusType CoursesManager::RemoveCourse(int courseID) {
    Course temp_course(courseID);
    // remove course from empty tree and try to remove it from the main tree.
    empty_courses_id.delete_value(empty_courses_id.get_root(), courseID);

    // remove all lectures associated with the course from the "big" lecture tree.
    auto temp_list = course_tree.find_value(course_tree.get_root(), temp_course)->data.lectures;
    for (int i = 0; i < temp_list.size(); ++i) {
        ViewData temp_lecture(courseID, i, temp_list[i].timed_watched);
        watched_lecture_tree.delete_value(watched_lecture_tree.get_root(), temp_lecture);
    }

    if(course_tree.delete_value(course_tree.get_root(), temp_course) == nullptr)
        return FAILURE;
    return SUCCESS;
}

StatusType CoursesManager::WatchClass(int courseID, int classID, int time) {
    int old_time_viewed = (course_tree.find_value(course_tree.get_root(),Course(courseID)))->data.lectures[classID].timed_watched;
    if(old_time_viewed > 0)
        watched_lecture_tree.delete_value(watched_lecture_tree.get_root(), ViewData(courseID,classID, old_time_viewed));
    watched_lecture_tree.insert_value(ViewData(courseID,classID, old_time_viewed + time));
    (course_tree.find_value(course_tree.get_root(),Course(courseID))->data.lectures[classID]).add_time(time);
    Course temp_course(courseID);
    temp_course = course_tree.find_value(course_tree.get_root(), temp_course)->data;

    // if no empty lectures left in course, remove it from empty_tree.
    if(temp_course.empty_lecture.head == nullptr)
        empty_courses_id.delete_value(empty_courses_id.get_root(), courseID);


    /*
     * Course temp_course(courseID);
    AVLNode<Course>* temp_node = course_tree.find_value(course_tree.get_root(), temp_course);
    if(temp_node != nullptr && (classID + 1 > temp_node->data.lectures.size()))
        return INVALID_INPUT;
    if(temp_node == nullptr)
        return FAILURE;

    // try to remove course from empty tree.
    empty_courses_id.delete_value(empty_courses_id.get_root(), courseID);

    // add time to the lecture array in the course.
    int old_time = temp_node->data.lectures[classID].timed_watched;
    temp_node->data.lectures[classID].add_time(time);
    Lecture temp_lecture(classID, old_time, courseID);

    // remove lecture from lecture tree and add a new one (to make sure we reserve the tree)
    watched_lecture_tree.delete_value(watched_lecture_tree.get_root(), temp_lecture);
    temp_lecture.timed_watched += time;
    watched_lecture_tree.insert_value(temp_lecture);

    // fix pointer array in course.
     *
     */
    return INVALID_INPUT;
}

StatusType CoursesManager::TimeViewed(int courseID, int classID, int *timeViewed) {
    Course temp_course(courseID);
    AVLNode<Course>* temp = course_tree.find_value(course_tree.get_root(), temp_course);
    // no course with such id.
    if(temp != nullptr && classID > temp->data.lectures.size())
        return INVALID_INPUT;

    // no class with such id.
    if(temp == nullptr)
        return FAILURE;

    *timeViewed = temp->data.lectures[classID].timed_watched;
    return SUCCESS;
}
