#include "qstate.h"

#include <cmath>
#include <cstdio>

QState::QState() {
}

QState::QState(size_t N) {
    n = N;

    std::vector<bool> row;
    row.resize(N);
    for (unsigned int col = 0; col < N; ++col) {
        row[col] = false;
    }

    for (unsigned int col = 0; col < n; ++col) {
        board.push_back(row);
    }
}

QState::QState(const QState &qs, size_t row) {
    this->n = qs.n;

    for (auto &row : qs.board) {
        board.push_back(row);
    } 

    unsigned int next_col = 0;
    while(column_has_queen(next_col)) {
        ++next_col;
    }    
    if (next_col < n) {
        this->board[next_col][row] = true;
    }
}

QState::QState(const QState &qs) {
    this->n = qs.n;

    for (auto &row : qs.board) {
        board.push_back(row);
    } 
}

QState::~QState() {
}

bool QState::valid_solution() const {
    return state_is_valid() and queens_on_board() == n;
}

bool QState::state_is_valid() const {
    bool is_valid = true;
    for (unsigned int col = 0; col < n; ++col) {
        if (queen_threats(col) > 0) {
            is_valid = false;
            break;
        }
    }
    return is_valid;
}

size_t QState::total_threats() const {
    size_t total = 0;
    for (unsigned int col = 0; col < n; ++col) {
        total += queen_threats(col);
    }   
    return total;
}

void QState::print_state() const {
    printf("\n");
    for (unsigned int row = 0; row < n; ++row) {
        for (unsigned int col = 0; col < n; ++col) {
            if (board[col][row]) {
                printf("[Q] ");
            }
            else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
    printf("\n");
    
}

size_t QState::queen_threats(size_t col) const {
    size_t threats = 0;
    if (column_has_queen(col) ) {
        threats += check_diagonals(col);
        threats += check_line(col);
    }
    return threats;
} 

size_t QState::check_diagonals(size_t col) const {
    size_t threats = 0;
    if (column_has_queen(col)) {
        size_t row = get_queen_row(col);
        for (unsigned int c = 0; c < n; ++c) {
            if (c not_eq col) {
                unsigned int diff = std::abs(
                        static_cast<int>(c) - static_cast<int>(col) );
                if ( col + diff < n and row + diff < n 
                    and board[col + diff][row + diff] )
                {
                    ++threats;
                }
                if ( col - diff < n and row - diff < n
                    and board[col - diff][row - diff] )
                {
                    ++threats;
                }
                if ( col - diff < n and row + diff < n 
                    and board[col - diff][row + diff] )
                {
                    ++threats;
                }
                if ( col + diff < n and row - diff < n
                    and board[col + diff][row - diff] )
                {
                    ++threats;
                }
            }
        }
    }
    return threats;
}

size_t QState::check_line(size_t col) const {
    size_t threats = 0;
    if (column_has_queen(col)) {
        size_t row = get_queen_row(col);
        for (unsigned int c = 0; c < n; ++c) {
            if (board[c][row] and c != col) {
                ++threats;
            }
        }
    }
    return threats;
}

bool QState::column_has_queen(size_t col) const {
    bool has_queen = false;
    for (unsigned int row = 0; row < n; ++row) {
        if (board[col][row]) {
            has_queen = true;
            break;
        }
    }
    return has_queen;
}

size_t QState::get_queen_row(size_t col) const {
    for (unsigned int row = 0; row < n; ++row) {
        if (board[col][row]) {
            return row;
        }
    }
    // Should never reach here (we check with has queen before)
    return (size_t)-1;
}

size_t QState::queens_on_board() const {
    size_t total = 0;
    for (unsigned int col = 0; col < n; ++col) {
        total += column_has_queen(col) ? 1 : 0;
    }
    return total;
}
