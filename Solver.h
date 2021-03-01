#pragma once
#include "Board.h"
#include <queue>
#include <memory>

class Solver {
private:
	class Node {
	public:
		std::shared_ptr<Node> prevNode;
		int moves;
		Board board;
		Node(Board const& board, int moves, std::shared_ptr<Node> prevNode);
		friend bool operator< (Node const& a, Node const& b);
	};
	std::vector<Board> m_solution;
	std::priority_queue<Node> m_PQ;
	int m_moves;
public:
	Solver(Board const& board);
	bool isSolvable();
	int moves();
	std::vector<Board> solution();
	friend bool operator< (Node const& a, Node const& b);
};
