#include "Solver.h"
#include <iostream>
// TODO: memory optimisation, detecting unsolvable boards

Solver::Solver(Board const& board)
{
	m_PQ.push(Node(board, nullptr));
	while (!m_PQ.top().board.isGoal())
	{
		lastNode = std::make_shared<Node>(m_PQ.top());
		std::vector<Board> neighbours = m_PQ.top().board.neighbours();

		m_PQ.pop();
		for (auto neighbour : neighbours)
		{
			// critical optimisation
			if (lastNode->prevNode != nullptr && lastNode->prevNode->board == neighbour)
			{
				continue;
			}
			m_PQ.push(Node(neighbour, lastNode));
		}
	}
	lastNode = std::make_shared<Node>(m_PQ.top());
}

bool Solver::isSolvable()
{
	// not implemented
	return false;
}

int Solver::moves()
{
	return m_moves;
}

std::stack<Board> Solver::solution()
{
	std::stack<Board> result;
	while (lastNode->prevNode)
	{
		result.push(lastNode->board);
		lastNode = lastNode->prevNode;
		m_moves++;
	}
	result.push(lastNode->board); // push starting board

	return result;
}

Solver::Node::Node(Board const& brd, std::shared_ptr<Node> lastNode) : board(brd), prevNode(lastNode)
{
	if (prevNode)
	{
		moves = prevNode->moves + 1;
	}
	m_distance = board.manhattan() + moves;
}

bool operator<(Solver::Node const& a, Solver::Node const& b)
{
	// reversed the operator for the priority queue to be a min PQ
	return a.getDistance() > b.getDistance();
	//return a.board.hamming() + a.moves > b.board.hamming() + b.moves;
}

int Solver::Node::getDistance() const
{
	return m_distance;
}