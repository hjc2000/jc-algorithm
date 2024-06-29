#pragma once
#include <base/signal/ISignalSource.h>
#include <base/signal/PeriodicSamplingClock.h>
#include <math.h>

namespace base
{
	/// @brief 正弦信号源 y = sin(w * t)
	class SinSignalSource
		: base::ISignalSource<double, PeriodicSamplingClock<double>>
	{
	private:
		double _periodic;

	public:
		/// @brief
		/// @param periodic 最小正周期
		SinSignalSource(double periodic);

		/// @brief 采样 time 时刻的值。
		/// @param time 时刻。
		/// @return
		double Sample(PeriodicSamplingClock<double> time) override;
	};
}
