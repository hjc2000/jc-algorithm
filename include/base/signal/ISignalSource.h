
namespace base
{
	/// @brief 能够对任意时刻进行采样的信号源接口。
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
