#ifndef HW1_COURSE_H
#define HW1_COURSE_H

#include "TemArray.h"
#include "Lecture.h"
#include "AVL.h"
#include "List.h"

class Course {
    public:
        explicit Course(int id, int num = 0) : id(id) , lectures(TemArray<Lecture>(num)) {};
        int id;
        TemArray<Lecture> lectures;
        
        // Courses are ordered by id only.
        bool operator==(const Course &other) const {
            return (id == other.id);
        }
        bool operator<(const Course &other) const {
            return (id < other.id);
        }
        bool operator>(const Course &other) const {
            return (id > other.id);
        }
        friend std::ostream& operator<<(std::ostream& os, const Course& c){
            os << "Course ID : " << c.id << std::endl;
            for(int i = 0; i < c.lectures.size(); i++)
                os << c.lectures[i] << std::endl;
            return os;
        }
};
#endif //HW1_COURSE_H
