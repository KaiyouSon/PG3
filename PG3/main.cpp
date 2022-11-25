#include <iostream>
#include <stdio.h>
#include "BidirectionalList.h"

int main()
{
	//BidireList<const char*> keihinntouhokuLine;

	//keihinntouhokuLine.PushBack("Yokohama Station");
	//keihinntouhokuLine.PushBack("Higasikanagawa Station");
	//keihinntouhokuLine.PushBack("Sinnkoyasu Station");
	//keihinntouhokuLine.PushBack("Turumi Station");
	//keihinntouhokuLine.PushBack("Kawasaki Station");
	//keihinntouhokuLine.PushBack("Kamata Station");
	//keihinntouhokuLine.PushBack("Oomori Station");
	//keihinntouhokuLine.PushBack("Ooimati Station");
	//keihinntouhokuLine.PushBack("Sinagawa Station");
	////keihinntouhokuLine.PushBack("TakanawaGateway Station");
	//keihinntouhokuLine.PushBack("Tamati Station");
	//keihinntouhokuLine.PushBack("Hamatutyou Station");
	//keihinntouhokuLine.PushBack("Sinnbasi Station");
	//keihinntouhokuLine.PushBack("Yuurakutyou Station");
	//keihinntouhokuLine.PushBack("Toukyou Station");
	//keihinntouhokuLine.PushBack("Kannda Station");
	//keihinntouhokuLine.PushBack("Akibahara Station");
	//keihinntouhokuLine.PushBack("Okatimati Station");
	//keihinntouhokuLine.PushBack("Ueno Station");
	//keihinntouhokuLine.PushBack("Uguisudani Station");
	//keihinntouhokuLine.PushBack("Nippori Station");
	//keihinntouhokuLine.PushBack("Nisinippori Station");
	//keihinntouhokuLine.PushBack("Tabata Station");
	//keihinntouhokuLine.PushBack("Kaminakazato Station");
	//keihinntouhokuLine.PushBack("Ouji Station");
	//keihinntouhokuLine.PushBack("Higasijyujyou Station");
	//keihinntouhokuLine.PushBack("Akabane Station");
	//keihinntouhokuLine.PushBack("Kawaguti Station");
	//keihinntouhokuLine.PushBack("Nisikawaguti Station");
	//keihinntouhokuLine.PushBack("Warabi Station");
	//keihinntouhokuLine.PushBack("Minamiurayasu Station");
	//keihinntouhokuLine.PushBack("Urayasu Station");
	//keihinntouhokuLine.PushBack("Kitaurayasu Station");
	//keihinntouhokuLine.PushBack("Yono Station");
	//keihinntouhokuLine.PushBack("Saitamasintosin Station");
	//keihinntouhokuLine.PushBack("Oomiya Station");

	BidireList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);

	std::cout << "------------------------" << std::endl;

	// リストのサイズ分のデータを出力する
	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << "今の駅：" << list.GetData(i) << std::endl;
		//std::cout << "前の駅：" << keihinntouhokuLine.GetNode(i) << std::endl;
		//std::cout << "後の駅" << keihinntouhokuLine.GetNode(i) << std::endl;
	}

	std::cout << "------------------------" << std::endl;

	list.Erase(2);

	// リストのサイズ分のデータを出力する
	for (int i = 0; i < list.GetSize(); i++)
	{
		std::cout << "今の駅：" << list.GetData(i) << std::endl;
		//std::cout << "前の駅：" << keihinntouhokuLine.GetNode(i) << std::endl;
		//std::cout << "後の駅" << keihinntouhokuLine.GetNode(i) << std::endl;
	}

	return 0;
}