#include <iostream>
#include <stdio.h>
#include "BidireList.h"

enum ElementsManipulatStep
{
	Default,
	Display,
	Insert,
	Edit,
	Delete,
};

void ElementsManipulat();
void ElementsDisplay(BidireList<int>& list);

int manipulatElementsStep = 0;
int elementsDisplayStep = 0;

int main()
{
	BidireList<int> list;
	int number = 0;

	while (true)
	{
		switch (manipulatElementsStep)
		{
		case Default:
			std::cout << "[�v�f�̑���]" << std::endl;
			std::cout << "1.�v�f�̕\��" << std::endl;
			std::cout << "2.�v�f�̑}��" << std::endl;
			std::cout << "3.�v�f�̕ҏW" << std::endl;
			std::cout << "4.�v�f�̍폜" << std::endl;

			std::cin >> manipulatElementsStep;
			std::cout << std::endl;

			break;

		case Display:

			if (elementsDisplayStep == 0)
			{
				std::cout << "[�v�f�̕\��]" << std::endl;
				std::cout << "1.�v�f�̈ꗗ�\��" << std::endl;

				std::cin >> elementsDisplayStep;
				std::cout << std::endl;
			}

			if (elementsDisplayStep == 1)
			{
				ElementsDisplay(list);
			}

			break;
		}
	}

	return 0;
}

void ElementsManipulat()
{
}

void ElementsDisplay(BidireList<int>& list)
{

	std::cout << "[�v�f�̈ꗗ�\��]" << std::endl;
	std::cout << "�v�f��: " << list.GetSize() << std::endl;

	std::cout << "�v�f�ꗗ:{" << std::endl;
	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << i << ":" << list.GetData(i) << std::endl;
	}
	std::cout << "}" << std::endl;

	std::cout << "-----------------------------" << std::endl;

	int step = 0;
	std::cout << "1.�v�f�̕\���ɖ߂�" << std::endl;
	std::cout << "2.�v�f�̑���ɖ߂�" << std::endl;

	std::cin >> step;
	std::cout << std::endl;

	switch (step)
	{
	case 1:
		elementsDisplayStep = 0;
		break;
	case 2:
		elementsDisplayStep = 0;
		manipulatElementsStep = Default;
		break;
	default:
		break;
	}
}
