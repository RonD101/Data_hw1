#ifndef HW1_COURSE_H
#define HW1_COURSE_H

#include "TemArray.h"
#include "Lecture.h"
#include "AVL.h"
#include "List.h"

class Course {
    public:
        explicit Course(int id, int num_of_lectures = 0) : id(id), lectures(TemArray<Lecture>(num_of_lectures)), pointers_to_empty_lectures(TemArray<Node<int>*>(num_of_lectures))
        {
            for (int i = num_of_lectures - 1; i >= 0; --i)
                pointers_to_empty_lectures[i] = empty_lecture.addAtStart(i);
        };

        int id;
        TemArray<Lecture> lectures;
        List<int> empty_lecture;
        TemArray<Node<int>*> pointers_to_empty_lectures;

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
