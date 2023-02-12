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
	SaveData,
};

class TaskManagementSystem
{
private:
	std::vector<Task> tasks;
	std::vector<Manager> managers;
	TaskManagementType taskManagementType;

private:
	void DisplayHome();
	void DisplayTaskList();
	void AddTask();
	void EditTask(const int& taskIndex);
	void DeleteTask(const int& taskIndex);

	void DisplayManagerList();
	void AddManager();
	void EditManager(const int& managerIndex);
	void DeleteManager(const int& managerIndex);

	void OutputTaskInfo(const unsigned int& index);
	void OutputManagerInfo(const unsigned int& index);
	void SaveData();

	void SaveTasksData();
	void LoadTasksData();

	void SaveManagerData();
	void LoadManagerData();

public:
	TaskManagementSystem();
	void Update();

	void LoadData();

};

