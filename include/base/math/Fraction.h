#pragma once
#include<ostream>
#include<stdint.h>
#include<string>

namespace base
{
	class Fraction
	{
	private:
		int64_t _num = 0;
		int64_t _den = 1;

	public:
		#pragma region 生命周期
		/// <summary>
		///		默认构造，分子为 0，分母为 1.
		/// </summary>
		Fraction() = default;

		/// <summary>
		///		整型转化为分数，则分子等于整型，分母为 1.
		/// </summary>
		/// <param name="num"></param>
		Fraction(int64_t num);

		Fraction(int64_t num, int64_t den);
		Fraction(Fraction const &o);

		Fraction &operator=(Fraction const &o);

		/// <summary>
		///		将整型赋值给分数，则变为分子为该整型，分母为 1 的分数。
		/// </summary>
		/// <param name="o"></param>
		/// <returns></returns>
		Fraction &operator=(int64_t o);
		#pragma endregion

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
		Fraction operator*(Fraction const &value) const;
		Fraction operator/(Fraction const &value) const;

		/// <summary>
		///		倒数
		/// </summary>
		/// <returns></returns>
		Fraction Reciprocal() const;

		Fraction &operator+=(Fraction const &value);
		Fraction &operator-=(Fraction const &value);
		Fraction &operator*=(Fraction const &value);
		Fraction &operator/=(Fraction const &value);

		std::string ToString() const;
	};
}

std::ostream &operator<<(std::ostream &ostream, base::Fraction const &fraction);
