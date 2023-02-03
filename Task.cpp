#include "Task.h"
#include <iostream>
unsigned int Task::idIndex = 0;

Task::Task()
{
	id = idIndex;
	idIndex++;
}

void Task::InputTitle()
{
	int inputNumber = 0;

	std::cout << "�薼��I�����Ă�������" << std::endl;
	std::cout << "1.�o�O�C��" << std::endl;
	std::cout << "2.�d�l�ǉ�" << std::endl;

	std::cin >> inputNumber;
	switch (inputNumber)
	{
	case 1:
		taskTitle = TaskTitle::Bug;
		break;
	case 2:
		taskTitle = TaskTitle::Request;
		break;
	default:
		taskTitle = TaskTitle::Unknown;
		break;
	}
}
void Task::InputContent()
{
	std::cout << "���e����͂��Ă�������" << std::endl;
	std::cin >> content;
}
void Task::InputDeadline()
{
	std::cout << "��������͂��Ă�������" << std::endl;
	std::cin >> content;
}
void Task::InputPriorityType()
{
	int inputNumber = 0;

	std::cout << "�D��x��I�����Ă�������" << std::endl;
	std::cout << "1.��" << std::endl;
	std::cout << "2.��" << std::endl;
	std::cout << "3.��" << std::endl;

	std::cin >> inputNumber;
	switch (inputNumber)
	{
	case 1:
		priorityType = PriorityType::High;
		break;
	case 2:
		priorityType = PriorityType::Middle;
		break;
	case 3:
		priorityType = PriorityType::Low;
		break;
	default:
		taskTitle = TaskTitle::Unknown;
		break;
	}
}
void Task::InputProgressType()
{
	int inputNumber = 0;

	std::cout << "�i����I�����Ă�������" << std::endl;
	std::cin >> inputNumber;
	switch (inputNumber)
	{
	case 1:
		progressType = ProgressType::NotStartedYet;
		break;
	case 2:
		progressType = ProgressType::BeingFixed;
		break;
	case 3:
		progressType = ProgressType::Fixed;
		break;
	default:
		progressType = ProgressType::Unknown;
		break;
	}
}

void Task::OutputID()
{
	std::cout << "[ID]" << std::endl;
	std::cout << id << std::endl;
}
void Task::OutputTitle()
{
	std::cout << "[�薼]" << std::endl;
	switch (taskTitle)
	{
	case TaskTitle::Bug:
		std::cout << "�o�O�C��" << std::endl;
		break;
	case TaskTitle::Request:
		std::cout << "�d�l�ύX" << std::endl;
		break;
	default:
		std::cout << "���I��" << std::endl;
		break;
	}
}
void Task::OutputContent()
{
	std::cout << "[���e]" << std::endl;
	std::cout << content << std::endl;
}
void Task::OutputDeadline()
{
	std::cout << "[����]" << std::endl;
	std::cout << deadline << std::endl;
}
void Task::OutputPriorityType()
{
	std::cout << "[�D��x]" << std::endl;
	switch (priorityType)
	{
	case PriorityType::High:
		std::cout << "��" << std::endl;
		break;
	case PriorityType::Middle:
		std::cout << "��" << std::endl;
		break;
	case PriorityType::Low:
		std::cout << "��" << std::endl;
		break;
	default:
		std::cout << "���I��" << std::endl;
		break;
	}
}
void Task::OutputProgressType()
{
	std::cout << "[�i��]" << std::endl;
	switch (progressType)
	{
	case ProgressType::NotStartedYet:
		std::cout << "������" << std::endl;
		break;
	case ProgressType::Fixed:
		std::cout << "�C����" << std::endl;
		break;
	case ProgressType::BeingFixed:
		std::cout << "�C����" << std::endl;
		break;
	default:
		std::cout << "���I��" << std::endl;
		break;
	}
}
