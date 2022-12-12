#pragma once
#include "Singleton.h"
#include <memory>

class SceneManager final
{
private:
	SceneManager(){}
	~SceneManager(){}
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	SceneManager(const SceneManager&&) = delete;
	SceneManager& operator=(const SceneManager&&) = delete;

public:
	void ChangeScene(const int sceneNo);

	static SceneManager* GetInstance();
	static void DestroyInstance();
};

