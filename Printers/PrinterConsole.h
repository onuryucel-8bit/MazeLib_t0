#include <iostream>
#include <vector> 

#include "../Algorithms/BaseAlgo.h"
#include "../Algorithms/MazeCell.h"

class PrinterConsole  
{  
public:  
	PrinterConsole(BaseAlgo& maze);
	~PrinterConsole();  

	void setCellTexture(char texture);
	void setWallTexture(char texture);
	void setMaze(BaseAlgo& maze);

	void createWindow();
	void draw();
private:  

	char m_cellTexture;
	char m_wallTexture;

	std::vector<char> m_window;

	BaseAlgo* m_maze;

	size_t m_width;
	size_t m_height;
};
