#pragma once
#include "Board.h"
#include <queue>
#include <memory>
#include <stack>

class Solver {
private:
	class Node {
		int m_distance;
	public:
		std::shared_ptr<Node> prevNode;
		int moves = 0;
		Board board;
		Node(Board const& brd, std::shared_ptr<Node> lastNode);
		friend bool operator< (Node const& a, Node const& b);
		int getDistance() const;
	};
	//std::stack<Board> m_solution;
	std::priority_queue<Node> m_PQ;
	int m_moves = 0;
	std::shared_ptr<Node> lastNode;
public:
	Solver(Board const& board);
	bool isSolvable();
	int moves();
	std::stack<Board> solution();
	friend bool operator< (Node const& a, Node const& b);
};
