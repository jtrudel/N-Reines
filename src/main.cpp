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
    if (next == nullptr) {
        printf("WE HAVE A PROBLEM\n");
    }
    int i = 0;
    while(next not_eq nullptr) 
    {
        std::cout<<++i<<std::endl;
        explore(next, width);
        next = node->get_next_unvisited_child();
        next->get_data().print_state();
    }
}
    

