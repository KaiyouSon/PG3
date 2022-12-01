#include <iostream>
#include <memory>
#include "ListOperator.h"
#include "BidireList.h"

int main()
{
	/*BidireList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);

	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << list.GetData(i) << std::endl;
	}

	list.Change(5, 3);
	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << list.GetData(i) << std::endl;
	}*/

	std::unique_ptr<ListOperator> listOperator =
		std::move(std::make_unique<ListOperator>());

	while (true)
	{
		listOperator->Update();
	}

	return 0;
}