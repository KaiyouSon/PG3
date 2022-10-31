#pragma once
#include "Node.h"

template<typename T>
//class UnidirectionalList
class SingleList
{
private:
	Node<T> start;
	uint32_t size;

private:
	// 単方向リストの最後のどうかをチェックする関数
	inline Node<T>* CheckBack(Node<T>* p)
	{
		if (p->next == nullptr)
		{
			return p;
		}
		else
		{
			CheckBack(p->next);
		}
	}

public:
	SingleList() :size(0)
	{

	};
	SingleList(T data) :size(0)
	{
		start.data = data;
		size++;
	}

	// 最初のデータ
	inline T GetFront()
	{
		return start.data;
	}

	// 最後のデータ
	inline T GetBack()
	{
		return CheckBack(&start)->data;
	}

	// 中間のデータ
	inline T GetNode(const uint32_t& index)
	{
		auto current = start;		// 現在のノード
		auto nextNode = start.next;	// 次のノード
		for (int i = 0; i < index; i++)
		{
			current = *nextNode;
			nextNode = current.next;
		}

		return current.data;
	}

	//	サイズの取得
	inline uint32_t GetSize()
	{
		return size;
	}

	// ノードの追加
	inline void PushBack(Node<T> p)
	{
		if (size == 0)
		{
			start = p;
		}
		else
		{
			CheckBack(&start)->next = &p;
		}

		size++;
	}

	// クリア
	inline void Clear()
	{
		start.data = 0;
		start.next = nullptr;
	}
};