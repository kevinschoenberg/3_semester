#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//Define function 1
double f1(double x)
{
	return 5 * x - 22;
}

//define function 2
double f2(double x)
{
	return 3 * exp(x);
}

//Serach for x such that the function equals C.
//We use binary search to find x, which is O(logN)
double search(double a, double b, double c, double (*f)(double x))
{
	int att = 0;

	//Keeps increasing x until it reaches the an x value which return C in the function:
	//This is within a margin of error.
	while (1)
	{
		att++;
		double x = ((b - a) / 2) + a;

		// If error is less than e^-10, then we say we found x
		// This is because there could be an error forced by the precision of the double datatype
		double margin = 1e-10;
		double error = abs(abs(f(x)) - abs(c));
		//Only enters this iff. x is wtihin the margin of error.
		if (error < margin)
		{
			cout << fixed << setprecision(6) << "x: " << x << " att: " << att << endl;
			cout << fixed << setprecision(3) << "f(x): " << f(x) << endl;
			return x;
		}
		else if (f(x) > c)
		{
			b = x;
		}
		else
		{
			a = x;
		}
	}
}

int main()
{
	int Test_interval = 100000;
	//Test f1:
	for (size_t i = 10; i < Test_interval; i=i*10)
	{
		cout << "f1" << endl;
		double x1 = search(0, 10000, i, &f1);
	}
	//Test f2
	for (size_t i = 10; i < Test_interval; i=i*10)
	{
		cout << "f2" << endl;
		double x1 = search(0, 10000 , i, &f1);
	}
	
	cout << "f1" << endl;
	double x1 = search(0, 10000, 70.3, &f1);
	cout << "f2" << endl;
	double x2 = search(0, 1000, 69.420, &f2);

	return 0;
}