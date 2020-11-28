#ifndef GENERIC_AVL_H
#define GENERIC_AVL_H

#include <iostream>

static int max(int a, int b){
    return (a > b) ? a : b;
}



    template <class T>
    class AVLNode {
    public:
        explicit AVLNode(const T& value) : data(value), left(nullptr), right(nullptr), parent(nullptr),height(0), balance_factor(0) {}
        ~AVLNode() = default;
        const T& get_value() const { return data; }

        void set_balanced_factor(int new_balance_factor) { balance_factor = new_balance_factor; }
        void set_parent(AVLNode* new_parent) { this->parent = new_parent; }
        void set_right(AVLNode* new_right)   { this->right = new_right; }
        void set_left(AVLNode* new_left)     { this->left = new_left; }
        void set_height(int new_height)      { height = new_height; }

        void print_node() const { std::cout << data << std::endl; }

        int get_balance_factor() { return balance_factor; }
        int get_height()  {
            if(this == nullptr)
                return -1;
            return height;
        }

        AVLNode* get_parent() const { return parent; }
        AVLNode* get_right()  const { return right; }
        AVLNode* get_left()   const { return left; }

    //private:
        T     data;
        AVLNode* left;
        AVLNode* right;
        AVLNode* parent;
        int height;
        int balance_factor;
    };

    template <class T>
    class AVLTree {
    public:
        AVLTree() : my_root(nullptr) {}
        ~AVLTree();

        AVLNode<T>* find_value(AVLNode<T>* root, const T& value, bool* side_flag = nullptr) const;
        AVLNode<T>* get_root() const { return my_root; }

        int  get_tree_height(AVLNode<T>* root) const;
        int  get_balance_factor(AVLNode<T>* current_node) const;

        AVLNode<T>* rotate_left (AVLNode<T>* current_node);
        AVLNode<T>* rotate_right(AVLNode<T>* current_node);
        void insert_value(const T& value);
        AVLNode<T>* delete_value(AVLNode<T>* root, const T &value);
        void in_order (AVLNode<T>* root) const;

    private:
        AVLNode<T>* my_root;
        void insert_node(AVLNode<T>* root, AVLNode<T>* ins);
        void delete_node(AVLNode<T>* node);

    };

template <class T>
static AVLNode<T>* find_min(AVLNode<T>* root)
{
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
    if(node) {
        delete_node(node->get_left());
        delete_node(node->get_right());
        delete node;
    }
}

template <class T>
void AVLTree<T>::insert_value(const T& value) {
    auto* new_node = new AVLNode<T>(value);
    if(!my_root) // Creating a root.
        my_root = new_node;
    else
        insert_node(my_root, new_node);

}

template <class T>
void AVLTree<T>::insert_node(AVLNode<T>* root, AVLNode<T>* ins) {

    if( ins->get_value() <= root->get_value() ) {
        if(root->get_left()) // If there is a left child, keep going left.
            insert_node(root->get_left(), ins);
        else {
            root->set_left(ins);
            ins->set_parent(root);
        }
    }
    else {
        if(root->get_right()) // If there is a right child, keep going right.
            insert_node(root->get_right(), ins);
        else {
            root->set_right(ins);
            ins->set_parent(root);
        }
    }

    // Balance the tree.
    int balance = get_tree_height(root->get_left()) - get_tree_height(root->get_right());
    root->set_balanced_factor(balance);
    if(balance > 1) { // Left tree is unbalanced
        if(get_balance_factor( root->get_left() ) < 0) // LR rotation needed.
            rotate_left(root->get_left());
        rotate_right(root);
    }
    else if(balance < -1) { // Right tree is unbalanced.
        if(get_balance_factor( root->get_right() ) > 0) // RL rotation needed.
            rotate_right( root->get_right() );
        rotate_left(root);
    }
    root->set_height(max(get_tree_height(root->get_left()) ,get_tree_height(root->get_right())) + 1);
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
AVLNode<T>* AVLTree<T>::find_value(AVLNode<T>* root, const T& value, bool* side_flag) const {
    if(root) {
        if(root->get_value() == value)
            return root;
        else if(value < root->get_value()) {
            *side_flag = false;
            return find_value(root->get_left(), value);
        }
        else {
            *side_flag = true;
            return find_value(root->get_right(), value);
        }
    }
    return nullptr;
}

template <class T>
int AVLTree<T>::get_tree_height(AVLNode<T>* root) const {
    if(root == nullptr)
        return -1;
    return root->get_height();
}

template <class T>
int  AVLTree<T>::get_balance_factor(AVLNode<T>* current_node) const {
    return current_node->get_balance_factor();
}

template <class T>
AVLNode<T>* AVLTree<T>::rotate_left(AVLNode<T>* current_node) {
    AVLNode<T>* new_root = current_node->get_right();
    current_node->set_right(new_root->get_left());
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

        // Element found
        // With 2 children
    else if(root->get_left() && root->get_right())
    {
        temp = find_min(root->get_right());
        root->data = temp->data;
        root->set_right(delete_value(root->get_right(), root->data));
    }
        // With one or zero child
    else
    {
        temp = root;
        if(root->get_left() == nullptr)
            root = root->get_right();
        else if(root->get_right() == nullptr)
            root = root->get_left();
        delete temp;
    }
    if(root == nullptr)
        return root;

    root->set_height(max(root->get_left()->get_height(), root->get_right()->get_height() + 1));

    // If node is unbalanced
    // If left node is deleted, right case
    if((root->get_left()->get_height() - root->get_right()->get_height()) == 2)
    {
        // right right case
        if((root->get_left()->get_left()->get_height() - root->get_left()->get_right()->get_height()) == 1)
            return rotate_left(root);
            // right left case
        else
        {
            root->set_right(rotate_right(root->get_right()));
            return rotate_left(root);
        }

    }
        // If right node is deleted, left case
    else if((root->get_right()->get_height() - root->get_left()->get_height()) == 2)
    {
        // left left case
        if((root->get_right()->get_right()->get_height() - root->right->get_left()->get_height()) == 1)
            return rotate_right(root);
            // left right case
        else
        {
            root->set_left(rotate_left(root->get_left()));
            return rotate_left(root);
        }
    }
    return root;
}

#endif // GENERIC_AVL_H