#include <iostream>
using namespace std;

// ���̎��Ԃ̋������v�Z����֐��i�ċA�I�����̌n�j
// ��F2����ꂽ��A2���Ԗڂ̋�����Ԃ�
float GetRecursiveHourSalary(float time);

// ���������Ԃ̍��v������Ԃ��֐��i�ċA�I�����̌n�j
float GetRecursiveTotalSalary(float time);

//  ���������Ԃ̍��v������Ԃ��֐��i��ʓI�����̌n�j
float GetGeneralTotalSalary(float time);

float main()
{
	// ����
	float time = 7.1;

	float recursiveTotalSalary = GetRecursiveTotalSalary(time);	// �ċA�I�����̌n�̍��v����
	float generalTotalSalary = GetGeneralTotalSalary(time);		// ��ʓI�����̌n�̍��v����

	if (recursiveTotalSalary >= generalTotalSalary)
	{
		cout << time << "���Ԃ��ƁA�ċA�I�����̌n�̕����ׂ���" << endl;
		cout << "���v����" << recursiveTotalSalary << "\n" << endl;
	}
	else
	{
		cout << time << "���Ԃ��ƁA��ʓI�����̌n�̕����ׂ���" << endl;
		cout << "���v����" << generalTotalSalary << "\n" << endl;
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