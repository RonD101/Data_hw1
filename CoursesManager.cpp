//
// Created by user on 30/11/2020.
//
#include "CoursesManager.h"

/* A function that constructs Balanced Binary Search Tree
from a sorted array */
AVLNode<Lecture>* sortedArrayToBST(int arr[], int start, int end) {
    /* Base Case */
    if (start > end)
        return nullptr;

    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    auto* l = new Lecture(arr[mid], 0);
    auto* root = new AVLNode<Lecture>(*l);

    /* Recursively construct the left subtree
    and make it left child of root */
    root->set_left(sortedArrayToBST(arr, start, mid - 1));

    /* Recursively construct the right subtree
    and make it right child of root */
    root->set_right(sortedArrayToBST(arr, mid + 1, end));

    return root;
}

void *CoursesManager::Init() {
    auto* boom = new CoursesManager();
    return boom;
}

StatusType CoursesManager::AddCourse(void *DS, int courseID, int numOfClasses) {
    auto* boom = static_cast<CoursesManager*>(DS);
    int *arr = new int[numOfClasses];
    for (int i = 0; i < numOfClasses; ++i) {
        arr[i] = i;
    }
    auto* new_course = new Course(courseID);
    new_course->lectures_tree->set_root(sortedArrayToBST(arr, 0, numOfClasses));
    new_course->lectures_tree->in_order(new_course->lectures_tree->get_root());
    boom->course_tree.insert_value(*new_course);
    delete [] arr;
    return SUCCESS;
}



