#include <iostream> 
#include "Board.h"
#include "Solver.h"

int main() 
{
    Board board({{1,2,3},{0,4,5},{7,8,6}});
    std::cout << "Hamming distance is: " << board.hamming() << std::endl;
    std::cout << "Manhattan distance is: " << board.manhattan() << std::endl;
   /* std::vector<Board> neighbours = board.neighbours();
    board.draw();
	std::cout << std::endl;
    for (auto brd : neighbours)
    {
        brd.draw();
        std::cout << std::endl;
    }
    */
    Solver solver(board);

    for (auto board : solver.solution())
    {
        board.draw();
        std::cout << std::endl;
    }
    std::cin.get(); 
    return 0;
}