#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

typedef int (*PFunc)(const int&);

// ��������𔻒f����֐�
int DecideOddOrEven(const int& num);

// �������擾����֐�
int GetRange(const int& min, const int& max);

int main()
{
	srand(time(nullptr));

	int num = 0;
	cin >> num;

	// �O�b�X���[�v����
	Sleep(3000);

	// �֐��|�C���^
	PFunc pFunc = DecideOddOrEven;

	// �����ł����
	if (pFunc(num) == 0)
	{
		cout << GetRange(-20, 20) << endl;
	}
	// ��ł����
	else if (pFunc(num) == 1)
	{
		cout << GetRange(-10, 10) << endl;
	}


	return 0;
}

// ��������𔻒f����֐�
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
		return -1;	// �G���[
	}
}

// �������擾����֐�
int GetRange(const int& min, const int& max)
{
	return rand() % ((max - min) + 1) + min;
}
