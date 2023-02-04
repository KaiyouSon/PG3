#pragma once
#include <string>

enum class ClassSign
{
	LD2B,
	LE2A,
	Unknown,
};

class Manager
{
private:
	int id;
	std::string name = "–¢‹L“ü";
	ClassSign classSign = ClassSign::LE2A;

public:
	static unsigned int idIndex;

public:
	Manager();
	void InputName();
	void InputClassSign();

	void OutputID();
	void OutputName();
	void OutputClassSign();
	void OutputInfo();
};

