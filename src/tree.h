#pragma once

#include <cstdio>
#include <vector>

template <typename T>
class TreeNode {
public:
    typedef TreeNode<T> TNode;
    TreeNode(TNode *const parent_, T data_);
    ~TreeNode() {};

    T get_data() const;

    TNode* get_parent() const;
    TNode* get_next_unvisited_child() const;
    
    void add_child(TNode *const child);
    
    void visit() { visited = true; }
    bool is_visited() const { return visited; }

private:
    TreeNode();
    TreeNode(const TNode &) {};
    TNode& operator=(const TNode &) {};

    bool visited;
    T data;
    TNode *parent;
    std::vector<TNode*> children; 
};

template <typename T>
TreeNode<T>::TreeNode(TNode *const parent_, T data_) {
    parent = parent_;
    data = data_;
    visited = false;
}

template <typename T>
T TreeNode<T>::get_data() const {
    return data;
}

template <typename T>
TreeNode<T>* TreeNode<T>::get_parent() const {
    return parent;
}

template <typename T>
TreeNode<T>* TreeNode<T>::get_next_unvisited_child() const {
    TNode* next = nullptr;
    for (auto &child: children) {
        printf("we are visiting a child\n");
        if ( !child->is_visited() ) {
            printf("we found one!!!!!!\n");
            next = child;
            break;
        }
    }
    next->get_data().print_state();
    return next;
}

template <typename T>
void TreeNode<T>::add_child(TNode *const child) {
    children.push_back(child);
}
