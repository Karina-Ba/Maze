#include "Maze.h"

//-------------------------------------------------------------------------------//
Maze::Maze(const int rows, const int cols) : m_rows(rows), m_cols(cols)
{
	this->m_maze = new char*[rows]; //Memory allocation for rows

	for (int i = 0; i < rows; ++i) //MEmory allocation for columns
	{
		this->m_maze[i] = new char[cols + 1]; //Allocating +1 for \0
	}
}
//-------------------------------------------------------------------------------//
Maze::~Maze()
{
	for (int i = 0; i < this->m_rows; ++i)
	{
		delete this->m_maze[i];
	}

	delete[] this->m_maze;
}
//-------------------------------------------------------------------------------//
void Maze::setMaze()
{
	cin.ignore(); //Ignoring \n from before

	char* input = new char[this->m_cols + 1]; //Creating string to read input

	 //User input maze
	for (int i = 0; i < this->m_rows; ++i) //Loop for rows
	{
		cin.getline(input, this->m_cols + 1); //Reading string from user

		if (strlen(input) != this->m_cols) //If string length is not the same as column amount, input is invalid
		{
			cout << "invalid input" << endl;
			exit(1);
		}

		for (int j = 0; j < this->m_cols; ++j) //Loop for columns
		{
			///I am aware I could have used less conditions but I chose to use these as they are more readable

			if ((i == 0 || i == this->m_rows - 1) && (input[j] != '*')) //If first or last row are not walls, input is invalid
			{
				cout << "invalid input" << endl;
				exit(1);
			}

			else if (((j == 0 && i != 1) || (j == this->m_cols - 1 && i != this->m_rows - 2)) && (input[j] != '*')) //If first or last column are not walls, input is invalid
			{
				cout << "invalid input" << endl;
				exit(1);
			}

			else if ((i == 1 && j == 0) && (input[j] != ' ')) //If start point is not empty space'input is invalid
			{
				cout << "invalid input" << endl;
				exit(1);
			}

			else if ((i == this->m_rows - 2 && j == this->m_cols - 1) && (input[j] != ' ')) //If end point is not empty space'input is invalid
			{
				cout << "invalid input" << endl;
				exit(1);
			}

			else if (input[j] != '*' && input[j] != ' ') //If input is anything but walls or empty spaces, input is invalid
			{
				cout << "invalid input" << endl;
				exit(1);
			}

			else //In any other case, input into maze
			{
				this->m_maze[i][j] = input[j];
			}
		}
		this->m_maze[i][this->m_cols] = '\0'; //Input at the end of the string
	}
}
//-------------------------------------------------------------------------------//
void Maze::createMaze()
{ ///Note: Since there was no answer in the forum for the option of a maze 11x11 and greater that is completely empty inside (with walls) filling the entire queue,
	///I did not give a solution for it, but the algorithm would have to check for every neighbor if it already exists in the queue or to enlarge the array.
	srand((unsigned)time(NULL)); //Rand setting

	//Creating a maze filled with walls, an entrance and an exit
	for (int i = 0; i < this->m_rows; ++i) 
	{
		for (int j = 0; j < this->m_cols; ++j)
		{
			if ((i == 1 && j == 0) || ((i == this->m_rows - 2) && (j == this->m_cols - 1)) ) //For exit and start, input free space
			{
				this->m_maze[i][j] = ' ';
			}

			else
			{
				this->m_maze[i][j] = '*';
			}
		}
		this->m_maze[i][this->m_cols] = '\0';
	}

	Stack stack(Point(' ', 1, 1)); //Resetting stack to be in (1,1)

	while (!stack.IsEmpty()) //Loop while stack is not empty
	{
		Point currPoint = stack.Pop(); //Take the top point out

		this->m_maze[currPoint.getHeight()][currPoint.getWidth()] = ' '; //Mark as visited point

		Point* possibleMoves = new Point[3]; //Maximum 3 possible moves (excluding the direction we came from)
		int logSize = 0; //Logical size of the array

		if (rightNeighbor(currPoint)) //If right neighbor exists
		{
			Point right(' ', currPoint.getHeight(), currPoint.getWidth() + 2); //Create that point 2 to the right
			possibleMoves[logSize] = right; //Input the point into the array
			logSize++; //Add one to logical size of array
		}

		if (bottomNeighbor(currPoint)) //If bottom neighbor exists
		{
			Point bottom(' ', currPoint.getHeight() + 2, currPoint.getWidth()); //Create that point 2 down
			possibleMoves[logSize] = bottom; //Input the point into the array
			logSize++; //Add one to logical size of array
		}

		if (leftNeighbor(currPoint)) //If left neighbor exists
		{
			Point left(' ', currPoint.getHeight(), currPoint.getWidth() - 2); //Create that point 2 to the left
			possibleMoves[logSize] = left; //Input the point into the array
			logSize++; //Add one to logical size of array
		}

		if (topNeighbor(currPoint)) //If top neighbor exists
		{
			Point top(' ', currPoint.getHeight() - 2, currPoint.getWidth()); //Create that point 2 up
			possibleMoves[logSize] = top; //Input the point into the array
			logSize++; //Add one to logical size of array
		}

		if (logSize > 0) //Only if there's possible neighbors in the array
		{
			eDirection direction = eDirection(rand() % logSize); //Choose neighbor randomly 

			breakTheWall(currPoint, possibleMoves[direction]); //Break the wall between the neighbors

			stack.Push(currPoint); //Input the current point back into the stack
			stack.Push(possibleMoves[direction]); //Input the neighbor into the stack
		}
		delete[] possibleMoves; //Delete array we allocated
	}
}
//-------------------------------------------------------------------------------//
void Maze::solveMaze()
{
	Point startPoint (' ', 1, 0); //Setting start point
	Point currPlc = startPoint;  //Setting current place in maze
	Queue queue(startPoint, this->m_cols * this->m_rows); //Creating queue
	bool  END = false; //Boolean variable to find end

	while (!queue.IsEmpty() && !END) //While the queue is not empty and we haven't reached the end
	{
		currPlc = queue.DeQueue(); //Take out what's in the queue

		if (currPlc.getItem() == ' ') //If it's an empty space we can use it
		{
			this->m_maze[currPlc.getHeight()][currPlc.getWidth()] = '$'; //Input the sign into that place, meaning we visited this spot

			//Setting variables for easier use height and width
			int currH = currPlc.getHeight();
			int currW = currPlc.getWidth();

			if ((currH == this->m_rows - 2) && (currW == this->m_cols - 1)) //If we reached the exit make end true
			{
				END = true;
			}

			else //We haven't reached the end of the maze
			{
				Point temp; //Creating point for easier use

				if (currW + 1 < this->m_cols) //From current place, making sure right exists
				{
					temp.setHeight(currH);
					temp.setWidth(currW + 1);
					temp.setItem(this->m_maze[currH][currW + 1]);

					if (temp.getItem() == ' ') //If possible move 
					{
						queue.EnQueue(temp); //Input point into queue
					}
				}

				if (currH + 1 < this->m_rows) //From current place, making sure bottom exists
				{
					//Setting info into point
					temp.setHeight(currH + 1);
					temp.setWidth(currW);
					temp.setItem(this->m_maze[currH + 1][currW]);

					if (temp.getItem() == ' ') //If possible move 
					{
						queue.EnQueue(temp); //Input point into queue
					}
				}

				if (currW - 1 > 0) //From current place, making sure left exists
				{
					//Setting info into point
					temp.setHeight(currH);
					temp.setWidth(currW - 1);
					temp.setItem(this->m_maze[currH][currW - 1]);

					if (temp.getItem() == ' ') //If possible move 
					{
						queue.EnQueue(temp); //Input point into queue
					}
				}

				if (currH - 1 > 0) //From current place, making sure top exists
				{
					//Setting info into point
					temp.setHeight(currH - 1);
					temp.setWidth(currW);
					temp.setItem(this->m_maze[currH - 1][currW]);

					if (temp.getItem() == ' ') //If possible move 
					{
						queue.EnQueue(temp); //Input point into queue
					}
				}
			}
		}
	}

	if (!queue.IsEmpty()) //If queue is not empty
	{
		queue.MakeEmpty();
	}

	if (this->m_maze[this->m_rows - 2][this->m_cols - 1] != '$') //If we haven't visited the end then there's no solution
	{
		cout << "no solution" << endl;
		exit(1);
	}

	else
	{
		this->printMaze(); //Printing maze
	}

}
//-------------------------------------------------------------------------------//
void Maze::printMaze() const
{
	for (int i = 0; i < this->m_rows; ++i)
	{
		cout << this->m_maze[i] << endl;
	}
}
//-------------------------------------------------------------------------------//
bool Maze::rightNeighbor(Point& point) const
{
	if (point.getWidth() + 2 < this->m_cols && this->m_maze[point.getHeight()][point.getWidth() + 2] == '*') //right
		return true;

	return false;
}
//-------------------------------------------------------------------------------//
bool Maze::bottomNeighbor(Point& point) const
{
	if (point.getHeight() + 2 < this->m_rows && this->m_maze[point.getHeight() + 2][point.getWidth()] == '*') //bottom
		return true;
	
	return false;
}
//-------------------------------------------------------------------------------//
bool Maze::leftNeighbor(Point& point) const
{
	if (point.getWidth() - 2 > 0 && this->m_maze[point.getHeight()][point.getWidth() - 2] == '*') //left
		return true;

	return false;
}
//-------------------------------------------------------------------------------//
bool Maze::topNeighbor(Point& point) const
{
	if (point.getHeight() - 2 > 0 && this->m_maze[point.getHeight() - 2][point.getWidth()] == '*') //top
		return true;

	return false;
}
//-------------------------------------------------------------------------------//
void Maze::breakTheWall(const Point& start, const Point& end)
{
	if (start.getHeight() > end.getHeight()) //If start height bigger than end
	{
		this->m_maze[end.getHeight() + 1][end.getWidth()] = ' '; //Break the wall one forward from start
	}

	else if (start.getHeight() < end.getHeight()) //If start height smaller than end height
	{
		this->m_maze[end.getHeight() - 1][end.getWidth()] = ' '; //Break the wall one back from start
	}
	
	else if (start.getWidth() > end.getWidth()) //If start width bigger than end width
	{
		this->m_maze[end.getHeight()][end.getWidth() + 1] = ' '; //Break the wall one up from start
	}

	else //If start width smaller than end width
	{
		this->m_maze[end.getHeight()][end.getWidth() - 1] = ' '; //Break the wall one down from start
	}
	///Either height or width will be the same meaning no double conditions exist
}
//-------------------------------------------------------------------------------//
