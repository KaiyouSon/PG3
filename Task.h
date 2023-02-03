#pragma once
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
	//Manager manager;
	TaskTitle taskTitle = TaskTitle::Unknown;
	std::string content = "������";
	std::string deadline = "������";
	PriorityType priorityType = PriorityType::Unknown;	// �D��x
	ProgressType progressType = ProgressType::Unknown;	// �i��

public:
	static unsigned int idIndex;

public:
	Task();

public:
	// ���͊֐�
	void InputTitle();
	void InputContent();
	void InputDeadline();
	void InputPriorityType();
	void InputProgressType();

public:
	// �o�͊֐�
	void OutputID();
	void OutputTitle();
	void OutputContent();
	void OutputDeadline();
	void OutputPriorityType();
	void OutputProgressType();
};

