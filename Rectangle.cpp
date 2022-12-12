#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() :
	width(0), height(0)
{
}

Rectangle::Rectangle(const float& width, const float& height) :
	width(width), height(height)
{
}

void Rectangle::Draw()
{
	std::cout << "��`���`�悳�ꂽ" << std::endl;
}

float Rectangle::GetSize()
{
	return width * height;
}
