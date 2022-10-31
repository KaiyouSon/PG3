#include <iostream>
#include "SingleList.h"

// 図書カード構造体
struct LibraryCard
{
	char name[256];
	int loanDate;
	int returnDate;
};

int main()
{
	SingleList<LibraryCard> libraryCardList;

	// 一個目のカード
	LibraryCard card{};
	std::cout << "名前" << std::endl;
	std::cin >> card.name;

	std::cout << "貸出日" << std::endl;
	std::cin >> card.loanDate;

	std::cout << "返却日" << std::endl;
	std::cin >> card.returnDate;
	libraryCardList.PushBack(card);

	std::cout << "------------------------" << std::endl;

	// リストのサイズ分のデータを出力する
	for (int i = 0; i < libraryCardList.GetSize(); i++)
	{
		std::cout << "名前  ：" << libraryCardList.GetNode(i).name << std::endl;
		std::cout << "貸出日：" << libraryCardList.GetNode(i).loanDate << std::endl;
		std::cout << "返却日：" << libraryCardList.GetNode(i).returnDate << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	return 0;
}