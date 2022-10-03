#include <iostream>
using namespace std;

// その時間の給料を計算する関数（再帰的賃金体系）
// 例：2を入れたら、2時間目の給料を返す
int GetRecursiveHourSalary(int time);

// 働いた時間の合計給料を返す関数（再帰的賃金体系）
int GetRecursiveTotalSalary(int time);

//  働いた時間の合計給料を返す関数（一般的賃金体系）
int GetGeneralTotalSalary(int time);

int main()
{
	// 時間
	int time = 8;

	int recursiveTotalSalary = GetRecursiveTotalSalary(time);	// 再帰的賃金体系の合計給料
	int generalTotalSalary = GetGeneralTotalSalary(time);		// 一般的賃金体系の合計給料

	if (recursiveTotalSalary >= generalTotalSalary)
	{
		cout << time << "時間だと、再帰的賃金体系の方が儲かる" << endl;
		cout << "合計給料：" << recursiveTotalSalary << "\n" << endl;
	}
	else
	{
		cout << time << "時間だと、一般的賃金体系の方が儲かる" << endl;
		cout << "合計給料：" << generalTotalSalary << "\n" << endl;
	}

	return 0;
}

int GetRecursiveHourSalary(int time)
{
	if (time <= 1)
	{
		return 100;
	}
	else
	{
		int test = GetRecursiveHourSalary(time - 1);
		return test * 2 - 50;
	}
}

int GetRecursiveTotalSalary(int time)
{
	int num = 0;
	for (int i = time; i > 0; i--)
	{
		num += GetRecursiveHourSalary(i);
	}

	return num;
}

int GetGeneralTotalSalary(int time)
{
	return time * 1072;
}