#pragma once
#include <base/container/IList.h>
#include <base/pipe/IConsumer.h>
#include <memory>

namespace base
{
	template <typename T>
	class IPipeSource
	{
	public:
		virtual ~IPipeSource() = default;

		/// @brief 消费者列表
		/// @return
		virtual base::IList<std::shared_ptr<base::IConsumer<T>>> &ConsumerList() = 0;

		/// @brief 将数据送给每个消费者
		/// @param data
		void SendDataToEachConsumer(T data)
		{
			for (std::shared_ptr<base::IConsumer<T>> &consumer : ConsumerList())
			{
				if (consumer)
				{
					consumer->SendFrame(data);
				}
			}
		}

		/// @brief 冲洗每个消费者
		void FlushEachConsumer()
		{
			for (std::shared_ptr<base::IConsumer<T>> &consumer : ConsumerList())
			{
				if (consumer)
				{
					consumer->Flush();
				}
			}
		}
	};
} // namespace base
