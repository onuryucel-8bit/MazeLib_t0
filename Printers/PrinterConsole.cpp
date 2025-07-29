#include "PrinterConsole.h"

PrinterConsole::PrinterConsole(BaseAlgo& maze)
{
	m_maze = &maze;

	m_height = 0;
	m_width = 0;

	m_cellTexture = '.';
	m_wallTexture = '#';
}

PrinterConsole::~PrinterConsole()
{
}

void PrinterConsole::createWindow()
{   
	if (m_maze->getMaze().empty())
	{		
		return;
	}
	/*
	2x2 => 5x5 
	3x3 => 7x7
	4x4 => 9x9

	nxm => (n + n + 1)x(m + m + 1)
		=> (2n + 1)x(2m + 1)

	10x10 => 21x21
	*/
	
	size_t mazeWidth = m_maze->getWidth();
	size_t mazeHeight = m_maze->getHeight();

	m_width = mazeWidth * 2 + 1;
	m_height = mazeHeight * 2 + 1;
	
	std::vector<MazeCell> maze = m_maze->getMaze();

	m_window.resize(m_width * m_height);

	//fill all with wall

	for (size_t i = 0; i < m_width * m_height; i++)
	{
		m_window[i] = m_wallTexture;
	}
			
	for (size_t i = 0; i < mazeHeight; i++)
	{
		for (size_t j = 0; j < mazeWidth; j++)
		{
			int posy = 2 * j + 1;
			int posx = 2 * i + 1;
						
			m_window[posy * m_width + posx] = m_cellTexture;
			
			if (maze[j * mazeWidth + i].up == false)
			{
				m_window[(posy - 1)* m_width + posx] = m_cellTexture;
			}

			if (maze[j * mazeWidth + i].right == false)
			{				
				m_window[posy * m_width + posx + 1] = m_cellTexture;
			}

			if (maze[j * mazeWidth + i].down == false)
			{				
				m_window[(posy + 1) * m_width + posx] = m_cellTexture;
			}
			
			if (maze[j * mazeWidth + i].left == false)
			{
				m_window[posy  * m_width + posx - 1] = m_cellTexture;
			}
		}
	}
}

void PrinterConsole::draw()
{
	if (m_window.empty())
	{		
		return;
	}

	for (size_t i = 0; i < m_window.size(); i++)
	{
		std::cout << m_window[i];

		if ((i + 1) % m_width == 0)
		{
			std::cout << "\n";
		}
	}
}


void PrinterConsole::setCellTexture(char texture)
{
	m_cellTexture = texture;
}

void PrinterConsole::setWallTexture(char texture)
{
	m_wallTexture = texture;
}

void PrinterConsole::setMaze(BaseAlgo& maze)
{
	m_maze = &maze;
}
