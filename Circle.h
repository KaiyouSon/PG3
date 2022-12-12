#pragma once
#include "IShape.h"
class Circle : public IShape
{
private:
	float radius;

public:
	Circle();
	Circle(const float& radius);
	void Draw() override;
	float GetSize() override;
};

