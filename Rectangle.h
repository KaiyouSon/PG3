#pragma once
#include "IShape.h"
class Rectangle : public IShape
{
private:
	float width;
	float height;

public:
	Rectangle();
	Rectangle(const float& width, const float& height);
	void Draw() override;
	float GetSize() override;

public:
	// セッター
	inline void SetWidth(const float& width) { this->width = width; }
	inline void SetHeight(const float& height) { this->height = height; }
};

