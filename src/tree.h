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
    void clear_children();
    
    void visit() { visited = true; }
    bool is_visited() const { return visited; }

    size_t child_number() const { return children.size(); }
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
TreeNode<T>::TreeNode(TNode *const parent_, T data_)
        : data(data_) {
    parent = parent_;
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
        if ( !child->is_visited() ) {
            next = child;
            break;
        }
    }
    return next;
}

template <typename T>
void TreeNode<T>::add_child(TNode *const child) {
    children.push_back(child);
}

template <typename T>
void TreeNode<T>::clear_children() {
    if (children.size() > 0) {
        for (auto &child : children) {
            delete child;
        }
    }
}
