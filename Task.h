#pragma once
#include <string>

// タスクのタイトル
enum class TaskTitle
{
	Bug,		// バグ修正
	Request,	// 仕様追加
	Unknown = -1,
};

// 優先度
enum class PriorityType
{
	High,
	Middle,
	Low,
	Unknown = -1,
};

// 進捗
enum class ProgressType
{
	NotStartedYet,	// 未着手
	BeingFixed,		// 修正中
	Fixed,			// 修正済み
	Unknown = -1,
};


class Task
{
private:
	int id;
	//Manager manager;
	TaskTitle taskTitle = TaskTitle::Unknown;
	std::string content = "未入力";
	std::string deadline = "未入力";
	PriorityType priorityType = PriorityType::Unknown;	// 優先度
	ProgressType progressType = ProgressType::Unknown;	// 進捗

public:
	static unsigned int idIndex;

public:
	Task();

public:
	// 入力関数
	void InputTitle();
	void InputContent();
	void InputDeadline();
	void InputPriorityType();
	void InputProgressType();

public:
	// 出力関数
	void OutputID();
	void OutputTitle();
	void OutputContent();
	void OutputDeadline();
	void OutputPriorityType();
	void OutputProgressType();
};

