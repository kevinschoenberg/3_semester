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

int DisjSets::new_find(int x)
{
	int root = x;

	if (s[x] < 0)
	{
		return s[x]; // O(1)
	}

	while (s[root] >= 0)
	{
		root = s[root]; // O(n)
	}
	int prev;
	int step = x;
	while (s[step] >= 0)
	{
		prev = step;
		step = s[step]; // O(n)
		unionSets(root, prev);
	}

	return root;
}

void DisjSets::print_s(int numElements)
{
	for (int i = 0; i < numElements; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void DisjSets::printx(int x, size_t numElements)
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

// Exercise 3.a
Maze::Maze() : s(1, -1) {}
Maze::Maze(int rows, int cols) : s(rows * cols, -1)
{
	generate(rows, cols);
}

int Maze::find(int x)
{
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}

void Maze::unionSets(int root1, int root2)
{
	s[root2] = root1;
}

void Maze::print_maze(int rows, int cols)
{
	// encode
	int en_rows = rows * 2 + 1;
	int en_cols = cols * 2 + 1;
	int en[en_cols * en_rows];
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

	// alle kanterne
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

	// vægge på rækkerne
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

	// decode

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
		// cout << en[i] << " ";

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
	// cout << endl;
	return len;
}

void Maze::generate(int rows, int cols)
{
	// fjern walls ved at union to felter der er ved siden af hinanden

	srand(time(0));

	int dir, c, r, root, succes;

	int start = 0;
	int end = (rows - 1) * (cols - 1);
	int cells = rows * cols;
	int cell;

	while (getlen(end, cells) != cells)
	{
		cell = rand() % cells;
		// hvis find giver "0" altså roden til alt, så er den med og der skal ikke gøre snoget
		// vi lader dog 0 komme gennem
		root = find(cell);

		// Tjek om c eller r er 0, r == rwos eller c == cols.

		// Hvis den retning vi går har samme root, så break;

		c = cell % cols;
		r = floor(cell / cols);

		int arr[] = {1, 1, 1, 1};
		int succes = 0;

		while (arr[0] + arr[1] + arr[2] + arr[3] != 0 && succes != 1)
		{
			dir = rand() % 4;
			arr[dir] = 0;
			// cout << "i " << cell << " " << dir << endl;
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

	// Måde at bruge array som matrix
	// r er den række man vil ned på
	// c er den kolonne man vil hen på
	// s[r * cols + c];
}

void Maze::print_solution(int rows, int cols)
{
	int start = 0;
	int end = rows * cols - 1;

	int start_path[rows * cols];
	int end_path[rows * cols];
	start_path[0] = start;
	end_path[0] = end;

	int start_path_len = 1;
	int end_path_len = 1;

	int root = find(start);
	int cell = start;
	while (cell != root)
	{
		cell = s[cell];
		start_path[start_path_len] = cell;
		start_path_len++;
	}

	cell = end;
	while (cell != root)
	{
		cell = s[cell];
		end_path[end_path_len] = cell;
		end_path_len++;
	}

	for (int i = 0; i < start_path_len; i++)
	{
		cout << start_path[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < end_path_len; i++)
	{
		cout << end_path[i] << " ";
	}

	cout << endl;

	int solution[rows * cols];
	int solution_len = 0;
	int meeting_point;
	for (int i = 0; i < start_path_len; i++)
	{
		solution[i] = start_path[i];
		solution_len++;
		for (int j = 0; j < end_path_len; j++)
		{
			if (start_path[i] == end_path[j])
			{
				meeting_point = j;
				cout << "mp" << meeting_point;
				i = start_path_len;
				break;
			}
		}
	}
	for (int i = meeting_point - 1; i > -1; i--)
	{
		solution[solution_len] = end_path[i];
		solution_len++;
	}

	cout << endl;
	cout << "solution is: ";
	for (int i = 0; i < solution_len; i++)
	{
		cout << solution[i] << " ";
	}
	cout << endl
		 << solution_len << endl;
}