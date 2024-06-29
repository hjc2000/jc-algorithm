#pragma once
#include <stdint.h>

namespace base
{
	/// @brief 周期采样时钟。
	/// @tparam TimeType
	template <typename TimeType>
	class PeriodicSamplingClock
	{
	private:
		TimeType _period{};
		TimeType _time{};

		void AdjustTime()
		{
			// 如果是浮点类型，会被截断后进行整数除法
			int64_t div = static_cast<int64_t>(_time) / _period;
			_time -= div * _period;
		}

	public:
		PeriodicSamplingClock(TimeType period)
		{
			_period = period;
			_time = 0;
		}

		PeriodicSamplingClock &operator+=(TimeType time)
		{
			_time += time;
		}
	};
} // namespace base
