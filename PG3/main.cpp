#include <iostream>
#include "BidirectionalList.h"

int main()
{
	BidireList<int> list;

	list.PushBack(0);
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);

	list.PushFront(-1);
	list.PushFront(-2);

	std::cout << "------------------------" << std::endl;

	// リストのサイズ分のデータを出力する
	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << list.GetNode(i) << std::endl;
	}

	return 0;
}