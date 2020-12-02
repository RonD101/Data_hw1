#include "CoursesManager.h"

StatusType CoursesManager::AddCourse(int courseID, int numOfClasses) {

    Course new_course(courseID, numOfClasses);
    for (int i = 0; i < numOfClasses; ++i)
        new_course.lectures[i] = Lecture(i, 0, courseID);

    if(course_tree.insert_value(new_course) && empty_courses_id.insert_value(courseID))
        return SUCCESS;

    return FAILURE;
}

StatusType CoursesManager::RemoveCourse(int courseID) {
    Course temp_course(courseID);
    // remove course from empty tree and try to remove it from the main tree.
    empty_courses_id.delete_value(empty_courses_id.get_root(), courseID);

    // remove all lectures associated with the course from the "big" lecture tree.
    for (int i = 0; i < course_tree.find_value(course_tree.get_root(), temp_course)->data.lectures.size(); ++i) {
        Lecture temp_lecture(courseID, 0, i);
        watched_lecture_tree.delete_value(watched_lecture_tree.get_root(), temp_lecture);
    }

    if(course_tree.delete_value(course_tree.get_root(), temp_course) == nullptr)
        return FAILURE;
    return SUCCESS;
}

StatusType CoursesManager::WatchClass(int courseID, int classID, int time) {
    int old_time_viewed = (course_tree.find_value(course_tree.get_root(),Course(courseID)))->data.lectures[classID].timed_watched;
    if(old_time_viewed > 0)
        watchedTree.delete_value(watchedTree.get_root(), ViewData(courseID,classID, old_time_viewed));
    watchedTree.insert_value(ViewData(courseID,classID, old_time_viewed + time));
    (course_tree.find_value(course_tree.get_root(),Course(courseID))->data.lectures[classID]).add_time(time);

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
