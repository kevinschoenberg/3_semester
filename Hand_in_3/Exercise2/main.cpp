#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double f1(double x)
{
	return 5 * x - 22;
}

double f2(double x)
{
	return 3 * exp(x);
}

double search(double a, double b, double c, double (*f)(double x))
{
	int att = 0;

	while (1)
	{
		att++;
		double x = ((b - a) / 2) + a;

		double margin = 1e-10;
		double error = abs(abs(f(x)) - abs(c));
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
	cout << "f1" << endl;
	double x1 = search(0, 10000, 70.3, &f1);
	cout << "f2" << endl;
	double x2 = search(0, 1000, 69.420, &f2);

	return 0;
}