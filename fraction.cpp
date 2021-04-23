#include "Fractionn.h"


Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	left.set_minus_to_number();
	right.set_minus_to_number();

	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numenator(left.get_numerator()*right.get_denomintor() + right.get_numerator()*left.get_denomintor());
	result.set_denominator(left.get_denomintor()*right.get_denomintor());
	result.to_proper().get_minus_from_number();
	return result.reduce();
}

Fraction operator-(Fraction left, Fraction right)
{
	/*left.to_proper().set_minus_to_number();
	right.to_proper().set_minus_to_number();
	return Fraction
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denomintor() - right.get_numerator() * left.get_denomintor(),
		left.get_denomintor() *	right.get_denomintor()
	).to_proper().get_minus_from_number();*/
	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();
	return Fraction
	(
		left.get_numerator() * right.get_denomintor() - right.get_numerator() * left.get_denomintor(),
		left.get_denomintor() *	right.get_denomintor()
	).to_proper().reduce();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();
	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denomintor()*right.get_denomintor()
	).to_proper().get_minus_from_number().reduce();
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator()*right.get_denomintor(),
		right.get_numerator()*left.get_denomintor()
	);
	result.to_proper();
	if (left.get_minus() || right.get_minus())result.set_minus(true);
	if (left.get_minus() && right.get_minus())result.set_minus(false);
	return result.reduce();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper().reduce();
	right.to_improper().reduce();
	/*if (left.get_numerator()*right.get_denomintor() == right.get_numerator()*left.get_denomintor())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	/*if (left.get_numerator() == right.get_numerator() && left.get_denomintor() == right.get_denomintor())
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return left.get_numerator() == right.get_numerator() && left.get_denomintor() == right.get_denomintor();
}





ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_minus())os << "(-";
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator())os << "(";
	if (obj.get_numerator())os << obj.get_numerator() << "/" << obj.get_denomintor();
	if (obj.get_integer() && obj.get_numerator())os << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	if (obj.get_minus())os << ")";
	return os;
}

