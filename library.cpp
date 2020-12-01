#include "library.h"
#include "CoursesManager.h"
void *Init() {
    CoursesManager *DS = new CoursesManager ();
    return (void*)DS;
}

StatusType AddCourse(void *DS, int courseID, int numOfClasses) {
    if(numOfClasses <= 0 || courseID <= 0 || DS == nullptr)
        return INVALID_INPUT;
    try {
        StatusType status(((CoursesManager *)DS)->AddCourse(courseID, numOfClasses));
        return status;
    }
    catch (const std::bad_alloc&) {
        return ALLOCATION_ERROR;
    }
}

StatusType RemoveCourse(void *DS, int courseID) {
    if(courseID <= 0 || DS == nullptr)
        return INVALID_INPUT;
    try {
        StatusType status(((CoursesManager *)DS)->RemoveCourse(courseID));
        return status;
    }
    catch (const std::bad_alloc&) {
        return ALLOCATION_ERROR;
    }
}
