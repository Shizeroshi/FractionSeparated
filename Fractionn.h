#pragma once
#include <iostream>

using namespace std;

#define DEBUG

class Fraction; // Class declaration - объявление класса
Fraction operator+(Fraction left, Fraction right); // Прототип
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);


class Fraction
{
	bool minus;
	bool plus;
	int integer; // Целая часть
	int numerator; // Числитель
	int denominator; // Знаменатель

public:
	bool get_minus()const
	{
		return minus;
	}
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denomintor()const
	{
		return denominator;
	}
	void set_minus(bool minus)
	{
		this->minus = minus;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numenator(int numenator)
	{
		this->numerator = numenator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	Fraction& set_minus_to_number()
	{
		if (minus)
		{
			integer = -integer;
			numerator = -numerator;
			minus = false;
		}
		return *this;
	}
	Fraction& get_minus_from_number()
	{
		if (integer < 0)
		{
			integer = -integer;
			minus = true;
		}
		if (numerator < 0)
		{
			numerator = -numerator;
			minus = true;
		}
		return *this;
	}

	// constructors
	Fraction()
	{
		this->minus = false;
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default constructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->minus = false;
		this->plus = false;
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		if (integer < 0)
		{
			minus = true;
			this->integer = -integer;
		}
#ifdef DEBUG
		cout << "Constructor1:\t" << this << endl;
#endif // DEBUG

	}
	Fraction(double decimal)
	{
		decimal += 1e-10;
		minus = decimal < 0 ? true : false;
		if (decimal < 0)
		{
			minus = true;
			decimal = -decimal;
		}
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();

#ifdef DEBUG
		cout << "Constructor double:\t" << this << endl;
#endif // DEBUG


	}


	Fraction(int numerator, int denomenator)
	{
		this->minus = false;
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denomenator);
#ifdef DEBUG
		cout << "Constructor2:\t\t" << this << endl;
#endif // DEBUG

		if (numerator < 0)
		{
			minus = true;
			this->numerator = -numerator;
		}
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->minus = false;
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
#ifdef DEBUG
		cout << "Constructor3:\t\t" << this << endl;

#endif // DEBUG
		if (integer < 0)
		{
			minus = true;
			this->integer = -integer;
		}
		if (numerator < 0)
		{
			minus = true;
			this->numerator = -numerator;
		}
	}
	~Fraction()
	{
#ifdef DEBUG
		cout << "Destructor:\t" << this << endl;
#endif // DEBUG

	}

	Fraction& operator=(const Fraction& other)
	{
		this->minus = other.minus;
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "CopyAssignment:\t" << this << endl;
#endif // DEBUG
		return *this;
	}

	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}

	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	// increment/decrement

	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}

	Fraction& operator++(int)
	{
		Fraction old = *this;
		this->integer++;
		return old;
	}

	Fraction& operator--()
	{
		this->integer--;
		return *this;
	}
	Fraction& operator--(int)
	{
		Fraction old = *this;
		this->integer--;
		return old;
	}

	// type cast operators

	explicit operator int()const
	{
		return minus ? -integer : integer;
	}
	explicit operator double()const
	{
		double number = integer + (double)numerator / denominator;
		if (minus)number = -number;
		return number;
	}

	// Methods:

	Fraction& to_proper()
	{
		get_minus_from_number();
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		get_minus_from_number();
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& reduce()
	{
		if (numerator == 0)return *this;
		int more, less, rest;
		// Выясняем кто больше, числитель, или знаменатель
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		// Находим наибольший числитель
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);

		int GCD = more; // Greatest Common Divisor
		// Собственно сокращаем дробь
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
};