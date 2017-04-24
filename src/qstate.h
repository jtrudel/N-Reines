#pragma once

#include <cstdio>
#include <vector>

class QState {
public:
    QState();
    QState(size_t N);
    QState(const QState &qs, size_t row);
    ~QState();

    bool valid_solution() const;
    bool state_is_valid() const;
    size_t total_threats() const;
    
    void print_state() const;

private:
    size_t n;
    std::vector<std::vector<bool> > board;

    size_t queen_threats(size_t col) const;
    size_t check_diagonals(size_t col) const;
    size_t check_line(size_t col) const;

    bool column_has_queen(size_t col) const;
    size_t get_queen_row(size_t col) const;
    size_t queens_on_board() const;
};

