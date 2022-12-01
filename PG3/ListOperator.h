#pragma once
#include "BidireList.h"
#include <string>

class ListOperator
{
private:
	BidireList<std::string> list;

	int manipulatElementsStep;	// 要素操作のステップ
	int elementsDisplayStep;	// 要素の表示のステップ

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

