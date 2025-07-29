#pragma once

#include <vector>

#include "MazeCell.h"

class BaseAlgo
{
public:
	BaseAlgo();
	~BaseAlgo();

	virtual void run(int x, int y) = 0;

	size_t getWidth();
	size_t getHeight();
	std::vector<MazeCell> getMaze();

protected:

	size_t m_width;
	size_t m_height;
	std::vector<MazeCell> m_maze;
};

