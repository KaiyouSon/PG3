#include "Manager.h"
#include <iostream>

unsigned int Manager::idIndex = 1;

Manager::Manager() :id(idIndex)
{
	idIndex++;
}

void Manager::InputName()
{
	std::cout << "担当者の名前を入力してください" << std::endl;
	std::cin >> name;
}
void Manager::InputClassSign()
{
	int inputNumber = 0;

	std::cout << "クラス記号を選択してください" << std::endl;
	std::cout << "1.LD2B" << std::endl;
	std::cout << "2.LE2A" << std::endl;

	std::cin >> inputNumber;
	switch (inputNumber)
	{
	case 1:
		classSign = ClassSign::LD2B;
		break;
	case 2:
		classSign = ClassSign::LE2A;
		break;
	default:
		classSign = ClassSign::Unknown;
		break;
	}
}

void Manager::OutputID()
{
	std::cout << "[ID]" << std::endl;
	std::cout << id << std::endl;
}
void Manager::OutputName()
{
	std::cout << "[名前]" << std::endl;
	std::cout << name << std::endl;
}
void Manager::OutputClassSign()
{
	std::cout << "[クラス記号]" << std::endl;
	switch (classSign)
	{
	case ClassSign::LD2B:
		std::cout << "LD2B" << std::endl;
		break;
	case ClassSign::LE2A:
		std::cout << "LE2A" << std::endl;
		break;
	default:
		std::cout << "未選択" << std::endl;
		break;
	}
}

void Manager::OutputInfo()
{




}
