#include "CoursesManager.h"

void sortedArrayToBST(AVLNode<Lecture>* root, int start, int end, bool* left_flag)
{
    if(start >= end)
        return;

    int mid = (start + end) / 2;
    int l_mid = (mid - start) / 2;
    int r_mid = mid + ((end - mid) / 2);
    Lecture left_l(l_mid, 0);
    if(mid != l_mid && !left_flag)
    {
        AVLNode<Lecture> left_n(left_l);
        left_n.set_parent(root);
        root->set_left(&left_n);
        sortedArrayToBST(root->get_left(), start, mid, left_flag);
    } else
        *left_flag = true;
    if(mid != r_mid)
    {
        Lecture right_l(r_mid, 0);
        AVLNode<Lecture> right_n(right_l);
        right_n.set_parent(root);
        root->set_right(&right_n);
        sortedArrayToBST(root->get_right(), mid, end, left_flag);
    }
}

StatusType CoursesManager::AddCourse(int courseID, int numOfClasses) {
    Course new_course(courseID);
    Lecture l(numOfClasses/2, 0);
    AVLNode<Lecture> root(l);
    bool* flag;
    *flag = false;
    sortedArrayToBST(&root, 0, numOfClasses, flag);
    new_course.lectures_tree->set_root(&root);
    new_course.lectures_tree->in_order(new_course.lectures_tree->get_root());
    course_tree.insert_value(new_course);
    return SUCCESS;
}