#include "TaskManager.h"
#include <iostream>

void TaskManager::Update()
{
	std::cout << "[�^�X�N�ҏW]" << std::endl;
	std::cout << "1.�^�X�N�̈ꗗ�\��" << std::endl;
	std::cout << "2.�^�X�N�̒ǉ�" << std::endl;

	std::cout << "[�^�X�N�ꗗ]" << std::endl;

	std::cout << "{" << std::endl;
	for (int i = 0; i < tasks.size(); i++)
	{
		std::cout << "�^�X�NID:" << i << std::endl;
	}
	std::cout << "}" << std::endl;

	int inputNumber;
	std::cin >> inputNumber;
	std::cout << std::endl;

	OutputTask(inputNumber);
}

void TaskManager::AddTask()
{
	Task task;
	task.InputTitle();
	task.InputContent();
	task.InputDeadline();
	task.InputPriorityType();

	tasks.emplace_back(task);

	std::cout << std::endl;
}

void TaskManager::OutputTask(const unsigned int& index)
{
	std::cout << "[�^�X�N�̏ڍ�]" << std::endl;

	tasks[index].OutputID();
	tasks[index].OutputTitle();
	tasks[index].OutputContent();
	tasks[index].OutputDeadline();
	tasks[index].OutputPriorityType();
	tasks[index].OutputProgressType();
}
