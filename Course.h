#ifndef HW1_COURSE_H
#define HW1_COURSE_H
#include "AVL.h"
#include "Lecture.h"
class Course {
    public:
        explicit Course(int id) : id(id) {};
        int id;
        AVLTree<Lecture> lectures_tree;

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
            c.lectures_tree.in_order(c.lectures_tree.get_root());
            return os;
        }
};
#endif //HW1_COURSE_H
