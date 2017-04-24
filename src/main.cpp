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
        for (size_t i = 0; i < width; ++i) {
            node->add_child(
                    new TreeNode<QState>(
                            node, 
                            QState(node->get_data(), i) ) );
        }
    }
    std::cout<<"first if done"<<std::endl;
    if ( not node->get_data().valid_solution() ) {
        for (auto next = node->get_next_unvisited_child(); next != nullptr; 
            next = node->get_next_unvisited_child() ) 
        {
            std::cout<<"recursive call here"<<std::endl;
            explore(next, width);
        }
    }
    else {
        node->get_data().print_state();
    }
}
    

