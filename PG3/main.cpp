#include <iostream>
#include "SingleList.h"

// �}���J�[�h�\����
struct LibraryCard
{
	char name[256];
	int loanDate;
	int returnDate;
};

int main()
{
	SingleList<LibraryCard> libraryCardList;

	// ��ڂ̃J�[�h
	LibraryCard card{};
	std::cout << "���O" << std::endl;
	std::cin >> card.name;

	std::cout << "�ݏo��" << std::endl;
	std::cin >> card.loanDate;

	std::cout << "�ԋp��" << std::endl;
	std::cin >> card.returnDate;
	libraryCardList.PushBack(card);

	std::cout << "------------------------" << std::endl;

	// ���X�g�̃T�C�Y���̃f�[�^���o�͂���
	for (int i = 0; i < libraryCardList.GetSize(); i++)
	{
		std::cout << "���O  �F" << libraryCardList.GetNode(i).name << std::endl;
		std::cout << "�ݏo���F" << libraryCardList.GetNode(i).loanDate << std::endl;
		std::cout << "�ԋp���F" << libraryCardList.GetNode(i).returnDate << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	return 0;
}