#ifndef GENERIC_AVL_H
#define GENERIC_AVL_H

#include <iostream>
#include "AVLNode.h"

template <class T>
class AVLTree {
    public:
        explicit AVLTree(int id = 0, AVLNode<T>* root = nullptr) : tree_id(id), my_root(root) {}
        ~AVLTree();
        AVLNode<T>* find_value(AVLNode<T>* root, const T& value) const;
        AVLNode<T>* get_root() const { return my_root; }
        void set_root(AVLNode<T>* root) { my_root = root; }
        int  get_tree_height(AVLNode<T>* root) const;
        int  get_balance_factor(AVLNode<T>* current_node) const;

        AVLNode<T>* rotate_left (AVLNode<T>* current_node);
        AVLNode<T>* rotate_right(AVLNode<T>* current_node);
        void insert_value(const T& value);
        AVLNode<T>* delete_value(AVLNode<T>* root, const T &value);
        void in_order (AVLNode<T>* root) const;
        int tree_id;
    bool operator==(AVLTree other) const {
        return (tree_id == other.tree_id);
    }
    bool operator<(AVLTree other) const {
        return (tree_id < other.tree_id);
    }
    bool operator>(AVLTree other) const {
        return (tree_id > other.tree_id);
    }
    private:
        AVLNode<T>* my_root;
        void insert_node(AVLNode<T>* root, const T& value);
        void delete_node(AVLNode<T>* node);
};

template <class T>
static AVLNode<T>* find_min(AVLNode<T>* root) {
    if(root == nullptr)
        return nullptr;
    else if(root->left == nullptr)
        return root;
    else
        return find_min(root->left);
}

template <class T>
AVLTree<T>::~AVLTree() {
    if(my_root)
        delete_node(my_root);
}

template <class T>
void AVLTree<T>::delete_node(AVLNode<T>* node) {
    // deletes all subtree of node and node itself.
    if(node) {
        delete_node(node->get_left());
        delete_node(node->get_right());
        delete node;
    }
}

template <class T>
void AVLTree<T>::insert_value(const T& value) {
    if(my_root == nullptr)
    {
        // Creating a root, if tree is empty.
        auto* new_node = new AVLNode<T>(value);
        my_root = new_node;
    }
    else
            insert_node(my_root, value);
}

template <class T>
static int max(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
void AVLTree<T>::insert_node(AVLNode<T>* root, const T& value) {
    if(root->get_value() == value)
        return;
    else if(value < root->get_value()) {
        if(root->get_left()) // If there is a left child, keep going left.
            insert_node(root->get_left(), value);
        else {
            auto* new_node = new AVLNode<T>(value);
            root->set_left(new_node);
            new_node->set_parent(root);
        }
    }
    else {
        if(root->get_right()) // If there is a right child, keep going right.
            insert_node(root->get_right(), value);
        else {
            auto* new_node = new AVLNode<T>(value);
            root->set_right(new_node);
            new_node->set_parent(root);
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
}

template <class T>
void AVLTree<T>::in_order(AVLNode<T>* root) const {
    if(root) {
        in_order(root->get_left());
        root->print_node();
        in_order(root->get_right());
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

    AVLNode<T>* temp;
    // Element not found
    if(root == nullptr)
        return nullptr;
    // Searching for element
    else if(value < root->data)
        root->set_left(delete_value(root->get_left(), value));
    else if(value > root->data)
        root->set_right(delete_value(root->get_right(), value));
    // Element found with 2 children
    else if(root->get_left() && root->get_right()) {
        // go right, and than all the way left.
        temp = find_min(root->get_right());
        root->data = temp->data;
        root->set_right(delete_value(root->get_right(), root->data));
    }
    // With one or zero children.
    else {
        temp = root;
        if(root->get_left() == nullptr)
            root = root->get_right();
        else if(root->get_right() == nullptr)
            root = root->get_left();
        delete temp;
    }
    if(root == nullptr)
        return root;

    root->set_height(max(AVLNode<T>::get_height(root->get_left()), AVLNode<T>::get_height(root->get_right()) + 1));

    // If node is unbalanced
    // If left node is deleted, right case
    if(AVLNode<T>::get_height(root->get_left()) - AVLNode<T>::get_height(root->get_right()) == 2) {
        // right right case
        if((AVLNode<T>::get_height(root->get_left()->get_left())) - (AVLNode<T>::get_height(root->get_left()->get_right())) == 1)
            return rotate_left(root);
            // right left case
        else {
            root->set_right(rotate_right(root->get_right()));
            return rotate_left(root);
        }
    }

    // If right node is deleted, left case
    else if((AVLNode<T>::get_height(root->get_right())) - (AVLNode<T>::get_height(root->get_left())) == 2) {
        // left left case
        if((AVLNode<T>::get_height(root->get_right()->get_right())) - (AVLNode<T>::get_height(root->right->get_left())) == 1)
            return rotate_right(root);
            // left right case
        else {
            root->set_left(rotate_left(root->get_left()));
            return rotate_left(root);
        }
    }
    return root;
}

#endif // GENERIC_AVL_H