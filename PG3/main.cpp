#include <iostream>
#include <memory>
#include "ListOperator.h"
#include "BidireList.h"

int main()
{
	//int index;

	//while (1)
	//{
	//	//std::cout << "整数値を入力してください。" << std::endl;
	//	//std::cin >> index;

	//	//if (std::cin.fail())
	//	//{
	//	//	std::cout << "入力エラー！\n" << std::endl;
	//	//	std::cin.clear();
	//	//	std::cin.ignore(1024, '\n');
	//	//}

	//	std::cout << "[要素の編集]" << std::endl;
	//	std::cout << "編集したい要素の番号を指定してください。" << std::endl;

	//	int index = 0;
	//	std::cin >> index;
	//	if (std::cin.fail())
	//	{
	//		std::cout << "入力エラー！\n" << std::endl;
	//		std::cin.clear();
	//		std::cin.ignore(1024, '\n');
	//	}
	//}

	//std::cin.ignore(1024, '\n');


	std::unique_ptr<ListOperator> listOperator =
		std::move(std::make_unique<ListOperator>());

	while (true)
	{
		listOperator->Update();
	}

	return 0;
}