#include <iostream>
using namespace std;

// ���̎��Ԃ̋������v�Z����֐��i�ċA�I�����̌n�j
// ��F2����ꂽ��A2���Ԗڂ̋�����Ԃ�
int GetRecursiveHourSalary(int time);

// ���������Ԃ̍��v������Ԃ��֐��i�ċA�I�����̌n�j
int GetRecursiveTotalSalary(int time);

//  ���������Ԃ̍��v������Ԃ��֐��i��ʓI�����̌n�j
int GetGeneralTotalSalary(int time);

int main()
{
	// ����
	int time = 8;

	int recursiveTotalSalary = GetRecursiveTotalSalary(time);	// �ċA�I�����̌n�̍��v����
	int generalTotalSalary = GetGeneralTotalSalary(time);		// ��ʓI�����̌n�̍��v����

	if (recursiveTotalSalary >= generalTotalSalary)
	{
		cout << time << "���Ԃ��ƁA�ċA�I�����̌n�̕����ׂ���" << endl;
		cout << "���v�����F" << recursiveTotalSalary << "\n" << endl;
	}
	else
	{
		cout << time << "���Ԃ��ƁA��ʓI�����̌n�̕����ׂ���" << endl;
		cout << "���v�����F" << generalTotalSalary << "\n" << endl;
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