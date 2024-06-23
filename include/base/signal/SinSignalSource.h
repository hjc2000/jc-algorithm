#include <base/signal/ISignalSource.h>
#include <math.h>

namespace base
{
	/// @brief 正弦信号源 y = sin(w * t)
	class SinSignalSource
		: base::ISignalSource<double, double>
	{
	private:
		double _periodic;

	public:
		/// @brief
		/// @param periodic 最小正周期
		SinSignalSource(double periodic)
		{
			_periodic = periodic;
		}

		double Sample(double time) override
		{
			// y = sin(w * t)
			// w = 2pi / T
			// y = sin(2pi / T * t)
			return sin(2 * M_PI * time / _periodic);
		}
	};
}
