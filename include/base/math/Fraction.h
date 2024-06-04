#pragma once
#include<stdint.h>

namespace base
{
	class Fraction
	{
	private:
		int64_t _num { };
		int64_t _den { };

	public:
		Fraction() = default;
		Fraction(int64_t num, int64_t den);
		Fraction(Fraction const &o);

		int64_t Num() const;
		void SetNum(int64_t value);

		int64_t Den() const;
		void SetDen(int64_t value);

		/// <summary>
		///		化简分数
		/// </summary>
		void Simplify();
	};
}