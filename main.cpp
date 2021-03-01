#include <iostream> 
#include "Board.h"

int main() 
{
    Board board({{1,2,3},{4,5,0},{7,8,6}});
    std::cout << "Hamming distance is: " << board.hamming() << std::endl;
    std::cout << "Manhattan distance is: " << board.manhattan() << std::endl;
    std::cin.get(); 
    return 0;
}