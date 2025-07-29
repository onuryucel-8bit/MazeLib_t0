/*		
	 a7.------------a6.
	  /			   / |
	 /			  /  |
  a4.---------a5./   |
	|			|    |
	|a3.		|    . a2
	|			|    /
	|			|   /
	|			|  /
	|			| /
	.-----------./
   a0           a1


   height
   ^
   |
   |  / length
   | /
   |/
   .----------->width


			Z
			|
			|	
		    |
   X<-------*
			 \
			  \
			   \
			    Y
*/

#include <fstream>
#include <string>
#include <vector>

#include "../Algorithms/BaseAlgo.h"

struct Vector3i
{
	int x = 0;
	int y = 0;
	int z = 0;
};

struct Wall
{
	Vector3i vertex[8];
};

class PrinterJACK
{
public:
	PrinterJACK(BaseAlgo& maze);
	~PrinterJACK();

	void createWindow();
	void setMaze(BaseAlgo& maze);
private:

	void createWall(int x, int y, int z, int width, int height, int length);
	void createMapFile();
	void writeFile(std::ofstream& file, Vector3i a, Vector3i b, Vector3i c, std::string textureCoords);

	std::vector<Wall> wallList;

	BaseAlgo* m_maze;
};

PrinterJACK::PrinterJACK(BaseAlgo& maze)
{
	m_maze = &maze;
}

PrinterJACK::~PrinterJACK()
{
}

void PrinterJACK::createWall(int x, int y, int z, int width, int height, int length)
{
	Wall wall;

	wall.vertex[0].x = x;
	wall.vertex[0].y = y;
	wall.vertex[0].z = z;

	wall.vertex[1].x = x - width;
	wall.vertex[1].y = y;
	wall.vertex[1].z = z;

	wall.vertex[2].x = x - width;
	wall.vertex[2].y = y - length;
	wall.vertex[2].z = z;

	wall.vertex[3].x = x;
	wall.vertex[3].y = y - length;
	wall.vertex[3].z = z;

	//-----------------------------------//

	wall.vertex[4].x = x;
	wall.vertex[4].y = y;
	wall.vertex[4].z = z + height;

	wall.vertex[5].x = x - width;
	wall.vertex[5].y = y;
	wall.vertex[5].z = z + height;

	wall.vertex[6].x = x - width;
	wall.vertex[6].y = y - length;

	wall.vertex[6].z = z + height;

	wall.vertex[7].x = x;
	wall.vertex[7].y = y - length;
	wall.vertex[7].z = z + height;


	wallList.push_back(wall);
}

void PrinterJACK::createMapFile()
{
	//C:\\Program Files (x86)\\Steam\\steamapps\\common\\Half-Life\\valve\\maps\\testMapMaker.map
	std::ofstream file("testMap.map");

	//A = 625
	//b = 407
	//c = 514
	//D = 736
	//E = 764
	//F = 120

	file << R"({
"classname" "worldspawn"
"defaultteam" "0"
"newunit" "0"
"gametitle" "0"
"startdark" "0"
"MaxRange" "4096"
"sounds" "1"
"mapversion" "220"
"wad" "/Program Files (x86)/Steam/steamapps/common/Half-Life/valve/halflife.wad;/Program Files (x86)/Steam/steamapps/common/Half-Life/valve/xeno.wad;/Program Files (x86)/Steam/steamapps/common/Half-Life/valve/liquids.wad;/Program Files (x86)/Steam/steamapps/common/Half-Life/valve/decals.wad;/hl1tools/sdhlt.wad;/Program Files (x86)/Steam/steamapps/common/Half-Life/valve/devtextures.wad"
"_generator" "J.A.C.K. 1.1.3773 (vpHalfLife)\" )"
"\n";


	for (size_t i = 0; i < wallList.size(); i++)
	{
		file << "{\n";

		writeFile(file, wallList[i].vertex[6], wallList[i].vertex[2], wallList[i].vertex[5], "[ 0 1 0 0 ] [ 0 0 -1 0 ] 0 1 1");
		writeFile(file, wallList[i].vertex[4], wallList[i].vertex[0], wallList[i].vertex[7], "[ 0 1 0 0 ] [ 0 0 -1 0 ] 0 1 1");
		writeFile(file, wallList[i].vertex[5], wallList[i].vertex[1], wallList[i].vertex[4], "[ 1 0 0 0 ] [ 0 0 -1 0 ] 0 1 1");

		writeFile(file, wallList[i].vertex[7], wallList[i].vertex[3], wallList[i].vertex[6], "[ 1 0 0 0 ] [ 0 0 -1 0 ] 0 1 1");
		writeFile(file, wallList[i].vertex[7], wallList[i].vertex[6], wallList[i].vertex[4], "[ 1 0 0 0 ] [ 0 -1 0 0 ] 0 1 1");
		writeFile(file, wallList[i].vertex[1], wallList[i].vertex[2], wallList[i].vertex[0], "[ 1 0 0 0 ] [ 0 -1 0 0 ] 0 1 1");

		file << "}";
	}


	file << "}";

	file.close();
}

//TODO macro | lambda ?
void PrinterJACK::writeFile(std::ofstream& file, Vector3i a, Vector3i b, Vector3i c, std::string textureCoords)
{
	file << "( " << a.x << " " << a.y << " " << a.z << " ) "
		<< "( " << b.x << " " << b.y << " " << b.z << " ) "
		<< "( " << c.x << " " << c.y << " " << c.z << " ) OUT_CON " << textureCoords << "\n";
}

void PrinterJACK::createWindow()
{
	// x + w * i
	// y + h * j

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

	//TODO remove size_t TEST
	size_t m_width = mazeWidth * 2 + 1;
	size_t m_height = mazeHeight * 2 + 1;

	std::vector<MazeCell> maze = m_maze->getMaze();

	//TODO remove m_window,m_cellTexture TEST
	std::vector<char> m_window;
	char m_cellTexture = '.';

	m_window.resize(m_width * m_height);

	//fill all with wall

	for (size_t i = 0; i < m_width * m_height; i++)
	{
		m_window[i] = '#';
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
				m_window[(posy - 1) * m_width + posx] = m_cellTexture;
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
				m_window[posy * m_width + posx - 1] = m_cellTexture;
			}

		}
	}

	//--------------------------------------------------------------------//

	int height = 32;
	int length = 128;
	int width = 128;

	int x = 0;
	int y = 0;
	int z = 0;

	int row = 0;

	for (size_t i = 0; i < m_height; i++)
	{
		for (size_t j = 0; j < m_width; j++)
		{
			if (m_window[j * m_width + i] != '.')
			{
				createWall(x, y, z, width, height, length);
			}

			x += width;

		}
		x = 0;
		y += length;
	}

	createMapFile();
}

void PrinterJACK::setMaze(BaseAlgo& maze)
{
	m_maze = &maze;
}