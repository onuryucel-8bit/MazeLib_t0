#pragma once  

#include <iostream>  

struct vec2ui
{
	size_t x = 0;
	size_t y = 0;
};

struct MazeCell  
{  
	bool up = false;  
	bool left = false;   
	bool down = false;  
	bool right = false;  

	friend std::ostream& operator<< (std::ostream& os, const MazeCell& cell)  
	{  
		os << std::boolalpha  
			<< "Cell data up:[" << cell.up  
			<< "] left:[" << cell.left  
			<< "] down:[" << cell.down  
			<< "] right:[" << cell.right  
			<< "]\n";  

		return os;  
	}  
};
/*
struct t1
{
	char cell; 0000_(0000)
}

*/