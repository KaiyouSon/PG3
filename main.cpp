#include <iostream>
#include <memory>
#include <Windows.h>
#include "SceneManager.h"

int main()
{
	SceneManager* sceneManager = SceneManager::GetInstance();

	sceneManager->Load();
	sceneManager->Init();

	while (true)
	{
		sceneManager->Update();
		sceneManager->Draw();
		Sleep(1000);
	}

	SceneManager::DestroyInstance();

	system("pause");

	return 0;
}