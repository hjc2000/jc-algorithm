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
		base::Fraction _sample_interval{1, 10};
		PeriodicSamplingClock<base::Fraction> _sample_clock;
		bool _opened = false;

	public:
		/// @brief
		/// @param sin_periodic 正弦信号的最小正周期
		/// @param sample_interval 采样的时间间隔
		SinSignalSource(double sin_periodic);

		/// @brief 采样间隔。单位：秒。
		/// @return
		base::Fraction SampleInterval() const override;

		/// @brief 设置采样间隔。单位：秒。
		/// @param value
		void SetSampleInterval(base::Fraction value) override;

		void Open() override;

		/// @brief 采样一次。
		/// @note 调用者不需要延时，每次采样都会自动将内部维护的时间递增构造函数
		/// 传进来的 sample_interval。
		///
		/// @return 采样值。
		double Sample() override;
	};
}
