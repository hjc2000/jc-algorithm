#include"RentedPtrFactory.h"

using namespace base;

void base::TestRentedPtrFactory()
{
	int *p = new int { 0 };
	std::shared_ptr<int> rented_sp = RentedPtrFactory::Create(p);
	delete p;
}
