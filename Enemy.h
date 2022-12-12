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
	// �Z�b�^�[
	static void SetisAllAlive(const bool& isAllAlive) { Enemy::isAllAlive = isAllAlive; }

	// �Q�b�^�[
	static bool GetisAllAlive() { return isAllAlive; }
};

