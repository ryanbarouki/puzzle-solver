#include "Board.h"
#include <cmath>
#include <iostream>

Board::Board(std::vector<std::vector<int>> const& tiles) : m_board(tiles)
{
}

void Board::draw() 
{
    for (auto row : m_board)
    {
        for (auto tile : row)
        {
            std::cout << tile << "  ";
        }
        std::cout << "\n";
    }
}

int Board::dimension() 
{
    return m_board.size();
}

// number of tiles out of place
int Board::hamming() 
{
    int res = 0;
    int n = m_board.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) 
        {
            if (m_board[i][j] == 0) continue;

            if (m_board[i][j] != n*i + j + 1)
            {
                ++res;
            }
        }
    }
    return res;
}

// sum of Manhattan distances between tiles and goal i.e. taxi-cab metric
int Board::manhattan() 
{
    int n = m_board.size();
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) 
        {
            // given a value p its position should be ((p-1)/n, (p - 1)%n) 
            int val = m_board[i][j];
            if (val == 0) continue; // ignore the missing tile with value 0

            int row = (val - 1)/n; // integer division
            int col = (val - 1) % n;
            res += abs(row - i) + abs(col - j);
        }
    }
    return res;
}

bool Board::isGoal() 
{
    return hamming() == 0;
}

bool operator==(Board const& board1, Board const& board2) 
{
    return board1.m_board == board2.m_board;
}

std::vector<Board> Board::neighbours() 
{
    std::pair<int, int> space = findSpace();
    int row = space.first;
    int col = space.second;
    std::vector<Board> neighbours;  
    int n = m_board.size();

    if (row < n - 1)
    {
        std::vector<std::vector<int>> new_board(m_board);   
        swap(new_board, row, col, row + 1, col);
        neighbours.push_back(Board(new_board));
    }
    if (row > 0)
    {
        std::vector<std::vector<int>> new_board(m_board);   
        swap(new_board, row, col, row - 1, col);
        neighbours.push_back(Board(new_board));
    }
    if (col < n - 1)
    {
        std::vector<std::vector<int>> new_board(m_board);   
        swap(new_board, row, col, row, col + 1);
        neighbours.push_back(Board(new_board));
    }
    if (col > 0) 
    {
        std::vector<std::vector<int>> new_board(m_board);   
        swap(new_board, row, col, row, col - 1);
        neighbours.push_back(Board(new_board));
    }
    return neighbours;
}

std::pair<int, int> Board::findSpace()
{
    int n = m_board.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; i < n; ++j)
        {
            if (m_board[i][j] == 0)
            {
                return std::pair<int, int>{i,j};
            }
        }
    }
}

void Board::swap(std::vector<std::vector<int>> &board, int row1, int col1, int row2, int col2)
{
    int temp = board[row1][col1];
    board[row1][col1] = board[row2][col2];
    board[row2][col2] = temp;
}