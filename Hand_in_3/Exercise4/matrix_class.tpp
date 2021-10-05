template <typename Object>
void Matrix<Object>::add(Matrix& mat) {
	int rows = numrows();
	int cols = numcols();

	if (rows != mat.numrows() || cols != mat.numcols()) {
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

	for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            array[i][j] = array[i][j] + mat[i][j];
		}
	}
}

template <typename Object>
Matrix<Object>& multiply(Matrix<Object>& a, Matrix<Object>& b) {
	if (a.numcols() != b.numrows()) {
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

	Matrix<Object> *mult = new Matrix<Object>(a.numrows(), b.numcols());

	for(int i = 0; i < a.numrows(); ++i) {
        for(int j = 0; j < b.numcols(); ++j) {
			(*mult)[i][j] = 0;
		}
	}

	for(int i = 0; i < a.numrows(); ++i) {
        for(int j = 0; j < b.numcols(); ++j) {
			for (int k = 0; k < b.numrows(); k++) {
				(*mult)[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return *mult;
}

template <typename Object>
void Matrix<Object>::transpose() {

	int oldrows = numrows();
	int oldcols = numcols();

	if (numrows() < numcols())
	{
		for (int i = 0; i < (numcols()-numrows()); i++)
		{
			cout << numcols()-numrows() << endl;
			cout << "adding col" << endl;
			array.push_back(array[0]);
		}
	} else if (numcols() < numrows())
	{
		for(auto& r : array) 
		{
			r.resize(numrows());
		}
	}
	

	for (int i = 0; i < numrows(); ++i) {
        for (int j = 0; j < numcols(); ++j) {
        	if (i == j)
        	{
        		break;
        	} else {
        		array[j][i] = array[j][i] + array[i][j];
    			array[i][j] = array[j][i] - array[i][j];
    			array[j][i] = array[j][i] - array[i][j];
        	}
		}
	}

	if (oldcols != numrows())
	{
		array.resize(oldcols);
	} else if (oldrows != numcols())
	{
		for(auto& r : array) 
		{
			r.resize(oldrows);
		}
	}
}