#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

typedef int (*PFunc)(const int&);

// 奇数か偶数を判断する関数
int DecideOddOrEven(const int& num);

// 乱数を取得する関数
int GetRange(const int& min, const int& max);

int main()
{
	srand(time(nullptr));

	int num = 0;
	cin >> num;

	// 三秒スリープする
	Sleep(3000);

	// 関数ポインタ
	PFunc pFunc = DecideOddOrEven;

	// 偶数であれば
	if (pFunc(num) == 0)
	{
		cout << GetRange(-20, 20) << endl;
	}
	// 奇数であれば
	else if (pFunc(num) == 1)
	{
		cout << GetRange(-10, 10) << endl;
	}


	return 0;
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
