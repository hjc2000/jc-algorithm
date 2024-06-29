#pragma once

namespace base
{
	template <typename SignalType>
	class ISignalSource
	{
	public:
		virtual ~ISignalSource() = default;

		/// @brief 采样一次。
		/// @return 采样值。
		virtual SignalType Sample() = 0;
	};
}
