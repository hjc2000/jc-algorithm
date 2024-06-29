#include "Fraction.h"
#include <numeric>
#include <stdexcept>

using namespace base;

#pragma region 生命周期
base::Fraction::Fraction(int64_t num)
{
	SetNum(num);
	SetDen(1);
}

base::Fraction::Fraction(int64_t num, int64_t den)
{
	SetNum(num);
	SetDen(den);
}

base::Fraction::Fraction(Fraction const &o)
{
	SetNum(o.Num());
	SetDen(o.Den());
}

Fraction &base::Fraction::operator=(Fraction const &o)
{
	SetNum(o.Num());
	SetDen(o.Den());
	return *this;
}

Fraction &base::Fraction::operator=(int64_t o)
{
	SetNum(o);
	SetDen(1);
	return *this;
}
#pragma endregion

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
	if (value == 0)
	{
		throw std::invalid_argument{"分母不能为 0."};
	}

	_den = value;
}

Fraction base::Fraction::Simplify() const
{
	if (_den == 0)
	{
		throw std::invalid_argument{"分母不能为 0."};
	}

	// 分子分母同时除以最大公约数
	int64_t gcd_value = std::gcd(_num, _den);
	int64_t scaled_num = _num / gcd_value;
	int64_t scaled_den = _den / gcd_value;

	if (scaled_den < 0)
	{
		// 如果分母小于 0，分子分母同时取相反数
		scaled_num = -scaled_num;
		scaled_den = -scaled_den;
	}

	Fraction ret{scaled_num, scaled_den};
	return ret;
}

Fraction base::Fraction::operator-() const
{
	Fraction ret{-_num, _den};
	return ret.Simplify();
}

Fraction base::Fraction::operator+(Fraction const &value) const
{
	// 通分后的分母为本对象的分母和 value 的分母的最小公倍数
	int64_t scaled_den = std::lcm(_den, value.Den());

	// 通分后的分子为本对象的分子乘上分母所乘的倍数
	int64_t scaled_num = _num * (scaled_den / _den);
	int64_t value_scaled_num = value.Num() * (scaled_den / value.Den());

	Fraction ret{
		scaled_num + value_scaled_num,
		scaled_den,
	};

	return ret.Simplify();
}

Fraction base::Fraction::operator-(Fraction const &value) const
{
	Fraction ret = *this + (-value);
	return ret.Simplify();
}

Fraction base::Fraction::operator*(Fraction const &value) const
{
	Fraction ret;
	ret.SetNum(_num * value.Num());
	ret.SetDen(_den * value.Den());
	return ret.Simplify();
}

Fraction base::Fraction::operator/(Fraction const &value) const
{
	Fraction ret{*this * value.Reciprocal()};
	return ret.Simplify();
}

Fraction base::Fraction::Reciprocal() const
{
	Fraction ret{_den, _num};
	return ret.Simplify();
}

Fraction &base::Fraction::operator+=(Fraction const &value)
{
	*this = *this + value;
	return *this;
}

Fraction &base::Fraction::operator-=(Fraction const &value)
{
	*this = *this - value;
	return *this;
}

Fraction &base::Fraction::operator*=(Fraction const &value)
{
	*this = *this * value;
	return *this;
}

Fraction &base::Fraction::operator/=(Fraction const &value)
{
	*this = *this / value;
	return *this;
}

#pragma region 强制转换
int64_t base::Fraction::Div() const
{
	return _num / _den;
}

int64_t base::Fraction::Mod() const
{
	return _num % _den;
}

double base::Fraction::ToDouble() const
{
	return static_cast<double>(_num) / _den;
}

std::string base::Fraction::ToString() const
{
	return std::to_string(_num) + " / " + std::to_string(_den);
}

base::Fraction::operator int64_t() const
{
	return Div();
}

base::Fraction::operator double() const
{
	return ToDouble();
}

base::Fraction::operator std::string() const
{
	return ToString();
}
#pragma endregion

#pragma region 全局重载运算符
std::ostream &operator<<(std::ostream &ostream, base::Fraction const &fraction)
{
	ostream << fraction.ToString();
	return ostream;
}

base::Fraction operator+(int64_t left, base::Fraction const &right)
{
	return base::Fraction{left} + right;
}

base::Fraction operator-(int64_t left, base::Fraction const &right)
{
	return base::Fraction{left} - right;
}

base::Fraction operator*(int64_t left, base::Fraction const &right)
{
	return base::Fraction(left) * right;
}

base::Fraction operator/(int64_t left, base::Fraction const &right)
{
	return base::Fraction{left} / right;
}
#pragma endregion
