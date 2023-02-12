#pragma once
#include "Manager.h"
#include <string>

// �^�X�N�̃^�C�g��
enum class TaskTitle
{
	Bug,		// �o�O�C��
	Request,	// �d�l�ǉ�
	Unknown = -1,
};

// �D��x
enum class PriorityType
{
	High,
	Middle,
	Low,
	Unknown = -1,
};

// �i��
enum class ProgressType
{
	NotStartedYet,	// ������
	BeingFixed,		// �C����
	Fixed,			// �C���ς�
	Unknown = -1,
};


class Task
{
private:
	int id;
	TaskTitle taskTitle = TaskTitle::Unknown;
	std::string content = "������";
	std::string deadline = "������";
	Manager manager;
	PriorityType priorityType = PriorityType::Unknown;	// �D��x
	ProgressType progressType = ProgressType::Unknown;	// �i��

public:
	static unsigned int idIndex;

public:
	Task();

public:
	inline TaskTitle GetTaskTitle() { return taskTitle; }
	inline std::string GetContent() { return content; }
	inline std::string GetDeadline() { return deadline; }
	inline int GetManagerID() { return manager.GetID(); }
	inline PriorityType GetPriorityType() { return priorityType; }
	inline ProgressType GetProgressType() { return progressType; }

	inline void SetTaskTitle(const TaskTitle taskTitle) { this->taskTitle = taskTitle; }
	inline void SetContent(const std::string content) { this->content = content; }
	inline void SetDeadline(const std::string deadline) { this->deadline = deadline; }
	inline void SetManager(const Manager& manager) { this->manager = manager; }
	inline void SetPriorityType(const PriorityType& priorityType) { this->priorityType = priorityType; }
	inline void SetProgressType(const ProgressType& progressType) { this->progressType = progressType; }

public:
	// ���͊֐�
	void InputTitle();
	void InputContent();
	void InputDeadline();
	void InputManager(const Manager& manager);
	void InputPriorityType();
	void InputProgressType();

public:
	// �o�͊֐�
	void OutputID();
	void OutputTitle();
	void OutputContent();
	void OutputDeadline();
	void OutputManager();
	void OutputPriorityType();
	void OutputProgressType();
};

