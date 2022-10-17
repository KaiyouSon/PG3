#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

typedef int (*PFunc)(const int&);

// ��������𔻒f����֐�
int DecideOddOrEven(const int& num);

// �������擾����֐�
int GetRange(const int& min, const int& max);

// ���I����֐�
void Lottery(PFunc pFunc, int num);

int main()
{
	srand(time(nullptr));

	int num = 0;
	cin >> num;

	// �֐��|�C���^
	PFunc pFunc = DecideOddOrEven;

	Lottery(pFunc, num);

	return 0;
}

// ���I����֐�
void Lottery(PFunc pFunc, int num)
{
	// �O�b�X���[�v����
	Sleep(3000);
	// �T�C�R���̏o��
	int randNum = GetRange(0, 6);
	cout << "���I���� :" << randNum << endl;

	if (pFunc(num) == pFunc(randNum))
	{
		cout << "������I" << endl;
	}
	else
	{
		cout << "�͂���I" << endl;
	}
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
