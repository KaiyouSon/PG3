#include "TaskManagementSystem.h"
#include <vector>

int main()
{
	TaskManagementSystem taskManager;

	while (true)
	{
		taskManager.Update();
	}

	return 0;
}
