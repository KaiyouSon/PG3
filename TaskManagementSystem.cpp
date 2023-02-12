#include "TaskManagementSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
	case TaskManagementType::SaveData:
		SaveData();
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
	std::cout << "5.�Z�[�u" << std::endl;

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
	case 5:
		taskManagementType = TaskManagementType::SaveData;
		break;
	default:
		break;
	}

	std::cout << std::endl;
}

void TaskManagementSystem::DisplayTaskList()
{
	int currentTaskIndex = 0;

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
		currentTaskIndex = inputNumber;
		OutputTaskInfo(inputNumber);
		std::cout << "0.�߂�" << std::endl;
		std::cout << "1.�ҏW" << std::endl;
		std::cout << "2.�폜" << std::endl;

		std::cin >> inputNumber;
		std::cout << std::endl;

		switch (inputNumber)
		{
		case 0:
			taskManagementType = TaskManagementType::DisplayTaskList;
			break;
		case 1:
			EditTask(currentTaskIndex - 1);
			break;
		case 2:
			DeleteTask(currentTaskIndex - 1);
			break;
		default:
			break;
		}
	}
}
void TaskManagementSystem::AddTask()
{
	Task task;
	task.InputTitle();
	task.InputContent();
	task.InputDeadline();

	int inputIndex = 0;
	do
	{
		std::cout << "�S����ID����͂��Ă�������" << std::endl;
		std::cout << "0.������" << std::endl;
		std::cin >> inputIndex;
		std::cout << std::endl;

		if (inputIndex == 0)
		{
			break;
		}
		else if (inputIndex <= managers.size())
		{
			break;
		}
		else
		{
			std::cout << "�Y������S����ID��������܂���ł����A�ēx���͂��Ă�������" << std::endl;
		}

	} while (true);
	if (managers.size() > 0)
	{
		task.InputManager(managers[inputIndex - 1]);
	}

	task.InputPriorityType();
	task.InputProgressType();

	tasks.emplace_back(task);

	std::cout << "�^�X�N���ǉ����܂���" << std::endl;
	taskManagementType = TaskManagementType::Home;

	std::cout << std::endl;
}
void TaskManagementSystem::EditTask(const int& taskIndex)
{
	int inputNumber;

	do
	{
		std::cout << "[�^�X�N�̕ҏW]" << std::endl;
		std::cout << "1.�薼" << std::endl;
		std::cout << "2.���e" << std::endl;
		std::cout << "3.����" << std::endl;
		std::cout << "4.�S����" << std::endl;
		std::cout << "5.�D��x" << std::endl;
		std::cout << "6.�i��" << std::endl;

		std::cin >> inputNumber;
		std::cout << std::endl;

		if (inputNumber >= 0 && inputNumber <= 6)
		{
			break;
		}

	} while (true);

	switch (inputNumber)
	{
	case 0:
		taskManagementType = TaskManagementType::Home;
		break;
	case 1:
		tasks[taskIndex].InputTitle();
		break;
	case 2:
		tasks[taskIndex].InputContent();
		break;
	case 3:
		tasks[taskIndex].InputDeadline();
		break;
	case 4:
	{
		int inputIndex = 0;
		do
		{
			std::cout << "�S����ID����͂��Ă�������" << std::endl;
			std::cout << "0.������" << std::endl;
			std::cin >> inputIndex;
			std::cout << std::endl;

			if (inputIndex == 0)
			{
				break;
			}
			else if (inputIndex <= managers.size())
			{
				break;
			}
			else
			{
				std::cout << "�Y������S����ID��������܂���ł����A�ēx���͂��Ă�������" << std::endl;
			}

		} while (true);
		if (managers.size() > 0)
		{
			tasks[taskIndex].InputManager(managers[inputIndex - 1]);
		}
	}

	break;
	case 5:
		tasks[taskIndex].InputPriorityType();
		break;
	case 6:
		tasks[taskIndex].InputProgressType();
		break;
	default:
		break;
	}
}
void TaskManagementSystem::DeleteTask(const int& taskIndex)
{
	tasks.erase(tasks.begin() + taskIndex);
}

void TaskManagementSystem::DisplayManagerList()
{
	int currentManagerIndex = 0;

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
		currentManagerIndex = inputNumber;
		OutputManagerInfo(inputNumber);
		std::cout << "0.�߂�" << std::endl;
		std::cout << "1.�ҏW" << std::endl;
		std::cout << "2.�폜" << std::endl;

		std::cin >> inputNumber;
		std::cout << std::endl;

		switch (inputNumber)
		{
		case 0:
			taskManagementType = TaskManagementType::DisplayTaskList;
			break;
		case 1:
			EditManager(currentManagerIndex);
			break;
		case 2:
			DeleteManager(currentManagerIndex);
			break;
		default:
			break;
		}
	}
}
void TaskManagementSystem::AddManager()
{
	Manager manager;
	manager.InputName();
	manager.InputClassSign();

	managers.emplace_back(manager);
	managers.back().SetID(managers.size());

	std::cout << "�S���҂��ǉ����܂���" << std::endl;
	taskManagementType = TaskManagementType::Home;

	std::cout << std::endl;
}
void TaskManagementSystem::EditManager(const int& managerIndex)
{
	int inputNumber;

	do
	{
		std::cout << "[�S���҂̕ҏW]" << std::endl;
		std::cout << "1.���O" << std::endl;
		std::cout << "2.�N���X�L��" << std::endl;

		std::cin >> inputNumber;
		std::cout << std::endl;

		if (inputNumber >= 0 && inputNumber <= 2)
		{
			break;
		}

	} while (true);

	switch (inputNumber)
	{
	case 0:
		taskManagementType = TaskManagementType::Home;
		break;
	case 1:
		managers[managerIndex - 1].InputName();
		break;
	case 2:
		managers[managerIndex - 1].InputClassSign();
		break;
	default:
		break;
	}
}
void TaskManagementSystem::DeleteManager(const int& managerIndex)
{
	managers.erase(managers.begin() + managerIndex);
}

void TaskManagementSystem::OutputTaskInfo(const unsigned int& index)
{
	std::cout << "[�^�X�N�̏ڍ�]" << std::endl;

	tasks[index - 1].OutputID();
	tasks[index - 1].OutputTitle();
	tasks[index - 1].OutputContent();
	tasks[index - 1].OutputDeadline();
	tasks[index - 1].OutputManager();
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
}

void TaskManagementSystem::LoadData()
{
	LoadManagerData();
	LoadTasksData();
}
void TaskManagementSystem::SaveData()
{
	SaveManagerData();
	SaveTasksData();

	std::cout << "�Z�[�u���������܂���" << std::endl;
	std::cout << std::endl;

	taskManagementType = TaskManagementType::Home;
}

void TaskManagementSystem::LoadTasksData()
{
	std::ifstream file;
	file.open("TaskData.txt");
	std::string line;
	int index = 0;
	while (std::getline(file, line))
	{
		// 1�s���̕�������X�g���[���ɕϊ����ĉ�͂��₷������
		std::istringstream lineStream(line);

		// ���p�X�y�[�X��؂�ōs�̐擪��������擾
		std::string key;
		std::getline(lineStream, key, ' ');

		if (key == "TasksSize")
		{
			int tasksSize = 0;
			lineStream >> tasksSize;
			tasks.resize(tasksSize);
		}

		if (key == "TaskTitle")
		{
			int taskTitle = 0;
			lineStream >> taskTitle;
			tasks[index].SetTaskTitle((TaskTitle)taskTitle);
			continue;
		}
		else if (key == "TaskContent")
		{
			std::string taskContent;
			lineStream >> taskContent;
			tasks[index].SetContent(taskContent);
			continue;
		}
		else if (key == "TaskDeadline")
		{
			std::string taskDeadline;
			lineStream >> taskDeadline;
			tasks[index].SetDeadline(taskDeadline);
		}
		else if (key == "TaskManagerID")
		{
			int taskManagerID;
			lineStream >> taskManagerID;
			if (taskManagerID < 0) continue;

			tasks[index].SetManager(managers[taskManagerID - 1]);
			continue;
		}
		else if (key == "TaskPriorityType")
		{
			int taskPriorityType = 0;
			lineStream >> taskPriorityType;
			tasks[index].SetPriorityType((PriorityType)taskPriorityType);
			continue;
		}
		else if (key == "TaskProgressType")
		{
			int taskProgressType = 0;
			lineStream >> taskProgressType;
			tasks[index].SetProgressType((ProgressType)taskProgressType);
			index++;

			continue;
		}
		else
		{
			continue;
		}
	}
	file.close();
}
void TaskManagementSystem::SaveTasksData()
{
	std::ofstream file;
	file.open("TaskData.txt", std::ios::out);

	file << "TasksSize " << tasks.size() << "\n\n";

	for (int i = 0; i < tasks.size(); i++)
	{
		file << "TaskTitle " << (int)tasks[i].GetTaskTitle() << "\n";
		file << "TaskContent " << tasks[i].GetContent() << "\n";
		file << "TaskDeadline " << tasks[i].GetDeadline() << "\n";
		file << "TaskManagerID " << tasks[i].GetManagerID() << "\n";
		file << "TaskPriorityType " << (int)tasks[i].GetPriorityType() << "\n";
		file << "TaskProgressType " << (int)tasks[i].GetProgressType() << "\n";
		file << "\n";
	}

	file.close();
}

void TaskManagementSystem::LoadManagerData()
{
	std::ifstream file;
	file.open("ManagerData.txt");
	std::string line;
	int index = 0;
	while (std::getline(file, line))
	{
		// 1�s���̕�������X�g���[���ɕϊ����ĉ�͂��₷������
		std::istringstream lineStream(line);

		// ���p�X�y�[�X��؂�ōs�̐擪��������擾
		std::string key;
		std::getline(lineStream, key, ' ');

		if (key == "ManagersSize")
		{
			int managersSize = 0;
			lineStream >> managersSize;
			managers.resize(managersSize);
		}

		if (key == "ManagerName")
		{
			managers[index].SetID(index + 1);

			std::string taskName;
			lineStream >> taskName;
			managers[index].SetName(taskName);
			continue;
		}
		else if (key == "ManagerClassSign")
		{
			int managerClassSign = 0;
			lineStream >> managerClassSign;
			managers[index].SetClassSign((ClassSign)managerClassSign);
			index++;
			continue;
		}
	}
	file.close();
}
void TaskManagementSystem::SaveManagerData()
{
	std::ofstream file;
	file.open("ManagerData.txt", std::ios::out);

	file << "ManagersSize " << managers.size() << "\n\n";

	for (int i = 0; i < managers.size(); i++)
	{
		file << "ManagerName " << managers[i].GetName() << "\n";
		file << "ManagerClassSign " << (int)managers[i].GetClassSign() << "\n";

		file << "\n";
	}

	file.close();
}