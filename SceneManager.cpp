#include "SceneManager.h"
#include <iostream>
#include <Windows.h>
#include <string>

SceneManager::SceneManager()
{
	const int enemyMaxNum = 3;

	for (int i = 0; i < enemyMaxNum; i++)
	{
		enemys.emplace_back(std::move(std::make_unique<Enemy>()));
	}
}

void SceneManager::Load()
{
	for (const auto& enemy : enemys)
	{
		enemy->Load();
	}
}

void SceneManager::Init()
{
	for (const auto& enemy : enemys)
	{
		enemy->Init();
	}
}

void SceneManager::Update()
{
	int key = 0;

	std::cout << "1 ¶‚«‚é 2 ŽE‚·" << std::endl;
	std::cin >> key;

	if (key == 1)
	{
		int count = 0;
		for (const auto& enemy : enemys)
		{
			std::cout << "enemy" << count;
			enemy->Update();
			count++;
			Sleep(500);
		}
	}
	else if (key == 2)
	{
		Enemy::SetisAllAlive(false);

		enemys.remove_if(
			[](const auto& enemy)
			{
				return !Enemy::GetisAllAlive();
			});

		if (enemys.empty() == true)
		{
			std::cout << "‘S•”‚µ‚ñ‚¾" << std::endl;
		}
	}

	std::cout << std::endl;
}

void SceneManager::Draw()
{
	for (const auto& enemy : enemys)
	{
		enemy->Draw();
	}
}

void SceneManager::ChangeScene(const int sceneNo)
{
	switch (sceneNo)
	{
	case 0:
		std::cout << "SceneNo: 0" << std::endl;
		break;

	case 1:
		std::cout << "SceneNo: 1" << std::endl;
		break;

	case 2:
		std::cout << "SceneNo: 2" << std::endl;
		break;

	case 3:
		std::cout << "SceneNo: 3" << std::endl;
		break;

	default:
		break;
	}
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager* sceneManager = new SceneManager;
	return sceneManager;
}

void SceneManager::DestroyInstance()
{
	delete GetInstance();
}