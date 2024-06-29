#pragma once
#include <base/signal/ISignalSource.h>
#include <base/signal/PeriodicSamplingClock.h>
#include <math.h>

namespace base
{
	/// @brief 正弦信号源 y = sin(w * t)
	class SinSignalSource
		: base::ISignalSource<double>
	{
	private:
		double _sin_periodic = 1;
		double _sample_interval = 0.1;
		PeriodicSamplingClock<double> _sample_clock;

	public:
		/// @brief
		/// @param sin_periodic 正弦信号的最小正周期
		/// @param sample_interval 采样的时间间隔
		SinSignalSource(double sin_periodic, double sample_interval);

		double Sample() override;
	};
}
