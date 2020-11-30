#ifndef HW1_COURSE_H
#define HW1_COURSE_H
#include "AVL.h"
#include "Lecture.h"
class Course {
    public:
        explicit Course(int id) : id(id) {
            lectures_tree = new AVLTree<Lecture>();
        };
        int id;
        AVLTree<Lecture> lectures_tree;
        bool operator==(Lecture other) const {
            return (id == other.id);
        }
        bool operator<(Lecture other) const {
            return (id < other.id);
        }
        bool operator>(Lecture other) const {
            return (id > other.id);
        }
};
#endif //HW1_COURSE_H
