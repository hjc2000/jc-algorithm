#include "PeriodicSamplingClock.h"

void base::PeriodicSamplingClock::AdjustTime()
{
	// 将时间减去整数倍的周期
	int64_t div = static_cast<int64_t>(_time / _period);
	_time -= _period * div;
}

base::PeriodicSamplingClock::PeriodicSamplingClock(base::Fraction period)
	: _period(period)
{
}
