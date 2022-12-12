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
	// ŠÖ”ƒe[ƒuƒ‹
	void (Enemy:: * FuncTable[])() =
	{
		// “o˜^
		&Enemy::ApproachUpdate,
		&Enemy::ShotUpdate,
		&Enemy::SecessionUpdate
	};

	// ŽÀs
	(this->*FuncTable[state])();
}

void Enemy::Draw()
{
}

void Enemy::ApproachUpdate()
{
	std::cout << "“G‚ªÚ‹ß" << std::endl;
	state = Shot;

	Sleep(1000);
}

void Enemy::ShotUpdate()
{
	std::cout << "“G‚ªŽËŒ‚" << std::endl;
	state = Secession;

	Sleep(1000);
}

void Enemy::SecessionUpdate()
{
	std::cout << "“G‚ª—£’E" << std::endl;
	state = Approach;

	Sleep(1000);
}