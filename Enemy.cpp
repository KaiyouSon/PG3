#include "Enemy.h"
#include <iostream>

bool Enemy::isAllAlive = true;

Enemy::Enemy()
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
	if (isAllAlive == false) return;

	std::cout << "�����Ă�" << std::endl;
}

void Enemy::Draw()
{
}
