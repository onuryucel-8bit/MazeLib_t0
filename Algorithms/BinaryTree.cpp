#include "BinaryTree.h"

BinaryTree::BinaryTree(size_t width, size_t height) 
{
	m_width = width;
	m_height = height;
	m_maze.resize(width * height);

	m_dir = Direction::BottomRight;
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::run(int x, int y)
{
	
	for (size_t i = 0; i < m_maze.size(); i++)
	{
		m_maze[i] = MazeCell({ true, true, true, true });
	}

	std::srand(std::time(0));

	int row = 0;

	int rndDirection;
	for (size_t i = 0; i < m_height; i++)
	{		
		for (size_t j = 0; j < m_width; j++)
		{
			//TODO rnd function pointer call here
			rndDirection = rand() % 2;
			//j * mazeWidth + i

			//posx = i;
			//posy = j;

			switch (m_dir)
			{
			case Direction::TopLeft:
				//top corridor
				if (i == 0 && j + 1 != m_width)
				{
					m_maze[i * m_height + j].right = false;
					m_maze[i * m_height + j + 1].left = false;
				}
				//left corridor
				if (j == 0 && i + 1 != m_height)
				{
					m_maze[i * m_height + j].down = false;
					m_maze[(i + 1) * m_height + j].up = false;
				}

				if (i != 0 && j != 0)
				{
					//up
					if (rndDirection == 0)
					{
						m_maze[i * m_height + j].up = false;
						m_maze[(i - 1) * m_height + j].down = false;
					}
					//left
					else
					{
						m_maze[i * m_height + j].left = false;
						m_maze[i * m_height + j - 1].right = false;
					}
				}

				break;
			case Direction::TopRight:
				//top corridor
				if (i == 0 && j + 1 != m_width)
				{
					m_maze[i * m_height + j].right = false;
					m_maze[i * m_height + j + 1].left = false;
				}
				//right corridor
				if (j + 1 == m_width && i + 1 != m_height)
				{
					m_maze[i * m_height + j].down = false;
					m_maze[(i + 1) * m_height + j].up = false;
				}
				//corner
				if (i != 0 && j + 1 != m_width)
				{					
					//up
					if (rndDirection == 0)
					{
						m_maze[i * m_height + j].up = false;
						m_maze[(i - 1) * m_height + j].down = false;
					}
					//right
					else
					{
						m_maze[i * m_height + j].right = false;
						m_maze[i * m_height + j + 1].left = false;
					}
				}
				break;

			case Direction::BottomLeft:
				//bottom corridor
				if (i + 1 == m_height && j + 1 != m_width)
				{
					m_maze[i * m_height + j].right = false;
					m_maze[i * m_height + j + 1].left = false;
				}
				//left corridor
				if (j == 0 && i + 1 != m_height)
				{
					m_maze[i * m_height + j].down = false;
					m_maze[(i + 1) * m_height + j].up = false;
				}

				//corner
				if (i + 1 != m_height && j != 0)
				{
					//down
					if (rndDirection == 0)
					{
						m_maze[i * m_height + j].down = false;
						m_maze[(i + 1) * m_height + j].up = false;
					}
					//left
					else
					{
						m_maze[i * m_height + j].left = false;
						m_maze[i * m_height + j - 1].right = false;
					}
				}

				break;

			case Direction::BottomRight:
				//bottom corridor
				if (i + 1 == m_height && j + 1 != m_width)
				{
					m_maze[i * m_height + j].right = false;
					m_maze[i * m_height + j + 1].left = false;
				}
				//right corridor
				if (j + 1 == m_width && i + 1 != m_height)
				{
					m_maze[i * m_height + j].down = false;
					m_maze[(i + 1) * m_height + j].up = false;
				}

				//corner
				if (i != m_height - 1 && j != m_width - 1)
				{
					//down
					if (rndDirection == 0)
					{
						m_maze[i * m_height + j].down = false;
						m_maze[(i + 1) * m_height + j].up = false;						
					}
					//right
					else
					{
						m_maze[i * m_height + j].right = false;
						m_maze[i * m_height + j + 1].left = false;
					}
				}


				break;
			}
		}

		

		
	}	

	
}

void BinaryTree::setDirection(Direction dir)
{
	m_dir = dir;
}

