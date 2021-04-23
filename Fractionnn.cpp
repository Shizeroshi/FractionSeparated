#include "Fractionn.h"
//#define Constructors_check
//#define ArithmeticalOperatorsCheck
//#define CompaundAssignmentCheck
//#define IncrementsCheck
//#define TypeConnvertions
#define CompatisonOperators

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator<(const Fraction& left, const Fraction& right)
{
	return (double)left < (double)right;
}

bool operator>(const Fraction& left, const Fraction& right)
{
	return (double)left > (double)right;
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return left > right || left == right;
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

void main()
{
	setlocale(LC_ALL, "");
	system("color 0A");
#ifdef Constructors_check
	Fraction A; // Default constructor
	cout << A << endl;
	Fraction B = -5; // single argument constructor
	cout << B << endl;
	Fraction C(-1, 2);
	cout << C << endl;
	Fraction D(-2, 3, 4);
	cout << D << endl;
#endif // Constructors_check

	/*Fraction A(7, 2);
	cout << A << " = " << A.to_proper() << endl;
	cout << A << " = " << A.to_improper() << endl;*/

	/*double a = 2.7;
	double b = 3.5;
	cout << a * b << endl;*/

#ifdef ArithmeticalOperatorsCheck
	Fraction A(2, 3, 5);
	Fraction B(-5, 6, 7);
	cout << A << "\t" << B << endl;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << B << " - " << B << " = " << B - B << endl;
	cout << B << " - " << B << " = " << B - A << endl;
	cout << B << " - " << B << " = " << A - B << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << " / " << B << " = " << A / B << endl;
	cout << A << "\t" << B << endl;
#endif // ArithmeticalOperatorsCheck
#ifdef CompaundAssignmentCheck
	Fraction A(2, 3, 4);
	Fraction B(5, 6, 7);
	A += B;
	cout << A << endl;
	A -= B;
	cout << A << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;

	Fraction reduce(840, 3600);
	cout << reduce.reduce() << endl;
	cout << Fraction(30, 7).reduce() << endl;
#endif // CompaundAssignmentCheck

#ifdef IncrementsCheck
	Fraction reduce(840, 3600);
	cout << reduce.reduce() << endl;
	cout << Fraction(30, 7).reduce() << endl;

	for (double i = .3; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(1, 2); i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // IncrementsCheck

#ifdef TypeConnvertions
	/*
int a = 2;
double b = 2;
int c = b;
double d = 2.5;
int e = d;
*/
//Fraction A = (Fraction)5; // From other to this / single argument constructor
	Fraction A(5); // Если конструктор эксплист то его можно вызвать только так
	cout << "Fraction A = " << A << endl;
	//a = (int)A;
	//cout << "int a = " << a << endl;

	/*Fraction B(-3, 4, 5);
	cout << B << endl;
	double b = (double)B;
	cout << b << endl;

	int c = (int)B;
	cout << c << endl;
	*/

	Fraction C = 2.3;
	cout << C << endl;
	cout << (double)C << endl;
#endif // TypeConnvertions

#ifdef CompatisonOperators
	Fraction A(1, 2);
	Fraction B(5, 11);
	/*if (A == B)
	{
		cout << "Fractions equal" << endl;
	}
	else
	{
		cout << "Fractions different" << endl;
	}*/
	/*cout << "Fractions " << (A == B ? "Equal" : "Different") << endl;*/
	cout << "Strict:\t";
	try
	{
		cout << (A == B) << endl;
	}
	catch (const exception&)
	{
		cout << "== Error" << endl;
	}
	try
	{
		cout << (A != B) << endl;
	}
	catch (const exception&)
	{
		cout << "!= Error" << endl;
	}
	cout << "Not strict:\t";
	try
	{
		cout << (A <= B) << endl;
	}
	catch (const exception&)
	{
		cout << "<= Error" << endl;
	}
	try
	{
		cout << (A >= B) << endl;
	}
	catch (const exception&)
	{
		cout << ">= Error" << endl;
	}
#endif // CompatisonOperators


}