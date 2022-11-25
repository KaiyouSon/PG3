#include <iostream>
#include <stdio.h>
#include "BidireList.h"

enum ManipulatElements
{
	Display = 1,
	Insert,
	Edit,
	Delete,
};

void ElementsDisplay(BidireList<int>& list);

int main()
{
	BidireList<int> list;
	int number = 0;

	int manipulatElementsStep = 0;
	int elementsDisplayStep = 0;

	while (true)
	{
		std::cout << "[—v‘f‚Ì‘€ì]" << std::endl;
		std::cout << "1.—v‘f‚Ì•\Ž¦" << std::endl;
		std::cout << "2.—v‘f‚Ì‘}“ü" << std::endl;
		std::cout << "3.—v‘f‚Ì•ÒW" << std::endl;
		std::cout << "4.—v‘f‚Ìíœ" << std::endl;

		std::cin >> manipulatElementsStep;
		std::cout << std::endl;

		switch (manipulatElementsStep)
		{
		case Display:
			std::cout << "[—v‘f‚Ì•\Ž¦]" << std::endl;
			std::cout << "1.—v‘f‚Ìˆê——•\Ž¦" << std::endl;

			std::cin >> elementsDisplayStep;
			std::cout << std::endl;

			if (elementsDisplayStep == 1)
			{
				ElementsDisplay(list);
			}
		}
	}

	return 0;
}

void ElementsDisplay(BidireList<int>& list)
{
	std::cout << "[—v‘f‚Ìˆê——•\Ž¦]" << std::endl;
	std::cout << "—v‘f”: " << list.GetSize() << std::endl;

	std::cout << "—v‘fˆê——:{" << std::endl;
	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << i << ":" << list.GetData(i) << std::endl;
	}
	std::cout << "}" << std::endl;

	std::cout << "-----------------------------" << std::endl;
}
