#pragma once

namespace base
{
	/// @brief 能够对任意时刻进行采样的信号源接口。
	/// @note 这种信号源通常是一个关于时间的函数，能够根据任意的时间值计算出采样值。
	///
	/// @tparam SignalType
	/// @tparam TimeType
	template <typename SignalType, typename TimeType>
	class ISignalSource
	{
	public:
		virtual ~ISignalSource() = default;

		/// @brief 非实时采样。传入时刻，获取对应时刻的信号值。
		/// @param time 采样时刻。
		/// @return
		virtual SignalType Sample(TimeType time) = 0;
	};
}
