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

	std::cout << "題名を選択してください" << std::endl;
	std::cout << "1.バグ修正" << std::endl;
	std::cout << "2.仕様追加" << std::endl;

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
	std::cout << "内容を入力してください" << std::endl;
	std::cin >> content;
}
void Task::InputDeadline()
{
	std::cout << "期限を入力してください" << std::endl;
	std::cin >> content;
}
void Task::InputPriorityType()
{
	int inputNumber = 0;

	std::cout << "優先度を選択してください" << std::endl;
	std::cout << "1.高" << std::endl;
	std::cout << "2.中" << std::endl;
	std::cout << "3.低" << std::endl;

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

	std::cout << "進捗を選択してください" << std::endl;
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
	std::cout << "[題名]" << std::endl;
	switch (taskTitle)
	{
	case TaskTitle::Bug:
		std::cout << "バグ修正" << std::endl;
		break;
	case TaskTitle::Request:
		std::cout << "仕様変更" << std::endl;
		break;
	default:
		std::cout << "未選択" << std::endl;
		break;
	}
}
void Task::OutputContent()
{
	std::cout << "[内容]" << std::endl;
	std::cout << content << std::endl;
}
void Task::OutputDeadline()
{
	std::cout << "[期限]" << std::endl;
	std::cout << deadline << std::endl;
}
void Task::OutputPriorityType()
{
	std::cout << "[優先度]" << std::endl;
	switch (priorityType)
	{
	case PriorityType::High:
		std::cout << "高" << std::endl;
		break;
	case PriorityType::Middle:
		std::cout << "中" << std::endl;
		break;
	case PriorityType::Low:
		std::cout << "低" << std::endl;
		break;
	default:
		std::cout << "未選択" << std::endl;
		break;
	}
}
void Task::OutputProgressType()
{
	std::cout << "[進捗]" << std::endl;
	switch (progressType)
	{
	case ProgressType::NotStartedYet:
		std::cout << "未着手" << std::endl;
		break;
	case ProgressType::Fixed:
		std::cout << "修正中" << std::endl;
		break;
	case ProgressType::BeingFixed:
		std::cout << "修正済" << std::endl;
		break;
	default:
		std::cout << "未選択" << std::endl;
		break;
	}
}
