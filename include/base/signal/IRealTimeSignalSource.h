
namespace base
{
	/// @brief 实时采样的信号源接口
	/// @tparam T
	template <typename T>
	class IRealTimeSignalSource
	{
	public:
		virtual ~IRealTimeSignalSource() = default;

		/// @brief 实时采样。采样当前时刻的信号值。
		/// @return
		virtual T Sample() = 0;
	};
}
