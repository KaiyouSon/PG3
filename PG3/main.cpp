#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

typedef int (*PFunc)(const int&);

// 奇数か偶数を判断する関数
int DecideOddOrEven(const int& num);

// 乱数を取得する関数
int GetRange(const int& min, const int& max);

// 抽選する関数
void Lottery(PFunc pFunc, int num);

int main()
{
	srand(time(nullptr));

	int num = 0;
	cin >> num;

	// 関数ポインタ
	PFunc pFunc = DecideOddOrEven;

	Lottery(pFunc, num);

	return 0;
}

// 抽選する関数
void Lottery(PFunc pFunc, int num)
{
	// 三秒スリープする
	Sleep(3000);
	// サイコロの出目
	int randNum = GetRange(0, 6);
	cout << "抽選結果 :" << randNum << endl;

	if (pFunc(num) == pFunc(randNum))
	{
		cout << "当たり！" << endl;
	}
	else
	{
		cout << "はずれ！" << endl;
	}
}

// 奇数か偶数を判断する関数
int DecideOddOrEven(const int& num)
{
	if (num % 2 == 0)
	{
		return 0;
	}
	else if (num % 1 == 0)
	{
		return 1;
	}
	else
	{
		return -1;	// エラー
	}
}

// 乱数を取得する関数
int GetRange(const int& min, const int& max)
{
	return rand() % ((max - min) + 1) + min;
}
