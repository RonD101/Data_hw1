//
// Created by Ron Dahan on 04/12/2020.
//

#ifndef HW1_EMPTYCOURSE_H
#define HW1_EMPTYCOURSE_H
#include "AVL.h"
#include "Course.h"

class EmptyCourse {
    int courseID;
    AVLNode<Course>* course_ptr;
public:
    explicit EmptyCourse(int courseID = 0 ,AVLNode<Course>* course_ptr = nullptr) : courseID(courseID), course_ptr(course_ptr){}
    void setCourseID(int new_course_ID) { courseID = new_course_ID; }
    void setCoursePtr(AVLNode<Course>* new_course_ptr) { course_ptr = new_course_ptr; }
    int getCourseID() const { return courseID; }
    AVLNode<Course>* getCoursePtr() const { return course_ptr; }

    bool operator<(const EmptyCourse& data) const {
        return courseID < data.courseID;
    }
    bool operator>(const EmptyCourse& data) const {
        return (data < *this);
    }
    bool operator==(const EmptyCourse& data) const {
        return (courseID == data.courseID);
    }

    friend std::ostream& operator<<(std::ostream& os, const EmptyCourse& data) {
        os << "Course ID : " << data.courseID<< std::endl;
        return os;
    }
};

#endif //HW1_EMPTYCOURSE_H