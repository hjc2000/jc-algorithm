#pragma once
#include <base/pipe/IPipeSource.h>
#include <base/task/CancellationToken.h>
#include <base/task/TaskCanceledException.h>

namespace base
{
	/// @brief
	/// @tparam T 必须是具有无参构造函数的类，实在不行可以用智能指针包装起来，
	/// 让 T 是一个智能指针。
	template <typename T>
	class ISource
	{
	public:
		virtual ~ISource() = default;

		/// @brief 从源中读取数据
		/// @param data 这里传入的是引用。派生类可以修改 data。
		/// @return 成功返回 0，失败返回负数的错误代码。
		virtual int ReadData(T &data) = 0;

		/// @brief 将数据泵送给消费者
		///
		/// @param consumer 消费者
		///
		/// @param cancellationToken 取消令牌
		/// @note 主动取消不会冲洗消费者。
		///
		/// @return 成功返回 0，失败返回负数的错误代码
		/// @note 此错误代码直接来自 ReadData。
		/// @note 调用本对象的 ReadData 方法读取数据，将数据送给消费者的过程中，如果遇到 ReadData
		/// 方法返回了负数，说明 数据源——本对象 发生了错误，可能是读取到文件尾，没有更多数据了，
		/// 或者其他错误。这时候会冲洗消费者，然后原封不动地返回 ReadData 方法所返回的错误代码。
		virtual int PumpTo(base::IConsumer<T> &consumer,
						   std::shared_ptr<base::CancellationToken> cancellationToken)
		{
			while (true)
			{
				if (cancellationToken->IsCancellationRequested())
				{
					throw base::TaskCanceledException{"PumpTo 函数被取消。"};
				}

				T data{};
				int ret = ReadData(data);
				if (ret < 0)
				{
					consumer.Flush();
					return ret;
				}

				consumer.SendData(data);
			}
		}
	};
}
