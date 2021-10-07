template <typename Object>
void Matrix<Object>::add(Matrix &mat)
{
	int rows = numrows();
	int cols = numcols();

	if (rows != mat.numrows() || cols != mat.numcols())
	{
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			array[i][j] = array[i][j] + mat[i][j];
		}
	}
}

template <typename Object>
Matrix<Object> &multiply(Matrix<Object> &a, Matrix<Object> &b)
{
	if (a.numcols() != b.numrows())
	{
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

	Matrix<Object> *mult = new Matrix<Object>(a.numrows(), b.numcols());

	for (int i = 0; i < a.numrows(); ++i)
	{
		for (int j = 0; j < b.numcols(); ++j)
		{
			(*mult)[i][j] = 0;
		}
	}

	for (int i = 0; i < a.numrows(); ++i)
	{
		for (int j = 0; j < b.numcols(); ++j)
		{
			for (int k = 0; k < b.numrows(); k++)
			{
				(*mult)[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return *mult;
}

template <typename Object>
Matrix<Object> &transpose(Matrix<Object> &mat)
{

	Matrix<Object> *trans = new Matrix<Object>(mat.numcols(), mat.numrows());

	for (int i = 0; i < mat.numrows(); ++i)
	{
		for (int j = 0; j < mat.numcols(); ++j)
		{
			(*trans)[j][i] = mat[i][j];
		}
	}

	return *trans;
}

#include <algorithm>

template <typename Object>
Matrix<Object> &matsort(Matrix<Object> &mat)
{

	//Puts matrix into an array
	Object temp[mat.numrows() * mat.numcols()];
	int k = 0;

	for (int i = 0; i < mat.numrows(); ++i)
	{
		for (int j = 0; j < mat.numcols(); ++j)
		{
			temp[k++] = mat[i][j];
		}
	}

	//Sorts the array
	std::sort(temp, temp + k);

	Matrix<Object> *sorted = new Matrix<Object>(mat.numrows(), mat.numcols());

	k = 0;

	//Puts the array back into matrix form
	for (int i = 0; i < mat.numrows(); ++i)
	{
		for (int j = 0; j < mat.numcols(); ++j)
		{
			(*sorted)[i][j] = temp[k++];
		}
	}

	return *sorted;
}

template <typename Object>
bool matsearch(Matrix<Object> &mat, int x)
{
	int itt = 0;
	int row = 0;
	int col = 0;

	//Finding row x must be in O(n)
	while (row + 1 < mat.numrows())
	{
		if (mat[row + 1][col] > x)
		{
			break;
		}
		row++;
	}

	//Check if we found x on the first col O(1)
	if (mat[row][0] == x)
	{
		cout << "Found: " << mat[row][0] << endl;
		return true;
	}

	//Searching row for x O(n)
	while (col < mat.numcols())
	{
		if (mat[row][col] == x)
		{
			cout << "Found: " << mat[row][col] << endl;
			return true;
		}
		col++;
	}

	//If x was not found
	cout << "Did not find: " << x << endl;
	return false;
}
