#include "BaseAlgo.h"

BaseAlgo::BaseAlgo()
{
	m_width = 0;
	m_height = 0;
}

BaseAlgo::~BaseAlgo()
{
}

std::vector<MazeCell> BaseAlgo::getMaze()
{
	return m_maze;
}

size_t BaseAlgo::getHeight()
{
	return m_height;
}

size_t BaseAlgo::getWidth()
{
	return m_width;
}