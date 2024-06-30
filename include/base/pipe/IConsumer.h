#pragma once

namespace base
{
	template <typename T>
	class IConsumer
	{
	public:
		virtual ~IConsumer() = default;

		/// @brief 向消费者送入数据
		/// @param data
		virtual void SendData(T data) = 0;

		/// @brief 冲洗消费者
		virtual void Flush()
		{
			// 派生类不一定需要冲洗，所以这里不定义为纯虚函数
		}
	};
} // namespace base
