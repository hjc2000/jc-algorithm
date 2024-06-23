#include <base/signal/ISignalSource.h>
#include <math.h>

namespace base
{
	/// @brief 正弦信号源 y = sin(w * t)
	/// @tparam T
	template <typename SignalType, typename TimeType>
	class SinSignalSource
		: base::ISignalSource<SignalType, TimeType>
	{
	private:
		TimeType _periodic;

	public:
		/// @brief
		/// @param periodic 最小正周期
		SinSignalSource(TimeType periodic)
		{
			_periodic = periodic;
		}

		SignalType Sample(TimeType time) override
		{
			// y = sin(w * t)
			// w = 2pi / T
			// y = sin(2pi / T * t)
			return sin(2 * M_PI * time / _periodic);
		}
	};
}
