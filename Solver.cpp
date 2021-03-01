#include "Solver.h"
// TODO: critial optimisation, caching the hamming and manhattan priorities, detecting unsolvable boards

Solver::Solver(Board const& board)
{
	// find solution
	Node initBoard(board, 0, nullptr);
	m_PQ.push(initBoard);
	//m_solution.push_back(board);
	m_moves = 0;
	while (!m_PQ.top().board.isGoal())
	{
		std::shared_ptr<Node> prevNode = std::make_shared<Node>(m_PQ.top());
		std::vector<Board> neighbours = m_PQ.top().board.neighbours();
		m_solution.push_back(m_PQ.top().board);
		m_PQ.pop();
		++m_moves;
		for (auto neighbour : neighbours)
		{
			Node node(neighbour, m_moves, prevNode);
			m_PQ.push(node);
		}
	}
	m_solution.push_back(m_PQ.top().board);
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

std::vector<Board> Solver::solution()
{
	return m_solution;
}

Solver::Node::Node(Board const& board, int moves, std::shared_ptr<Node> prevNode) : board(board), moves(moves), prevNode(prevNode)
{
}

bool operator<(Solver::Node const& a, Solver::Node const& b)
{
	// reversed the operator for the priority queue to be a min PQ
	return a.board.hamming() + a.moves > b.board.hamming() + b.moves;
}