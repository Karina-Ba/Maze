//***********************************************************************************//
// Karina Batmanishvili - 321800898.                                                 //
// This project asks user if he wants to input maze or recieve a random maze,        //
// in size of his choosing, and solves the maze printing it to the screen.           //
//                                                                                   //
// First you choose: 1 meaning you input a maze, 2 meaning randomized maze will be   //
// created. Then you input the amount of rows you want, and after that the amount of //
// columns. After that a solved maze will be displayed by the sizes you asked.       //
//***********************************************************************************//
#include "Maze.h"

int main()
{
	int choice;
	int rows, cols;

	//User input for maze options
	cout << "Maze: 1) From input 2) Random" << endl;
	cin >> choice;

	cin >> rows;

	if (rows > Queue::MAX_ROW) //Input test
	{
		cout << "invalid input" << endl;
		exit(1);
	}

	cin >> cols;

	if (cols > Queue::MAX_COL) //Input test
	{
		cout << "invalid input" << endl;
		exit(1);
	}

	//Creating the maze
	Maze maze(rows, cols); 

	if (choice == 1) //User input maze
	{
		maze.setMaze();
	}

	else if (choice == 2 && (rows % 2 == 1) && (cols % 2 == 1)) //Randomly generated maze for odd numbers only
	{
		maze.createMaze();
	}

	else //Any other case
	{
		cout << "invalid input" << endl;
		exit(1);
	}

	maze.solveMaze(); //Solving maze

	return (1);
}