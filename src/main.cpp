#include "tree.h"
#include "qstate.h"

#include <iostream>
#include <cstdlib>

void explore(TreeNode<QState>*, size_t width);

int main(int argc, char** argv) {
    size_t N = argc > 1 ? atoi(argv[1]) : 8;
    TreeNode<QState>* solution = new TreeNode<QState>(nullptr, QState(N) );
    explore(solution, N);
}

void explore(TreeNode<QState>* node, size_t width) {
    node->visit();
    node->get_data().print_state();
    if (node->get_data().state_is_valid() ) {
        if (node->get_data().valid_solution() ) {
            node->get_data().print_state(); 
        }
        else {
            for (size_t i = 0; i < width; ++i) {
                node->add_child(
                        new TreeNode<QState>(
                                node, 
                                QState(node->get_data(), i) ) );
            }
        }
    }
    auto next = node->get_next_unvisited_child();
    while(next not_eq nullptr) 
    {
        std::cout<<"recursive call here"<<std::endl;
        explore(next, width);
        next = node->get_next_unvisited_child();
    }
}
    

