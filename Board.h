#pragma once

#include <vector> 

class Board {
private:
    std::vector<std::vector<int>> m_board;
public:
    Board(std::vector<std::vector<int>> const& tiles);
    void draw();
    int dimension();
    int hamming();
    int manhattan();
    bool isGoal();
    friend bool operator==(Board const& board1, Board const& board2);
    std::vector<Board> neighbours();
    // Board twin(); // used for optimisation
private:
    std::pair<int, int> findSpace();
    void swap(std::vector<std::vector<int>> &board, int row1, int col1, int row2, int col2);
};