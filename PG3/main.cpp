#include <iostream>
#include <time.h>
#include <windows.h>
#include <functional>
using namespace std;

// �������擾����֐�
int GetRange(const int& min, const int& max);

// ��������𔻒f����֐�
int DecideOddOrEven(const int& num);

int main()
{
	srand(time(nullptr));

	int num = 0;
	cin >> num;

	// ���I���ʂ�Ԃ��֐�
	function <void()> Lottry = [=]()
	{
		// �T�C�R���̏o��
		int randNum = GetRange(0, 6);
		cout << "���I���� :" << randNum << endl;
		DecideOddOrEven(num) == DecideOddOrEven(randNum) ? cout << "������I" << endl : cout << "�͂���I" << endl;
	};

	// �^�C���A�E�g�֐�
	function<void(function<void()>, const int&)> SetTimeOut =
		[](function<void()> fx, const int& second)
	{
		Sleep(second * 1000);
		fx();
	};

	// ���s
	SetTimeOut(Lottry, 3);
	return 0;
}

// �������擾����֐�
int GetRange(const int& min, const int& max)
{
	return rand() % ((max - min) + 1) + min;
}

int DecideOddOrEven(const int& num)
{
	if (num % 2 == 0)
	{
		return 0;	// ����
	}
	else if (num % 1 == 0)
	{
		return 1;	// �
	}
	else
	{
		return -1;	// �G���[
	}
}
