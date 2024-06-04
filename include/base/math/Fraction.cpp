#include"Fraction.h"
#include<numeric>

base::Fraction::Fraction(int64_t num, int64_t den)
{
	_num = num;
	_den = den;
}

base::Fraction::Fraction(Fraction const &o)
{
	_num = o.Num();
	_den = o.Den();
}

int64_t base::Fraction::Num() const
{
	return _num;
}

void base::Fraction::SetNum(int64_t value)
{
	_num = value;
}

int64_t base::Fraction::Den() const
{
	return _den;
}

void base::Fraction::SetDen(int64_t value)
{
	_den = value;
}

void base::Fraction::Simplify()
{

}
