//***********************************************************************************//
// Karina Batmanishvili - 321800898.                                                 //
// This class is made for the maze and it's functions such as creating and solving   //
//***********************************************************************************//

#ifndef __MAZE_
#define __MAZE_

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"
#include "Stack.h"
using namespace std;

#pragma warning(disable: 4996)

class Maze
{
public:
	enum eDirection { Right = 0, Bottom, Left, Top }; //Enum for easier readability

	 //C'tor
	 Maze(const int rows = Queue::MAX_ROW, const int cols = Queue::MAX_COL);
	 //D'tor
	~Maze();

	//Maze functions
	void setMaze    (); //Function recieves maze from user
	void createMaze (); //Function creates random maze with sizes from user
	void solveMaze  (); //Function solves maze
	void printMaze  () const; //Function prints maze

private:
	const int m_rows;  //Row amount in maze
	const int m_cols;  //Column amount in maze
	char**    m_maze;  //Maze as a matrix

	//Neighbor functions return if such neighbor exists
	bool rightNeighbor(Point& point) const;
	bool bottomNeighbor(Point& point) const;
	bool leftNeighbor(Point& point) const;
	bool topNeighbor(Point& point) const;

	//Function to break a wall between two neighbors
	void breakTheWall(const Point& start, const Point& end);
};

#endif //__MAZE_
