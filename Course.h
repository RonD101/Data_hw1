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
            //head_of_empty_lecture = empty_lecture.addAtStart(-1);
        };
        //Node<int>* head_of_empty_lecture;
        int id;
        TemArray<Lecture> lectures;
        List<int> empty_lecture;
        TemArray<Node<int>*> pointers_to_empty_lectures;


        Course(const Course& course){
            id = course.id;
            lectures = course.lectures;
            auto head = course.empty_lecture.head;
            if (head == nullptr)
                return;
            auto end_list = empty_lecture.addAtStart(head->getData());
            pointers_to_empty_lectures = TemArray<Node<int>*>(lectures.size());
            int counter = 0;
            pointers_to_empty_lectures[counter] = end_list;
            head = head->getNext();
            while(head){
                counter++;
                end_list = empty_lecture.addNodeAfter(end_list,head->getData());
                pointers_to_empty_lectures[counter] = end_list;
                head = head->getNext();
            }
        }

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
