#include "TaskManager.h"
#include <iostream>

void TaskManager::Update()
{
	std::cout << "[タスク編集]" << std::endl;
	std::cout << "1.タスクの一覧表示" << std::endl;
	std::cout << "2.タスクの追加" << std::endl;

	std::cout << "[タスク一覧]" << std::endl;

	std::cout << "{" << std::endl;
	for (int i = 0; i < tasks.size(); i++)
	{
		std::cout << "タスクID:" << i << std::endl;
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
	std::cout << "[タスクの詳細]" << std::endl;

	tasks[index].OutputID();
	tasks[index].OutputTitle();
	tasks[index].OutputContent();
	tasks[index].OutputDeadline();
	tasks[index].OutputPriorityType();
	tasks[index].OutputProgressType();
}
