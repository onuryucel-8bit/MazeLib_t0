/*
x * w + y
index = indexX * arrayWidth + indexY;

y * h + x
index = indexY * arrayHeight + indexX;
*/

#include "Algorithms/BaseAlgo.h"
#include "Algorithms/BinaryTree.h"

#include "Printers/PrinterConsole.h"
#include "Printers/PrinterJACK.h"


//TODO remove run(x,y) => run() some algorithms dont need x,y coordinates

int main()
{
	BinaryTree binaryTree(5,5);	
	binaryTree.setDirection(Direction::BottomRight);
	binaryTree.run(0,0);

	
	PrinterJACK jack((BaseAlgo&)binaryTree);
	jack.createWindow();

	
	PrinterConsole console((BaseAlgo&)binaryTree);
	console.setCellTexture('.');
	console.setWallTexture('@');
	console.createWindow();
	console.draw();
}