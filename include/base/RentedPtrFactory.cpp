#include"RentedPtrFactory.h"

using namespace base;

/// <summary>
///		测试函数。测试函数的存在是为了在本库中就将泛型的 RentedPtrFactory::Create 方法
///		给实例化，这样编译器和 inlinesenser 才能在有错的情况下检测出错误，否则 C++ 模板
///		很难在没有被实例化的情况下检测错误。
/// </summary>
void TestRentedPtrFactory()
{
	int *p = new int { 0 };
	std::shared_ptr<int> rented_sp = RentedPtrFactory::Create(p);
	delete p;
}
