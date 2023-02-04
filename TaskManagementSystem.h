#pragma once
#include "Task.h"
#include "Manager.h"
#include <vector>

enum TaskManagementType
{
	Home,
	DisplayTaskList,
	AddTask,
	DisplayManagerList,
	AddManager,
};

class TaskManagementSystem
{
private:
	std::vector<Task> tasks;
	std::vector<Manager> managers;
	TaskManagementType taskManagementType;

public:
	TaskManagementSystem();
	void Update();

	void DisplayHome();
	void DisplayTaskList();
	void AddTask();
	void DisplayManagerList();
	void AddManager();
	void OutputTaskInfo(const unsigned int& index);
	void OutputManagerInfo(const unsigned int& index);

};

