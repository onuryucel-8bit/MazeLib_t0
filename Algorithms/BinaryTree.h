#pragma once

#include <iostream>
#include <vector>

#include "BaseAlgo.h"
#include "MazeCell.h"

enum Direction
{
	TopLeft,
	TopRight,
	BottomLeft,
	BottomRight
};

class BinaryTree : public BaseAlgo
{
public:
	BinaryTree(size_t width, size_t height);	
	~BinaryTree();

	void setDirection(Direction dir);
	void run(int x, int y) override;

	size_t getWidth();
	size_t getHeight();

	std::vector<MazeCell> getMaze();
private:

	Direction m_dir;
	
};

