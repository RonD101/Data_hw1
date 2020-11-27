#ifndef GENERIC_AVL_H
#define GENERIC_AVL_H

#include <iostream>

static int max(int a, int b){
    return (a > b) ? a : b;
}
    template <class T>
    class AVLNode {
    public:
        AVLNode(const T& value) : data(value), left(NULL), right(NULL), parent(NULL),height(0), balanced(0) {}
        ~AVLNode() {}
        const T&  get_value() const { return data; }
        void      set_left(AVLNode* left) { this->left = left; }
        void      set_right(AVLNode* right) { this->right = right; }
        void      set_parent(AVLNode* parent) { this->parent = parent; }
        AVLNode*  get_parent() const { return parent; }
        AVLNode*  get_right() const { return right; }
        AVLNode*  get_left() const { return left; }

        int get_balanced_factor(){return balanced;}
        void set_balanced_factor(int new_balanced_factor){balanced = new_balanced_factor;}
        int get_height(){return height;}
        void set_height(int new_height){height = new_height;}
        void      print_node() const { std::cout << data << std::endl; }

    private:
        AVLNode();
        T     data;
        AVLNode* left;
        AVLNode* right;
        AVLNode* parent;
        int height;
        int balanced;
    };

    template <class T>
    class AVLTree {
    public:
        AVLTree() : my_root(NULL) {}
        ~AVLTree();

        bool insert_value(const T& value);
        AVLNode<T>* get_root() const { return my_root; }
        AVLNode<T>* find_value(AVLNode<T>* root, const T& value) const;

        int  get_tree_height(AVLNode<T>* root) const;
        int  get_balance_factor(AVLNode<T>* root) const;

        void rotate_left (AVLNode<T>* root);
        void rotate_right(AVLNode<T>* root);

        void inorder (AVLNode<T>* root) const;



    private:
        void insert_node(AVLNode<T>* root, AVLNode<T>* ins);
        void delete_node(AVLNode<T>* node);

        AVLNode<T>* my_root;
    };

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
    bool AVLTree<T>::insert_value(const T& value) {
        AVLNode<T>* new_node = new AVLNode<T>(value);

        if(!new_node)
            return true; // Out of memory

        if(!my_root) // Creating a root.
            my_root = new_node;
        else
            insert_node(my_root, new_node);
        return false;
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
        root->set_height(max(get_tree_height(root->get_left()),get_tree_height(root->get_right())) + 1);
    }

    template <class T>
    void AVLTree<T>::inorder(AVLNode<T>* root) const {
        if(root) {
            inorder(root->get_left());
            root->print_node();
            inorder(root->get_right());
        }
    }

    template <class T>
    AVLNode<T>* AVLTree<T>::find_value(AVLNode<T>* root, const T& value) const {
        if(root) {
            if( root->get_value() == value )
                return root;
            else if( value < root->get_value() )
                return find_value( root->get_left(), value );
            else
                return find_value( root->get_right(), value );
        }
        return NULL;
    }

    template <class T>
    int AVLTree<T>::get_tree_height(AVLNode<T>* root) const {
        if(root == NULL)
            return -1;
        return root->get_height();
//        int height = -1;
//        if(root) {
//            int left  = get_tree_height(root->get_left());
//            int right = get_tree_height(root->get_right());
//            if(left > right)
//                height = 1 + left;
//            else
//                height = 1 + right;
//        }
//        return height;
    }

    template <class T>
    int  AVLTree<T>::get_balance_factor(AVLNode<T>* current_node) const {
        return current_node->get_balanced_factor();
//        int balance = 0;
//        if(current_node)
//            balance = get_tree_height(current_node->get_left()) - get_tree_height(current_node->get_right());
//        return balance;
    }

    template <class T>
    void AVLTree<T>::rotate_left (AVLNode<T>* current_node) {
        AVLNode<T>* new_root = current_node->get_right();
        current_node->set_right(new_root->get_left());
        new_root->set_left(current_node);

        if(current_node->get_parent() == NULL) {
            my_root = new_root;
            new_root->set_parent(NULL);
        }
        else {
            if(current_node->get_parent()->get_left() == current_node)
                current_node->get_parent()->set_left(new_root);
            else
                current_node->get_parent()->set_right(new_root);
            new_root->set_parent(current_node->get_parent());
        }
        current_node->set_parent(new_root);
    }

    template <class T>
    void AVLTree<T>::rotate_right(AVLNode<T>* current_node) {
        // Rotate node
        AVLNode<T>* new_root = current_node->get_left();
        current_node->set_left(new_root->get_right());
        new_root->set_right(current_node);

        // Adjust tree
        if(current_node->get_parent() == NULL) {
            my_root = new_root;
            new_root->set_parent(NULL);
        }
        else {
            if(current_node->get_parent()->get_left() == current_node)
                current_node->get_parent()->set_left(new_root);
            else
                current_node->get_parent()->set_right(new_root);
            new_root->set_parent(current_node->get_parent());
        }
        current_node->set_parent(new_root);
    }

#endif // GENERIC_AVL_H