#include "CoursesManager.h"

void sortedArrayToBST(AVLNode<Lecture>* root, int start, int end)
{
    if(start > end)
        return;

    int mid = (start + end) / 2;
    int l_mid = (mid - start) / 2;
    int r_mid = (end - mid + 1) / 2;
    Lecture left_l(l_mid, 0);
    Lecture right_l(r_mid, 0);
    AVLNode<Lecture> left_n(left_l);
    AVLNode<Lecture> right_n(right_l);
    left_n.set_parent(root);
    right_n.set_parent(root);
    root->set_left(&left_n);
    root->set_right(&right_n);
    sortedArrayToBST(root->get_left(), start, mid - 1);
    sortedArrayToBST(root->get_right(), mid + 1, end);
}

StatusType CoursesManager::AddCourse(int courseID, int numOfClasses) {
    Course new_course(courseID);
    Lecture temp(numOfClasses/2, 0);
    AVLNode<Lecture> root(temp);
    sortedArrayToBST(&root, 0, numOfClasses);
    new_course.lectures_tree->set_root(&root);
    new_course.lectures_tree->in_order(new_course.lectures_tree->get_root());
    course_tree.insert_value(new_course);
    return SUCCESS;
}