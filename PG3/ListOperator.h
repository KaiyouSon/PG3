#pragma once
#include "BidireList.h"

class ListOperator
{
private:
	BidireList<int> list;

	int manipulatElementsStep;	// �v�f����̃X�e�b�v
	int elementsDisplayStep;	// �v�f�̕\���̃X�e�b�v

private:
	void ElementsDisplay();
	void ElementsListDisplay();
	void ElementsOrderDesignationDisplay();
	void ElementsDisplayBack();

	void ElementsInsert();

	void ElementsEdit();

public:
	void Update();
};

