#pragma once

template<typename T>
struct Node
{
	T data;
	Node<T>* next;

	Node() :next(nullptr)
	{
	}
	Node(T data) : data(data), next(nullptr)
	{
	}

	void PushBack(Node<T> p)
	{
		if (next == nullptr)
		{
			next = &p;
		}
	}
};