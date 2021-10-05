#include <iostream>
#include <math.h>

using namespace std;

double f1(double x)
{
	return 5*x-22;
}
double f2(double x)
{
	return 3*exp(x);
}

double search(double a, double b, double c, double (*f)(double x))
{
	int att = 0;

	while(1)
	{
		att++;
		double x = (a + b) / 2;
		// If error is less than e^-10, then we say we found x
		// This is because there could be an error forced by the precision of the double datatype
		double errorMargin = 1e-10;
		double error = abs(abs(f(x)) - abs(c));
		if(error < errorMargin)
		{
			cout << "Found x: " << x << " in " << att << " attempts" << ", f(x) = " << f(x) << ", with error: " << abs(abs(f(x)) - abs(c)) << endl;
			return x;
		} else if (f(x) > c)
		{
			b = x;
		} else
		{
			a = x;
		}
	}
}
int main()
{
	cout << "f1" << endl;
	double x1 = search(0, 10000, 70.3, &f1);
	cout << "f2" << endl;
	double x2 = search(0, 10000, 70.3, &f2);

	return 0;
}