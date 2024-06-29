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

		/// @brief 采样一次。
		/// @note 调用者不需要延时，每次采样都会自动将内部维护的时间递增构造函数
		/// 传进来的 sample_interval。
		///
		/// @return 采样值。
		double Sample() override;
	};
}
