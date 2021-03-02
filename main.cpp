#include <iostream> 
#include "Board.h"
#include "Solver.h"

int main() 
{
    // Board board({ {14, 13, 5, 3},{0, 1, 8, 12},{6, 2, 4, 10},{11, 9, 15, 7} });
    // Board board({ {0,15,14,13},{12,11,10,9},{8,7,6,5},{4,3,2,1} }); // 78 moves!! too long
    // Board board({ {6,9,7,4},{2,5,10,8},{3,11,1,12},{13, 14, 15, 0} });
    // Board board({ {2,3,0,8},{15,12,6,7},{13,1,4,9},{14,11,10,5} }); // 50 moves
    Board board({ {5,6,3,4},{8,0,1,15},{10,7,2,11},{12,9,14,13} }); // 40 moves
    //Board board({ {3,1,2}, {0,4,5}, {7,8,6} });
    //Board board({ {0,4,1}, {5,3,2}, {7,8,6} }); // 10 moves - solved
    //Board board({ {3,4,6}, {2,0,8}, {1,7,5} }); // 14 moves - solved
    //Board board({ {4,3,1}, {0,2,6}, {7,8,5} }); // 17 moves - solved
    //Board board({ {7,0,4}, {8,5,1}, {6,3,2} }); // 19 moves - solved
    //Board board({ {6,0,8}, {4,3,5}, {1,2,7} }); // 23 moves - solved
    //Board board({ {8,3,5}, {6,4,2}, {1,0,7} }); // 25 moves - solved
    //Board board({ {6,3,8}, {5,4,1}, {7,2,0} }); // 28 moves - solved
    //Board board({ {8,6,7}, {2,0,4}, {3,5,1} }); // 30 moves - solved quickly with manhattan
    //Board board({ {0,1,3}, {4,2,5}, {7,8,6} });

	Solver solver(board);
    
    std::stack<Board> solution = solver.solution();
	while (!solution.empty())
	{
		solution.top().draw();
		std::cout << std::endl;
        solution.pop();
	}
    std::cout << "Solved in " << solver.moves() << " moves!\n";
    std::cin.get(); 
    return 0;
}