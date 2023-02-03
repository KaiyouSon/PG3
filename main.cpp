#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "TaskManager.h"

enum class ClassSign
{
	LD2B,
	LE2A,
};

class Manager
{
	int id;
	std::string name;
	ClassSign classSign;
};


int main()
{
	TaskManager taskManager;

	taskManager.AddTask();

	taskManager.Update();


	return 0;
}
