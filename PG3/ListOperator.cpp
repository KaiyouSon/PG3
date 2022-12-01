#include "ListOperator.h"
#include <iostream>

enum ElementsManipulatStep
{
	Default,
	Display,
	Insert,
	Edit,
	Delete,
};

void ListOperator::Update()
{
	switch (manipulatElementsStep)
	{
	case Default:
		std::cout << "[要素の操作]" << std::endl;
		std::cout << "1.要素の表示" << std::endl;
		std::cout << "2.要素の挿入" << std::endl;
		std::cout << "3.要素の編集" << std::endl;
		std::cout << "4.要素の削除" << std::endl;

		std::cin >> manipulatElementsStep;
		//std::cout << std::endl;
		break;

	case Display:
		ElementsDisplay();
		break;

	case Insert:
		ElementsInsert();
		break;

	case Edit:
		ElementsEdit();
		break;

	}
}

// 要素の表示
void ListOperator::ElementsDisplay()
{
	enum ElementsDisplayOption
	{
		Default,
		ListDisplay,				// 一覧表示
		OrderDesignationDisplay,	// 順番指定表示
		BackToManipulatElements = 9,// 要素操作に戻る
	};

	switch (elementsDisplayStep)
	{
	case Default:	// 要素の表示（デフォルトメニュー）
		std::cout << "[要素の表示]" << std::endl;
		std::cout << "1.要素の一覧表示" << std::endl;
		std::cout << "2.順番を指定して要素の表示" << std::endl;

		std::cin >> elementsDisplayStep;
		std::cout << std::endl;
		break;

	case ListDisplay:	// 一覧表示
		ElementsListDisplay();
		break;

	case OrderDesignationDisplay:	// 順番指定表示
		ElementsOrderDesignationDisplay();
		break;
	default:
		break;
	}
}
// 要素の一覧表示
void ListOperator::ElementsListDisplay()
{
	std::cout << "[要素の一覧表示]" << std::endl;
	std::cout << "要素数: " << list.GetSize() << std::endl;

	std::cout << "要素一覧:{" << std::endl;
	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << i << ":" << list.GetData(i) << std::endl;
	}
	std::cout << "}" << std::endl;

	std::cout << "\n-----------------------------" << std::endl;

	// 戻る処理
	ElementsDisplayBack();
}
// 順番を指定して要素の表示
void ListOperator::ElementsOrderDesignationDisplay()
{
	std::cout << "[順番を指定して要素を表示]" << std::endl;
	std::cout << "表示したい要素の順番を指定してください。" << std::endl;

	int index = 0;
	std::cin >> index;
	if (index > list.GetSize())
	{
		std::cout << "指定した順番に要素がありませんでした。" << std::endl;
	}
	else
	{
		std::cout << index << ":" << list.GetData(index) << std::endl;
	}

	std::cout << "\n-----------------------------" << std::endl;

	// 戻る処理
	ElementsDisplayBack();
}
// 要素の表示内での戻る処理
void ListOperator::ElementsDisplayBack()
{
	enum Option
	{
		BackToDisplay = 1,	// 要素の表示に戻る
		BackToManipulat,	// 要素の操作に戻る
	};

	int optionNum = 0;
	std::cout << "1.要素の表示に戻る" << std::endl;
	std::cout << "2.要素の操作に戻る" << std::endl;

	std::cin >> optionNum;
	std::cout << std::endl;

	switch (optionNum)
	{
	case BackToDisplay:
		elementsDisplayStep = 0;
		break;
	case BackToManipulat:
		elementsDisplayStep = 0;
		manipulatElementsStep = Default;
		break;
	default:
		break;
	}
}

// 要素の挿入
void ListOperator::ElementsInsert()
{
	std::cout << "[リストの要素の挿入]" << std::endl;
	std::cout << "要素を追加する場所を指定してくだいさい。最後尾に追加する場合は何も入力しないでください" << std::endl;

	int index = 0;
	std::cin >> index;

	std::cout << "追加する要素の値を入力してください" << std::endl;

	int data = 0;
	std::cin >> data;

	if (index > list.GetSize())
	{
		list.PushBack(data);
		std::cout << "要素" << data << "が最後尾に追加されました" << std::endl;
	}
	else if (index == 0)
	{
		list.PushFront(data);
		std::cout << "要素" << data << "が最前列に追加されました" << std::endl;
	}
	else if (index < list.GetSize())
	{
		list.Insert(data, index);
		std::cout << "要素" << data << "が" << index << "番目に挿入されました" << std::endl;
	}

	std::cout << std::endl;
	manipulatElementsStep = Default;
}

// 要素の編集
void ListOperator::ElementsEdit()
{
	std::cout << "[要素の編集]" << std::endl;
	std::cout << "編集したい要素の番号を指定してください。" << std::endl;

	int index = 0;
	std::cin >> index;

	if (index < list.GetSize())
	{
		std::cout << index << "番目の要素の変更する値を入力してください。" << std::endl;

		int data;
		std::cin >> data;
		list.Change(data, index + 1);

		std::cout << index << "番目の要素の値が" << data << "に変更されました。" << std::endl;
	}
	else
	{
		std::cout << index << "番目の要素の値が見つかりませんでした。" << std::endl;
	}

	std::cout << std::endl;
	manipulatElementsStep = Default;
}