#include <iostream>
using namespace std;

// その時間の給料を計算する関数（再帰的賃金体系）
// 例：2を入れたら、2時間目の給料を返す
float GetRecursiveHourSalary(float time);

// 働いた時間の合計給料を返す関数（再帰的賃金体系）
float GetRecursiveTotalSalary(float time);

//  働いた時間の合計給料を返す関数（一般的賃金体系）
float GetGeneralTotalSalary(float time);

float main()
{
	// 時間
	float time = 7.1;

	float recursiveTotalSalary = GetRecursiveTotalSalary(time);	// 再帰的賃金体系の合計給料
	float generalTotalSalary = GetGeneralTotalSalary(time);		// 一般的賃金体系の合計給料

	if (recursiveTotalSalary >= generalTotalSalary)
	{
		cout << time << "時間だと、再帰的賃金体系の方が儲かる" << endl;
		cout << "合計給料" << recursiveTotalSalary << "\n" << endl;
	}
	else
	{
		cout << time << "時間だと、一般的賃金体系の方が儲かる" << endl;
		cout << "合計給料" << generalTotalSalary << "\n" << endl;
	}

	return 0;
}

float GetRecursiveHourSalary(float time)
{
	if (time <= 1)
	{
		return 100;
	}
	else
	{
		float test = GetRecursiveHourSalary(time - 1);
		return test * 2 - 50;
	}
}

float GetRecursiveTotalSalary(float time)
{
	float num = 0;
	for (float i = time; i > 0; i--)
	{
		num += GetRecursiveHourSalary(i);
	}

	return num;
}

float GetGeneralTotalSalary(float time)
{
	return time * 1072;
}