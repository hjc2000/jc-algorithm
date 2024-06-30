#pragma once

namespace base
{
	template <typename T>
	class ISource
	{
	public:
		virtual ~ISource() = default;

		/// @brief 从源中读取数据
		/// @param data 这里传入的是引用。派生类可以修改 data。
		/// @return 成功返回 0，失败返回负数的错误代码。
		virtual int ReadData(T &data) = 0;
	};
}
