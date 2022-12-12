#pragma once
#include "Singleton.h"
#include "Enemy.h"
#include <memory>
#include <list>

class SceneManager final
{
private:
	std::list<std::unique_ptr<Enemy>> enemys;

public:
	void Load();
	void Init();
	void Update();
	void Draw();
	void ChangeScene(const int sceneNo);

public:	// シングルトン関連
	static SceneManager* GetInstance();
	static void DestroyInstance();
private:
	SceneManager();
	~SceneManager() {}
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	SceneManager(const SceneManager&&) = delete;
	SceneManager& operator=(const SceneManager&&) = delete;
};

