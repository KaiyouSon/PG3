#include <iostream>
#include <memory>
#include "ListOperator.h"
#include "BidireList.h"

int main()
{
	//int index;

	//while (1)
	//{
	//	//std::cout << "�����l����͂��Ă��������B" << std::endl;
	//	//std::cin >> index;

	//	//if (std::cin.fail())
	//	//{
	//	//	std::cout << "���̓G���[�I\n" << std::endl;
	//	//	std::cin.clear();
	//	//	std::cin.ignore(1024, '\n');
	//	//}

	//	std::cout << "[�v�f�̕ҏW]" << std::endl;
	//	std::cout << "�ҏW�������v�f�̔ԍ����w�肵�Ă��������B" << std::endl;

	//	int index = 0;
	//	std::cin >> index;
	//	if (std::cin.fail())
	//	{
	//		std::cout << "���̓G���[�I\n" << std::endl;
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