#include "TaskManagementSystem.h"
#include <vector>

int main()
{
	TaskManagementSystem taskManager;
	taskManager.LoadData();

	while (true)
	{
		taskManager.Update();
	}

	return 0;
}
