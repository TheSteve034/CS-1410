#include <iostream>
#include "fraction.h"
#include <iomanip>
using namespace std;

fraction operator+(fraction f1, fraction f2)
{
	int a = (f1.numerator * f2.denominator) + (f1.denominator*f2.numerator);
	int b = f1.denominator * f2.denominator;
	int g = gcd(a, b);
	f1.denominator = b / g;
	f1.numerator = a / g;

	return fraction(f1);
}

fraction operator-(fraction f1, fraction f2)
{
	int a = (f1.numerator * f2.denominator) - (f1.denominator * f2.numerator);
	int b = f1.denominator * f2.denominator;

	int g = gcd(a, b);

	f1.denominator = b / g;
	f1.numerator = a / g;

	return fraction(f1);
}

fraction operator*(fraction f1, fraction f2)
{
	int a = f1.numerator*f2.numerator;
	int b = f1.denominator*f2.denominator;
	int g = gcd(a, b);
	f1.denominator = b / g;
	f1.numerator = a / g;

	return fraction(f1);
}

fraction operator/(fraction f1, fraction f2)
{
	int a = f1.numerator*f2.denominator;
	int b = f1.denominator*f2.numerator;
	int g = gcd(a, b);
	f1.denominator = b / g;
	f1.numerator = a / g;

	return fraction(f1);
}

istream& operator>>(istream& in, fraction& f)
{
	cout << "please enter the numerator: ";
	cin >> f.numerator;
	cout << "please enter the denominator: ";
	cin >> f.denominator;

	return in;
}

ostream& operator<<(ostream& out, fraction& f)
{
	cout.fill('0');
	cout << f.numerator << '/';
	cout << f.denominator << endl;
	cout.fill(' ');

	return out;
}

int gcd(int u, int v)
{
	u = (u < 0) ? -u : u;			// make u non-negative
	v = (v < 0) ? -v : v;			// make v non-negative

	while (u > 0)
	{
		if (u < v)
		{
			int t = u;	// swap u and v
			u = v;
			v = t;
		}

		u -= v;
	}

	return v;				// the GCD of u and v
}