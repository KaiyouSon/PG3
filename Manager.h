#pragma once
#include <string>

enum class ClassSign
{
	LD2B,
	LE2A,
	LE2B,
	Unknown,
};

class Manager
{
private:
	int id = -1;
	std::string name = "–¢‹L“ü";
	ClassSign classSign = ClassSign::LE2A;

public:
	Manager();
	void InputName();
	void InputClassSign();

	void OutputID();
	void OutputName();
	void OutputClassSign();

	void SetID(const int& id) { this->id = id; }
	int GetID() { return id; }

	inline std::string GetName() { return name; }
	inline ClassSign GetClassSign() { return classSign; }

	inline void SetName(const std::string& name) { this->name = name; }
	inline void SetClassSign(const ClassSign& name) { this->classSign = classSign; }

};

