#pragma once
#include "BidireList.h"

class ListOperator
{
private:
	BidireList<int> list;

	int manipulatElementsStep;	// 要素操作のステップ
	int elementsDisplayStep;	// 要素の表示のステップ

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

