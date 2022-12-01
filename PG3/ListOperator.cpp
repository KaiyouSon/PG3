#include "ListOperator.h"
#include <iostream>

enum ElementsManipulatStep
{
	Default,
	Display,
	Insert,
	Edit,
	Delete,
};

void ListOperator::Update()
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
		if (std::cin.fail())
		{
			std::cout << "���̓G���[\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
		//std::cout << std::endl;
		break;

	case Display:
		ElementsDisplay();
		break;

	case Insert:
		ElementsInsert();
		break;

	case Edit:
		ElementsEdit();
		break;

	case Delete:
		ElementsDelete();
		break;

	default:
		std::cout << "���̓G���[\n" << std::endl;
		manipulatElementsStep = Default;
		break;
	}
}

// �v�f�̕\��
void ListOperator::ElementsDisplay()
{
	enum ElementsDisplayOption
	{
		Default,
		ListDisplay,				// �ꗗ�\��
		OrderDesignationDisplay,	// ���Ԏw��\��
		BackToManipulatElements = 9,// �v�f����ɖ߂�
	};

	switch (elementsDisplayStep)
	{
	case Default:	// �v�f�̕\���i�f�t�H���g���j���[�j
		std::cout << "[�v�f�̕\��]" << std::endl;
		std::cout << "1.�v�f�̈ꗗ�\��" << std::endl;
		std::cout << "2.���Ԃ��w�肵�ėv�f�̕\��" << std::endl;

		std::cin >> elementsDisplayStep;
		if (std::cin.fail())
		{
			std::cout << "���̓G���[\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}

		std::cout << std::endl;
		break;

	case ListDisplay:	// �ꗗ�\��
		ElementsListDisplay();
		break;

	case OrderDesignationDisplay:	// ���Ԏw��\��
		ElementsOrderDesignationDisplay();
		break;

	default:
		std::cout << "���̓G���[\n" << std::endl;
		elementsDisplayStep = Default;
		break;
	}
}
// �v�f�̈ꗗ�\��
void ListOperator::ElementsListDisplay()
{
	std::cout << "[�v�f�̈ꗗ�\��]" << std::endl;
	std::cout << "�v�f��: " << list.GetSize() << std::endl;

	std::cout << "�v�f�ꗗ:{" << std::endl;
	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << i << ":" << list.GetData(i) << std::endl;
	}
	std::cout << "}" << std::endl;

	std::cout << "\n-----------------------------" << std::endl;

	// �߂鏈��
	ElementsDisplayBack();
}
// ���Ԃ��w�肵�ėv�f�̕\��
void ListOperator::ElementsOrderDesignationDisplay()
{
	std::cout << "[���Ԃ��w�肵�ėv�f��\��]" << std::endl;
	std::cout << "�\���������v�f�̏��Ԃ��w�肵�Ă��������B" << std::endl;

	int index = 0;
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cout << "���̓G���[\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(1024, '\n');
	}

	if (index > list.GetSize())
	{
		std::cout << "�w�肵�����Ԃɗv�f������܂���ł����B" << std::endl;
	}
	else
	{
		std::cout << index << ":" << list.GetData(index) << std::endl;
	}

	std::cout << "\n-----------------------------" << std::endl;

	// �߂鏈��
	ElementsDisplayBack();
}
// �v�f�̕\�����ł̖߂鏈��
void ListOperator::ElementsDisplayBack()
{
	enum Option
	{
		BackToDisplay = 1,	// �v�f�̕\���ɖ߂�
		BackToManipulat,	// �v�f�̑���ɖ߂�
	};

	int optionNum = 0;
	std::cout << "1.�v�f�̕\���ɖ߂�" << std::endl;
	std::cout << "2.�v�f�̑���ɖ߂�" << std::endl;

	std::cin >> optionNum;
	std::cout << std::endl;
	if (std::cin.fail())
	{
		std::cout << "���̓G���[\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(1024, '\n');
	}

	switch (optionNum)
	{
	case BackToDisplay:
		elementsDisplayStep = 0;
		break;
	case BackToManipulat:
		elementsDisplayStep = 0;
		manipulatElementsStep = Default;
		break;
	default:
		optionNum = BackToDisplay;
		std::cout << "���̓G���[\n" << std::endl;
		break;
	}
}

// �v�f�̑}��
void ListOperator::ElementsInsert()
{
	std::cout << "[���X�g�̗v�f�̑}��]" << std::endl;
	std::cout << "�v�f��ǉ�����ꏊ���w�肵�Ă����������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł�������" << std::endl;

	std::string str;
	std::cin.ignore(1024, '\n');
	std::getline(std::cin, str);

	int index = atoi(str.c_str());

	if (std::cin.fail())
	{
		std::cout << "���̓G���[\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(1024, '\n');
	}

	std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;

	std::string data;
	std::cin >> data;

	list.Insert(data, index);
	if (index > list.GetSize())
	{
		std::cout << "�v�f" << data << "��" << list.GetSize() - 1 << "�Ԗڂɑ}������܂���" << std::endl;
	}
	else
	{
		std::cout << "�v�f" << data << "��" << index << "�Ԗڂɑ}������܂���" << std::endl;
	}

	std::cout << std::endl;
	manipulatElementsStep = Default;
}

// �v�f�̕ҏW
void ListOperator::ElementsEdit()
{
	std::cout << "[�v�f�̕ҏW]" << std::endl;
	std::cout << "�ҏW�������v�f�̔ԍ����w�肵�Ă��������B" << std::endl;

	int index = 0;
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cout << "���̓G���[\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(1024, '\n');
	}

	if (index < list.GetSize())
	{
		std::cout << index << "�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B" << std::endl;

		std::string data;
		std::cin >> data;
		list.Change(data, index);

		std::cout << index << "�Ԗڂ̗v�f�̒l��" << data << "�ɕύX����܂����B" << std::endl;
	}
	else
	{
		std::cout << index << "�Ԗڂ̗v�f�̒l��������܂���ł����B" << std::endl;
	}

	std::cout << std::endl;
	manipulatElementsStep = Default;
}

// �v�f�̍폜
void ListOperator::ElementsDelete()
{
	std::cout << "[�v�f�̍폜]" << std::endl;
	std::cout << "�폜�������v�f�̔ԍ����w�肵�Ă��������B" << std::endl;

	int index = 0;
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cout << "���̓G���[\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(1024, '\n');
	}

	if (index < list.GetSize())
	{
		std::string data = list.GetData(index);
		std::cout << index << "�Ԗڂ̗v�f" << data << "���폜���܂����B" << std::endl;
		list.Erase(index);
	}
	else
	{
		std::cout << index << "�Ԗڂ̗v�f�̒l��������܂���ł����B" << std::endl;
	}

	std::cout << std::endl;
	manipulatElementsStep = Default;
}