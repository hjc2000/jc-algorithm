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

		double Sample(double time) override;
	};
}
