#pragma once

#include <vector>

#include "BaseAlgo.h"
#include "MazeCell.h"

class RecursiveBacktracking : public BaseAlgo
{
public:
	RecursiveBacktracking(size_t width, size_t height);
	~RecursiveBacktracking();

	void run(int x, int y) override;

private:

	void recRun();
};

RecursiveBacktracking::RecursiveBacktracking(size_t width, size_t height)
{
	m_width = width;
	m_height = height;
	m_maze.resize(width * height);
}

RecursiveBacktracking::~RecursiveBacktracking()
{
}

void RecursiveBacktracking::run(int x, int y)
{
	recRun();
}

void RecursiveBacktracking::recRun()
{

}
