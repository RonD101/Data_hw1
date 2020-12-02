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
    AVLNode<Course>* temp_node = course_tree.find_value(course_tree.get_root(), Course(courseID));

    // no class with this id in course.
    if(temp_node != nullptr && (classID + 1 > temp_node->data.lectures.size()))
        return INVALID_INPUT;
    // no course with this id.
    if(temp_node == nullptr)
        return FAILURE;


    int old_time_viewed = temp_node->data.lectures[classID].timed_watched;
    // remove old lecture from watched tree and insert the new one (with the updated time).
    if(old_time_viewed > 0)
        watched_lecture_tree.delete_value(watched_lecture_tree.get_root(), ViewData(courseID,classID, old_time_viewed));
    watched_lecture_tree.insert_value(ViewData(courseID, classID, old_time_viewed + time));
    temp_node->data.lectures[classID].add_time(time);

    // if no empty lectures left in course, remove it from empty_tree.
    if(temp_node->data.empty_lecture.head == nullptr)
        empty_courses_id.delete_value(empty_courses_id.get_root(), courseID);


    // remove class from empty list and set pointer to that list to null (if it is not null already).
    if(temp_node->data.pointers_to_empty_lectures[classID] != nullptr)
        temp_node->data.empty_lecture.removeNode(temp_node->data.pointers_to_empty_lectures[classID]);
    temp_node->data.pointers_to_empty_lectures[classID] = nullptr;
    return SUCCESS;
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

StatusType CoursesManager::GetMostViewedClasses(int numOfClasses, int *courses, int *classes) {
    int cnt = numOfClasses;
    watched_lecture_tree.reverse_in_order(watched_lecture_tree.get_root(), &cnt);

    return SUCCESS;
}
