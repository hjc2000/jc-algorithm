#pragma once
#include<stdint.h>

namespace base
{
	class Fraction
	{
	private:
		int64_t _num = 0;
		int64_t _den = 1;

	public:
		Fraction() = default;
		Fraction(int64_t num, int64_t den);
		Fraction(Fraction const &o);
		Fraction &operator=(Fraction const &o);

		int64_t Num() const;
		void SetNum(int64_t value);

		int64_t Den() const;
		void SetDen(int64_t value);

		/// <summary>
		///		化简分数，返回化简后的值。
		/// </summary>
		Fraction Simplify() const;

		Fraction operator-() const;
		Fraction operator+(Fraction const &value) const;
		Fraction operator-(Fraction const &value) const;

		/// <summary>
		///		倒数
		/// </summary>
		/// <returns></returns>
		Fraction Reciprocal() const;

		Fraction &operator+=(Fraction const &value);
		Fraction &operator-=(Fraction const &value);
	};
}