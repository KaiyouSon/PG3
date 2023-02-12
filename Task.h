#pragma once
#include "Manager.h"
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
	TaskTitle taskTitle = TaskTitle::Unknown;
	std::string content = "未入力";
	std::string deadline = "未入力";
	Manager manager;
	PriorityType priorityType = PriorityType::Unknown;	// 優先度
	ProgressType progressType = ProgressType::Unknown;	// 進捗

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
	// 入力関数
	void InputTitle();
	void InputContent();
	void InputDeadline();
	void InputManager(const Manager& manager);
	void InputPriorityType();
	void InputProgressType();

public:
	// 出力関数
	void OutputID();
	void OutputTitle();
	void OutputContent();
	void OutputDeadline();
	void OutputManager();
	void OutputPriorityType();
	void OutputProgressType();
};

