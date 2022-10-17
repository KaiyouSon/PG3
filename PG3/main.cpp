#include <iostream>
#include <time.h>
#include <windows.h>
#include <functional>
using namespace std;

// �������擾����֐�
int GetRange(const int& min, const int& max);

int main()
{
	srand(time(nullptr));

	int num = 0;
	cin >> num;

	// �O�b�X���[�v����
	Sleep(3000);

	// ��������𔻒f���郉���_���֐�
	function<int(const int&)> fx = [](const int& num)
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
	};

	// �����ł����
	if (fx(num) == 0)
	{
		cout << GetRange(-20, 20) << endl;
	}
	// ��ł����
	else if (fx(num) == 1)
	{
		cout << GetRange(-10, 10) << endl;
	}

	return 0;
}

// �������擾����֐�
int GetRange(const int& min, const int& max)
{
	return rand() % ((max - min) + 1) + min;
}