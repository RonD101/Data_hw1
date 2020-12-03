#ifndef GENERIC_AVL_H
#define GENERIC_AVL_H

#include <iostream>
#include "AVLNode.h"

template <class T>
class AVLTree {
    public:
        explicit AVLTree() : my_root(nullptr), nodes_counter(0) {}
        ~AVLTree();
        AVLNode<T>* find_value(AVLNode<T>* root, const T& value) const;
        AVLNode<T>* delete_value(AVLNode<T>* root, const T &value);
        AVLNode<T>* get_root() const { return my_root; }
        AVLNode<T>* find_min(AVLNode<T>* root);

        void reverse_in_order(AVLNode<T>* root, int* remained, int* counted, int *courses, int *classes) const;
        void in_order (AVLNode<T>* root) const;
        bool insert_value(const T& value);
        void delete_node(AVLNode<T>* node);
    private:
        AVLNode<T>* my_root;
        int nodes_counter;

        AVLNode<T>* rotate_left (AVLNode<T>* current_node);
        AVLNode<T>* rotate_right(AVLNode<T>* current_node);

        bool insert_node(AVLNode<T>* root, const T& value);


        int get_balance_factor(AVLNode<T>* current_node) const;
        int get_tree_height(AVLNode<T>* root) const;
};

template <class T>
AVLNode<T>* AVLTree<T>::find_min(AVLNode<T>* root) {
    if(nodes_counter <= 0)
        return nullptr;
    if(root == nullptr)
        return nullptr;
    else if(root->get_left() == nullptr)
        return root;
    else
        return find_min(root->get_left());
}

template <class T>
AVLTree<T>::~AVLTree() {
    if(my_root)
        delete_node(my_root);
}

template <class T>
void AVLTree<T>::delete_node(AVLNode<T>* node) {
    // deletes all subtree of node and node itself.
    if(nodes_counter <= 0)
        return;
    if(node) {
        delete_node(node->get_left());
        delete_node(node->get_right());
        delete node;
    }
}

template <class T>
bool AVLTree<T>::insert_value(const T& value) {
    if(my_root == nullptr || nodes_counter == 0) {
        // Creating a root, if tree is empty.
        auto* new_node = new AVLNode<T>(value);
        my_root = new_node;
        nodes_counter++;
        return true;
    }
    else
        return(insert_node(my_root, value));
}

template <class T>
static int max(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
bool AVLTree<T>::insert_node(AVLNode<T>* root, const T& value) {
    if(root->get_value() == value)
        return false;
    else if(value < root->get_value()) {
        if(root->get_left()) // If there is a left child, keep going left.
            insert_node(root->get_left(), value);
        else {
            auto* new_node = new AVLNode<T>(value);
            root->set_left(new_node);
            new_node->set_parent(root);
            nodes_counter++;
        }
    }
    else {
        if(root->get_right()) // If there is a right child, keep going right.
            insert_node(root->get_right(), value);
        else {
            auto* new_node = new AVLNode<T>(value);
            root->set_right(new_node);
            new_node->set_parent(root);
            nodes_counter++;
        }
    }

    // Balance the tree.
    int balance = get_tree_height(root->get_left()) - get_tree_height(root->get_right());
    root->set_balanced_factor(balance);
    if(balance > 1) { // Left tree is unbalanced
        if(get_balance_factor(root->get_left()) < 0) // LR rotation needed.
            rotate_left(root->get_left());
        rotate_right(root);
    }
    else if(balance < -1) { // Right tree is unbalanced.
        if(get_balance_factor(root->get_right()) > 0) // RL rotation needed.
            rotate_right(root->get_right());
        rotate_left(root);
    }
    balance = get_tree_height(root->get_left()) - get_tree_height(root->get_right());
    root->set_balanced_factor(balance);
    root->set_height(max(get_tree_height(root->get_left()), get_tree_height(root->get_right())) + 1);
    return true;
}

template <class T>
void AVLTree<T>::in_order(AVLNode<T>* root) const {
    if(nodes_counter <= 0)
        return;
    if(root) {
        in_order(root->get_left());
        root->print_node();
        in_order(root->get_right());
    }
}

// Traverse the right subtree by recursively calling the reverse in-order function.
// Access the data part of the current node.
// Traverse the left subtree by recursively calling the reverse in-order function.
template <class T>
void AVLTree<T>::reverse_in_order(AVLNode<T>* root, int* remained, int* counted, int *courses, int *classes) const {
    // need to implement
    if(root) {
        reverse_in_order(root->get_right(), remained, counted, courses, classes);
        if(*remained <= 0)
            return;
        root->print_node();
        courses[*counted] = root->data.getCourse();
        classes[*counted] = root->data.getLecture();
        *remained = *remained - 1;
        *counted = *counted + 1;
        reverse_in_order(root->get_left(), remained, counted, courses, classes);
    }
}

template <class T>
AVLNode<T>* AVLTree<T>::find_value(AVLNode<T>* root, const T& value) const {
    if(root) {
        if (root->get_value() == value)
            return root;
        else if (value < root->get_value())
            return find_value(root->get_left(), value);
        else
            return find_value(root->get_right(), value);
    }
    return nullptr;
}

template <class T>
int AVLTree<T>::get_tree_height(AVLNode<T>* root) const {
    if(root == nullptr)
        return -1;
    return AVLNode<T>::get_height(root);
}

template <class T>
int AVLTree<T>::get_balance_factor(AVLNode<T>* current_node) const {
    return current_node->get_balance_factor();
}

template <class T>
AVLNode<T>* AVLTree<T>::rotate_left(AVLNode<T>* current_node) {

    AVLNode<T>* new_root = current_node->get_right();
    current_node->set_right(new_root->get_left());
    if(new_root->get_left())
        (new_root->get_left())->set_parent(current_node);
    new_root->set_left(current_node);

    if(current_node->get_parent() == nullptr) {
        my_root = new_root;
        new_root->set_parent(nullptr);
    }
    else {
        if(current_node->get_parent()->get_left() == current_node)
            current_node->get_parent()->set_left(new_root);
        else
            current_node->get_parent()->set_right(new_root);
        new_root->set_parent(current_node->get_parent());
    }
    current_node->set_parent(new_root);
    return new_root;
}

template <class T>
AVLNode<T>* AVLTree<T>::rotate_right(AVLNode<T>* current_node) {
    // Rotate node
    AVLNode<T>* new_root = current_node->get_left();
    current_node->set_left(new_root->get_right());
    if(new_root->get_right())
        (new_root->get_right())->set_parent(current_node);
    new_root->set_right(current_node);

    // Adjust tree
    if(current_node->get_parent() == nullptr) {
        my_root = new_root;
        new_root->set_parent(nullptr);
    }
    else {
        if(current_node->get_parent()->get_left() == current_node)
            current_node->get_parent()->set_left(new_root);
        else
            current_node->get_parent()->set_right(new_root);
        new_root->set_parent(current_node->get_parent());
    }
    current_node->set_parent(new_root);
    return new_root;
}

template <class T>
AVLNode<T>* AVLTree<T>::delete_value(AVLNode<T>* root, const T &value) {
    if(root == nullptr)
        return nullptr;
    AVLNode<T>* temp_node = find_value(root, value);
    // value not in tree
    if(temp_node == nullptr)
        return nullptr;

    AVLNode<T>* left = temp_node->get_left();
    AVLNode<T>* right = temp_node->get_right();

    // we are the root
    if(my_root == temp_node) {
        // we have no children.
        if (left == nullptr && right == nullptr) {
            delete temp_node;
            my_root = nullptr;
            nodes_counter = 0;
        }
        // we have left child.
        else if (left != nullptr && right == nullptr) {
            left->set_parent(nullptr);
            my_root = left;
            delete temp_node;
        }
        // we have right child
        else if (left == nullptr && right != nullptr) {
            right->set_parent(nullptr);
            my_root = right;
            delete temp_node;
        }
        // we have two children
        else if(left != nullptr && right != nullptr) {
            AVLNode<T>* next_in_order = find_min(right);
            next_in_order->get_parent()->set_left(nullptr);
            next_in_order->set_left(left);
            next_in_order->set_right(right);
            next_in_order->set_parent(nullptr);
            my_root = next_in_order;
        }
    }
    // we are leaf
    else if(left == nullptr && right == nullptr) {
        // we are left child
        if(temp_node->get_parent()->get_left() == temp_node)
            temp_node->get_parent()->set_left(nullptr);
        else
            temp_node->get_parent()->set_right(nullptr);
        delete temp_node;
        nodes_counter--;
    }
    // we have one child
    else if(left == nullptr || right == nullptr) {
        // we are left child.
        if(temp_node->get_parent()->get_left() == temp_node) {
            // we have right child.
            if(left == nullptr) {
                temp_node->get_parent()->set_left(temp_node->get_right());
                temp_node->get_right()->set_parent(temp_node->get_parent());
            }
            else { // we have left child.
                temp_node->get_parent()->set_left(temp_node->get_left());
                temp_node->get_left()->set_parent(temp_node->get_parent());
            }
        }
        else { // we are right child.
            if(left == nullptr) {
                temp_node->get_parent()->set_right(temp_node->get_right());
                temp_node->get_right()->set_parent(temp_node->get_parent());
            }
            else { // we have left child.
                temp_node->get_parent()->set_right(temp_node->get_left());
                temp_node->get_left()->set_parent(temp_node->get_parent());
            }
        }
        delete temp_node;
        nodes_counter--;
    }
    // we have two children
    else if(left != nullptr && right != nullptr) {
    }
}

#endif // GENERIC_AVL_H