#include "Enemy.h"
#include <iostream>
#include <Windows.h>

Enemy::Enemy() : state(Approach)
{
}

void Enemy::Load()
{
}

void Enemy::Init()
{
}

void Enemy::Update()
{
	// �֐��e�[�u��
	void (Enemy:: * FuncTable[])() =
	{
		// �o�^
		&Enemy::ApproachUpdate,
		&Enemy::ShotUpdate,
		&Enemy::SecessionUpdate
	};

	// ���s
	(this->*FuncTable[state])();
}

void Enemy::Draw()
{
}

void Enemy::ApproachUpdate()
{
	std::cout << "�G���ڋ�" << std::endl;
	state = Shot;

	Sleep(1000);
}

void Enemy::ShotUpdate()
{
	std::cout << "�G���ˌ�" << std::endl;
	state = Secession;

	Sleep(1000);
}

void Enemy::SecessionUpdate()
{
	std::cout << "�G�����E" << std::endl;
	state = Approach;

	Sleep(1000);
}