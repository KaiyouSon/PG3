#include "Circle.h"
#include <iostream>

Circle::Circle() : radius(0)
{
}

Circle::Circle(const float& radius) : radius(radius)
{
}

void Circle::Draw()
{
	std::cout << "�~���`�悳�ꂽ" << std::endl;
}

float Circle::GetSize()
{
	const float PI = 3.14159f;
	return radius * radius * PI;
}
