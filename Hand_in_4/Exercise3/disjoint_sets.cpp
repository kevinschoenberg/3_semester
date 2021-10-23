#include "disjoint_sets.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjSets::DisjSets(int numElements) : s(numElements, -1) {}

/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */
void DisjSets::unionSets(int root1, int root2)
{
	s[root2] = root1;
}

/**
 * Perform a find.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find(int x) const
{
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}

/**
 * Perform a find, same as above..
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find(int x)
{
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}

/**
 * Performs a no recursive find with buildin
 * path compression.
 **/
int DisjSets::new_find(int x)
{
	int root = x;

	if(s[x] < 0)
	{
		return s[x]; //O(1)
	}

	while(s[root] >= 0)
	{
		root = s[root]; //O(n)
	}
	int prev;
	int step = x;

	//Path compresion part.
	while(s[step] >= 0)
	{
		prev = step;
		step = s[step]; //O(n)
		unionSets(root,prev);
	}

	return root;
}

/*
Prints a given disjointed set.
*/
void DisjSets::print_s(int numElements)
{
	for (int i = 0; i < numElements; i++)
    {
        cout << s[i] << " ";
    }
	cout << endl;
}

/**
 * Locates all the sets with the same root as the given x.
 * And prints them all.
 * */
void DisjSets::printx(int x, size_t numElements)
{
	//Sets target root
	int target = find(x);
	cout << "printing all elements with the root: " << target << endl;
	//Locates all with same root.
	for (size_t i = 0; i < numElements; i++)
	{
		if (find(i)==target)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

// Exercise 3.a
Maze::Maze() : s(1, -1) {}
//Constructer
Maze::Maze(int rows, int cols) : s(rows * cols, -1)
{
	generate(rows, cols);
}

//Recursive find function
int Maze::find(int x)
{
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}
 //UNion function.
void Maze::unionSets(int root1, int root2)
{
	s[root2] = root1;
}

//Print maze function.
void Maze::print_maze(int rows, int cols)
{
	// encode the maze from a disjoint set to a matrix with walls.
	int en_rows = rows * 2 + 1;
	int en_cols = cols * 2 + 1;
	int en[en_cols * en_rows];

	// THe following assgined numbers are showed in the decode part.
	for (int i = 0; i < en_cols * en_rows; i++)
	{
		en[i] = 0;
	}

	for (int i = 0; i < en_rows; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 0; j < en_cols; j += 2)
			{
				en[j + i * en_cols] = 2;
			}
		}
		else
		{
			for (int j = 0; j < en_cols; j++)
			{
				en[j + i * en_cols] = 2;
			}
		}
	}

	// Construct all the edges
	for (int i = 2; i < en_cols - 1; i++)
	{
		en[i] = 1;
		en[(en_rows - 1) * en_cols + i - 1] = 1;
	}

	for (int i = 2; i < en_rows - 1; i++)
	{
		en[i * en_cols] = 1;
		en[(i * en_cols) - 1] = 1;
	}

	// Relation between disjoint set index and the encoded matrix.
	// int c = i % cols;
	// int r = floor(i / cols);
	// s[r * cols + c] = en[1 + 2c + 2r * cols + cols]

	for (int i = 0; i < rows * cols; i++)
	{
		int c = i % cols;
		int r = floor(i / cols);
		en[1 + 2 * c + (2 * r) * en_cols + en_cols] = 0;
	}

	int edge_row = rows - 1;
	int edge_col = cols - 1;

	// Walls within the maze.
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			int c = j;
			int r = i;
			if (s[r * cols + c] == r * cols + c + 1 || s[r * cols + c + 1] == r * cols + c)
			{
				en[1 + 2 * c + (2 * r) * en_cols + en_cols + 1] = 3;
			}
			else
			{
				en[1 + 2 * c + (2 * r) * en_cols + en_cols + 1] = 1;
			}
		}
	}

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows - 1; j++)
		{
			int c = i;
			int r = j;
			if (s[r * cols + c] == (r + 1) * cols + c || s[(r + 1) * cols + c] == r * cols + c)
			{
				en[1 + 2 * c + ((2 * r) + 1) * en_cols + en_cols] = 3;
			}
			else
			{
				en[1 + 2 * c + ((2 * r) + 1) * en_cols + en_cols] = 1;
			}
		}
	}

	// decode and print the maze.
	for (int i = 0; i < en_rows * en_cols; i++)
	{
		int c = i % en_cols;
		int r = floor(i / en_cols);

		if (en[i] == 1)
		{
			if (r % 2 == 0 && c != 0 && c != en_cols - 1)
			{
				cout << "--";
			}
			else
			{
				cout << "| ";
			}
		}
		else if (en[i] == 2)
			cout << ". ";
		else
		{
			cout << "  ";
		}

		if (c == en_cols - 1)
		{
			cout << endl;
		}
	}
	cout << endl;
}


void Maze::print_s2(int rows, int cols)
{
	for (int i = 0; i < rows * cols; i++)
	{
		int c = i % cols;
		int r = floor(i / cols);
		cout << s[i] << " ";
		if (c == cols - 1)
		{
			cout << endl;
		}
	}
	cout << endl;
}

/**
 * Locates all the sets with the same root as the given x.
 * And prints them all.
 * */
void Maze::printx(int x, size_t numElements)
{
	int target = find(x);
	cout << "printing all elements with the root: " << target << endl;
	for (size_t i = 0; i < numElements; i++)
	{
		if (find(i) == target)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}


int Maze::getlen(int x, size_t numElements)
{
	int target = find(x);
	int len = 0;
	for (size_t i = 0; i < numElements; i++)
	{
		if (find(i) == target)
		{
			len++;
		}
	}
	return len;
}

//Maze generation 
void Maze::generate(int rows, int cols)
{
	//Remove walls by using union on two fields next to each other.
	srand(time(0));

	int dir, c, r, root, succes;

	int start = 0;
	int end = (rows - 1) * (cols - 1);
	int cells = rows * cols;
	int cell;

	while (getlen(end, cells) != cells)
	{
		cell = rand() % cells;
		//If the result is "0". Then dont do anything.
		root = find(cell);

		//Check if c or r is 0. r== rwos or c==cols.

		// If the direction we move have the same root, then break;
		// A way to use an array as a matrix.
		// r is the row one want to walk down
		// c is the collum one want to walk down
		// s[r * cols + c];

		c = cell % cols;
		r = floor(cell / cols);

		int arr[] = {1, 1, 1, 1};
		int succes = 0;

		while (arr[0] + arr[1] + arr[2] + arr[3] != 0 && succes != 1)
		{
			dir = rand() % 4;
			arr[dir] = 0;

			switch (dir)
			{
			case 0:
				// right
				if (c == cols - 1 || find(r * cols + (c + 1)) == root)
				{
					break;
				}
				succes = 1;
				unionSets(cell, r * cols + (c + 1));
				break;
			case 1:
				// up
				if (r == 0 || find((r - 1) * cols + c) == root)
				{
					break;
				}
				succes = 1;
				unionSets(cell, (r - 1) * cols + c);
				break;
			case 2:
				// left
				if (c == 0 || find(r * cols + (c - 1)) == root)
				{
					break;
				}
				succes = 1;
				unionSets(cell, r * cols + (c - 1));
				break;
			case 3:
				// down
				if (r == rows - 1 || find((r + 1) * cols + c) == root)
				{
					break;
				}
				succes = 1;
				unionSets(cell, (r + 1) * cols + c);
				break;
			}
		}
	}
}

//Finds and prints a solution for the given maze.
void Maze::print_solution(int rows, int cols)
{
	//Determines the start and end field of the maze.
	int start = 0;
	int end = rows * cols - 1;
	
	//Creates the arrays for the path from start and from end. 
	int start_path[rows * cols];
	int end_path[rows * cols];
	start_path[0] = start;
	end_path[0] = end;
	int start_path_len = 1;
	int end_path_len = 1;
	//Create solution array
	int solution[rows * cols];
	int solution_len = 0;

	//Locates the root.
	int root = find(start);
	int cell = start;

	//Creates path to the root from the start of the maze.
	while (cell != root)
	{
		cell = s[cell];
		start_path[start_path_len] = cell;
		start_path_len++;
	}

	//creates path to the root from the end of the maze.
	cell = end;
	while (cell != root)
	{
		cell = s[cell];
		end_path[end_path_len] = cell;
		end_path_len++;
	}

	//Prints the path from start to root
	/**
	for (int i = 0; i < start_path_len; i++)
	{
		cout << start_path[i] << " ";
	}
	cout << endl;
	**/
	//Prints the path from end to root
	/**
	for (int i = 0; i < end_path_len; i++)
	{
		cout << end_path[i] << " ";
	}
	cout << endl;
	**/

	//Locates the meeting point between the two paths.
	int meeting_point;
	for (int i = 0; i < start_path_len; i++)
	{
		//Fills the solution with first part of the start to root path.
		//until the two paths meet.
		solution[i] = start_path[i];
		solution_len++;
		for (int j = 0; j < end_path_len; j++)
		{
			if (start_path[i] == end_path[j])
			{
				meeting_point = j;
				i = start_path_len;
				break;
			}
		}
	}

	//Fills the solution with the rest of the path from
	// end to root which is adfter the meeting point.
	for (int i = meeting_point - 1; i > -1; i--)
	{
		solution[solution_len] = end_path[i];
		solution_len++;
	}
	cout << endl;

	//Prints the solution.
	cout << "solution is: ";
	for (int i = 0; i < solution_len; i++)
	{
		cout << solution[i] << " ";
	}
	cout << endl << "Leangth of the solution is: " << solution_len << endl;
}