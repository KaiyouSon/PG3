#pragma once
class Enemy
{
private:
	enum EnemyState
	{
		Approach,
		Shot,
		Secession,
	};

	int state;

private:
	void ApproachUpdate();
	void ShotUpdate();
	void SecessionUpdate();

public:
	Enemy();
	void Load();
	void Init();
	void Update();
	void Draw();
};

