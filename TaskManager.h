#pragma once
#include "Task.h"
#include <vector>

class TaskManager
{
private:
	std::vector<Task> tasks;

public:
	void Update();

	void AddTask();
	void OutputTask(const unsigned int& index);

};

