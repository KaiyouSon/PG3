#include "TaskManagementSystem.h"
#include <iostream>

TaskManagementSystem::TaskManagementSystem() :
	taskManagementType(TaskManagementType::Home)
{
}

void TaskManagementSystem::Update()
{
	switch (taskManagementType)
	{
	case TaskManagementType::Home:
		DisplayHome();
		break;
	case TaskManagementType::DisplayTaskList:
		DisplayTaskList();
		break;
	case TaskManagementType::AddTask:
		AddTask();
		break;
	case TaskManagementType::DisplayManagerList:
		DisplayManagerList();
		break;
	case TaskManagementType::AddManager:
		AddManager();
		break;

	default:
		break;
	}
}

void TaskManagementSystem::DisplayHome()
{
	std::cout << "[�^�X�N�Ǘ��V�X�e��]" << std::endl;
	std::cout << "1.�^�X�N�̈ꗗ�\��" << std::endl;
	std::cout << "2.�^�X�N�̒ǉ�" << std::endl;
	std::cout << "3.�S���҂̈ꗗ�\��" << std::endl;
	std::cout << "4.�S���҂̒ǉ�" << std::endl;

	int inputNumber;
	std::cin >> inputNumber;

	switch (inputNumber)
	{
	case 1:
		taskManagementType = TaskManagementType::DisplayTaskList;
		break;
	case 2:
		taskManagementType = TaskManagementType::AddTask;
		break;
	case 3:
		taskManagementType = TaskManagementType::DisplayManagerList;
		break;
	case 4:
		taskManagementType = TaskManagementType::AddManager;
		break;
	default:
		break;
	}

	std::cout << std::endl;
}
void TaskManagementSystem::DisplayTaskList()
{
	std::cout << "[�^�X�N�ꗗ]" << std::endl;

	std::cout << "{" << std::endl;
	for (int i = 0; i < tasks.size(); i++)
	{
		std::cout << "�^�X�NID:" << i + 1 << std::endl;
	}
	std::cout << "}" << std::endl;

	std::cout << "0.�߂�" << std::endl;

	int inputNumber;
	std::cin >> inputNumber;
	std::cout << std::endl;

	if (inputNumber == 0)
	{
		taskManagementType = TaskManagementType::Home;
	}
	else
	{
		OutputTaskInfo(inputNumber);
	}
}
void TaskManagementSystem::AddTask()
{
	Task task;
	task.InputTitle();
	task.InputContent();
	task.InputDeadline();
	task.InputPriorityType();

	tasks.emplace_back(task);

	std::cout << "�^�X�N���ǉ����܂���" << std::endl;
	taskManagementType = TaskManagementType::Home;

	std::cout << std::endl;
}
void TaskManagementSystem::DisplayManagerList()
{
	std::cout << "[�S���҈ꗗ]" << std::endl;

	std::cout << "{" << std::endl;
	for (int i = 0; i < managers.size(); i++)
	{
		std::cout << "�S����ID:" << i + 1 << std::endl;
	}
	std::cout << "}" << std::endl;

	std::cout << "0.�߂�" << std::endl;

	int inputNumber;
	std::cin >> inputNumber;
	std::cout << std::endl;

	if (inputNumber == 0)
	{
		taskManagementType = TaskManagementType::Home;
	}
	else
	{
		OutputManagerInfo(inputNumber);
	}
}
void TaskManagementSystem::AddManager()
{
	Manager manager;
	manager.InputName();
	manager.InputClassSign();

	managers.emplace_back(manager);

	std::cout << "�S���҂��ǉ����܂���" << std::endl;
	taskManagementType = TaskManagementType::Home;

	std::cout << std::endl;
}

void TaskManagementSystem::OutputTaskInfo(const unsigned int& index)
{
	std::cout << "[�^�X�N�̏ڍ�]" << std::endl;

	tasks[index - 1].OutputID();
	tasks[index - 1].OutputTitle();
	tasks[index - 1].OutputContent();
	tasks[index - 1].OutputDeadline();
	tasks[index - 1].OutputPriorityType();
	tasks[index - 1].OutputProgressType();

	std::cout << std::endl;
}
void TaskManagementSystem::OutputManagerInfo(const unsigned int& index)
{
	std::cout << "[�S���҂̏ڍ�]" << std::endl;

	managers[index - 1].OutputID();
	managers[index - 1].OutputName();
	managers[index - 1].OutputClassSign();

	std::cout << std::endl;

	std::cout << "1.�S���҂̈ꗗ�\��" << std::endl;
	std::cout << "2.�z�[���ɖ߂�" << std::endl;

	int inputNumber;
	std::cin >> inputNumber;
	std::cout << std::endl;

	switch (inputNumber)
	{
	case 1:
		taskManagementType = TaskManagementType::DisplayManagerList;
		break;
	case 2:
		taskManagementType = TaskManagementType::Home;
		break;
	default:
		break;
	}

}
