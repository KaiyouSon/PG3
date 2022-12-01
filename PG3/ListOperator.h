#pragma once
#include "BidireList.h"
#include <string>

class ListOperator
{
private:
	BidireList<std::string> list;

	int manipulatElementsStep;	// �v�f����̃X�e�b�v
	int elementsDisplayStep;	// �v�f�̕\���̃X�e�b�v

private:
	void ElementsDisplay();
	void ElementsListDisplay();
	void ElementsOrderDesignationDisplay();
	void ElementsDisplayBack();

	void ElementsInsert();

	void ElementsEdit();

	void ElementsDelete();

public:
	void Update();
};

