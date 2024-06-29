#pragma once
#include <base/math/Fraction.h>
#include <stdint.h>

namespace base
{
	/// @brief 周期采样时钟。
	/// @note 时间大于一个周期时会自动减去整数倍的周期，调整到一个周期以内。
	class PeriodicSamplingClock
	{
	private:
		base::Fraction _period{};
		base::Fraction _time{};

		void AdjustTime();

	public:
		/// @brief 时钟的周期。
		/// @param period
		PeriodicSamplingClock(base::Fraction period);

#pragma region 四则运算符
		PeriodicSamplingClock &operator+=(base::Fraction value)
		{
			_time += value;
			AdjustTime();
			return *this;
		}

		PeriodicSamplingClock &operator-=(base::Fraction value)
		{
			_time -= value;
			AdjustTime();
			return *this;
		}

		PeriodicSamplingClock &operator*=(base::Fraction value)
		{
			_time *= value;
			AdjustTime();
			return *this;
		}

		PeriodicSamplingClock &operator/=(base::Fraction value)
		{
			_time /= value;
			AdjustTime();
			return *this;
		}
#pragma endregion

		/// @brief 本时钟的周期
		/// @return
		base::Fraction Period() const
		{
			return _period;
		}

		base::Fraction Time() const
		{
			return _time;
		}

		explicit operator base::Fraction() const
		{
			return _time;
		}
	};
} // namespace base
