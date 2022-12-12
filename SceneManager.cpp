#include "SceneManager.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

SceneManager::SceneManager()
{
	shapes.emplace_back(std::move(std::make_unique<Circle>(5.f)));
	shapes.emplace_back(std::move(std::make_unique<Rectangle>(10.f, 20.f)));
}

void SceneManager::Load()
{
}

void SceneManager::Init()
{
}

void SceneManager::Update()
{
	for (const auto& shape : shapes)
	{
		std::cout << "�ʐρF" << shape->GetSize() << std::endl;
	}
}

void SceneManager::Draw()
{
	for (const auto& shape : shapes)
	{
		shape->Draw();
	}
	std::cout << std::endl;
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