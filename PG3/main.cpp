#include <iostream>
#include <time.h>
#include <windows.h>
#include <functional>
using namespace std;

// 乱数を取得する関数
int GetRange(const int& min, const int& max);

int main()
{
	srand(time(nullptr));

	int num = 0;
	cin >> num;

	// 三秒スリープする
	Sleep(3000);

	// 奇数か偶数を判断するラムダ式関数
	function<int(const int&)> fx = [](const int& num)
	{
		if (num % 2 == 0)
		{
			return 0;	// 偶数
		}
		else if (num % 1 == 0)
		{
			return 1;	// 奇数
		}
		else
		{
			return -1;	// エラー
		}
	};

	// サイコロの出目
	int randNum = GetRange(0, 6);
	cout << "抽選結果 :" << randNum << endl;

	if (fx(num) == fx(randNum))
	{
		cout << "当たり！" << endl;
	}
	else
	{
		cout << "はずれ！" << endl;
	}

	return 0;
}

// 乱数を取得する関数
int GetRange(const int& min, const int& max)
{
	return rand() % ((max - min) + 1) + min;
}