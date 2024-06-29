#pragma once
#include <base/signal/ISignalSource.h>
#include <math.h>

namespace base
{
	/// @brief 正弦信号源 y = sin(w * t)
	class DoubleSinSignalSource
		: base::ISignalSource<double, double>
	{
	private:
		double _periodic;

	public:
		/// @brief
		/// @param periodic 最小正周期
		DoubleSinSignalSource(double periodic);

		/// @brief 采样 time 时刻的值。
		///
		/// @param time 时刻。
		/// @note 注意，double 非常大时精度会降低。double 没必要大于最小正周期太多。
		/// 对于连续采样，有一个 time 变量，每次采样后增大一点。当 time 大于最小正周期后，
		/// 可以将 time 减去最小正周期，这样可以让 time 保持在较高的精度。
		///
		/// @return
		double Sample(double time) override;
	};
}
