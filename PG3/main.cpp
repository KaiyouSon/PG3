#include <iostream>
#include <time.h>
#include <windows.h>
#include <functional>
using namespace std;

// 乱数を取得する関数
int GetRange(const int& min, const int& max);

// 奇数か偶数を判断する関数
int DecideOddOrEven(const int& num);

int main()
{
	srand(time(nullptr));

	int num = 0;
	cin >> num;

	// 抽選結果を返す関数
	function <void()> Lottry = [=]()
	{
		// サイコロの出目
		int randNum = GetRange(0, 6);
		cout << "抽選結果 :" << randNum << endl;
		DecideOddOrEven(num) == DecideOddOrEven(randNum) ? cout << "当たり！" << endl : cout << "はずれ！" << endl;
	};

	// タイムアウト関数
	function<void(function<void()>, const int&)> SetTimeOut =
		[](function<void()> fx, const int& second)
	{
		Sleep(second * 1000);
		fx();
	};

	// 実行
	SetTimeOut(Lottry, 3);
	return 0;
}

// 乱数を取得する関数
int GetRange(const int& min, const int& max)
{
	return rand() % ((max - min) + 1) + min;
}

int DecideOddOrEven(const int& num)
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
}
