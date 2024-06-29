#pragma once
#include <stdint.h>

namespace base
{
	/// @brief 周期采样时钟。
	/// @note 时间大于一个周期时会自动减去整数倍的周期，调整到一个周期以内。
	/// @tparam TimeType
	template <typename TimeType>
	class PeriodicSamplingClock
	{
	private:
		TimeType _period{};
		TimeType _time{};

		void AdjustTime()
		{
			int64_t div = static_cast<int64_t>(_time / _period);
			_time -= _period * static_cast<TimeType>(div);
		}

	public:
		/// @brief 时钟的周期。
		/// @param period
		PeriodicSamplingClock(TimeType period)
		{
			_period = period;
			_time = 0;
		}

#pragma region 四则运算符
		PeriodicSamplingClock &operator+=(TimeType value)
		{
			_time += value;
			AdjustTime();
			return *this;
		}

		PeriodicSamplingClock &operator-=(TimeType value)
		{
			_time -= value;
			AdjustTime();
			return *this;
		}

		PeriodicSamplingClock &operator*=(TimeType value)
		{
			_time *= value;
			AdjustTime();
			return *this;
		}

		PeriodicSamplingClock &operator/=(TimeType value)
		{
			_time /= value;
			AdjustTime();
			return *this;
		}
#pragma endregion

		TimeType Time() const
		{
			return _time;
		}

		explicit operator TimeType() const
		{
			return _time;
		}
	};
} // namespace base
