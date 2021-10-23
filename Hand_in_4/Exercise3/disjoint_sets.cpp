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

	// s[root2] = root1;
}

void Maze::print_s(int rows, int cols)
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
	cout << endl;
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
			cout << "i " << cell << " " << dir << endl;
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
		cout << "test" << endl;
	}

	// Måde at bruge array som matrix
	// r er den række man vil ned på
	// c er den kolonne man vil hen på
	// s[r * cols + c];
}