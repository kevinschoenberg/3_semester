#include <iostream>

using namespace std;

double f(double x)
{
	return x;
}

double search(double a, double b, double c, double (*f)(double x))
{
	
	int att = 0;

	while(1)
	{
		att++;
		double x = (a + b) / 2;
		cout << att << " " << x << endl;
		if(f(x) == c)
		{
			cout << "Found x: " << x << " in " << att << " attempts" << endl;
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
//Se data med 1.5 Den viser en logaritmist udvikling
int main()
{
	cout << search(0, 10000, 1.5, &f) << endl;
	return 0;
}