#pragma once
#include<memory>

namespace base
{
	class RentedPtrFactory
	{
	public:
		/// <summary>
		///		利用传进来的裸指针构造一个共享指针。这个共享指针的删除器什么也不做，
		///		不会释放内存。
		/// 
		///		这么做是为了让一些例如静态变量或手动管理生命周期的变量能够被 shared_ptr
		///		套壳，从而兼容那些需要 shared_ptr 的 API。
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="o"></param>
		/// <returns></returns>
		template<typename T>
		static std::shared_ptr<T> Create(T *o)
		{
			std::shared_ptr<T> ret { o, [](T *o) { } };
			return ret;
		}
	};

	/// <summary>
	///		测试函数。测试函数的存在是为了在本库中就将泛型的 RentedPtrFactory::Create 方法
	///		给实例化，这样编译器和 inlinesenser 才能在有错的情况下检测出错误，否则 C++ 模板
	///		很难在没有被实例化的情况下检测错误。
	/// </summary>
	void TestRentedPtrFactory();
}
