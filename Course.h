#ifndef HW1_COURSE_H
#define HW1_COURSE_H
#include "AVL.h"
#include "Lecture.h"
class Course {
    public:
        explicit Course(int id) : id(id) {};
        int id;
        AVLTree<Lecture>* lectures_tree;
        bool operator==(const Course other) const {
            return (id == other.id);
        }
        bool operator<(const Course other) const {
            return (id < other.id);
        }
        bool operator>(const Course other) const {
            return (id > other.id);
        }
};
#endif //HW1_COURSE_H
