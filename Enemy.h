#pragma once
class Enemy
{
private:
	static bool isAllAlive;


public:
	Enemy();
	void Load();
	void Init();
	void Update();
	void Draw();

public:
	// セッター
	static void SetisAllAlive(const bool& isAllAlive) { Enemy::isAllAlive = isAllAlive; }

	// ゲッター
	static bool GetisAllAlive() { return isAllAlive; }
};

