#pragma once

template<typename T>
struct Node
{
	T data;
	Node<T>* prev;
	Node<T>* next;

	Node() :next(nullptr)
	{
	}
	Node(T data) : data(data), next(nullptr)
	{
	}

	void PushFront(Node<T> p)
	{
		if (prev == nullptr)
		{
			prev = &p;
		}
	}

	void PushBack(Node<T> p)
	{
		if (next == nullptr)
		{
			next = &p;
		}
	}
};

template<typename T>
class BidirectionalList
{
private:
	Node<T> begin;
	Node<T> tempNode;
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
	BidirectionalList() :size(0)
	{

	};
	BidirectionalList(const T& data) :size(0)
	{
		begin.data = data;
		size++;
	}

	// 先頭にノードを追加
	inline void PushFront(Node<T> p)
	{
		tempNode = begin;
		begin = p;
		begin.next = &tempNode;
		size++;
	}

	// 末尾にノードを追加
	inline void PushBack(Node<T> p)
	{
		if (size == 0)
		{
			begin = p;
		}
		else
		{
			CheckBack(&begin)->next = &p;
		}

		size++;
	}

	// 最初のデータ
	inline T GetFront()
	{
		return begin.data;
	}

	// 最後のデータ
	inline T GetBack()
	{
		return CheckBack(&begin)->data;
	}

	// 中間のデータ
	inline T GetNode(const uint32_t& index)
	{
		auto current = begin;		// 現在のノード
		auto nextNode = begin.next;	// 次のノード
		for (int i = 0; i < index; i++)
		{
			current = *nextNode;
			nextNode = current.next;
		}

		return current.data;
	}

	// サイズの取得
	inline uint32_t GetSize() { return size; }

	// クリア
	inline void Clear() { begin.data = 0; begin.next = nullptr; }
};

template<typename T>
using BidireList = BidirectionalList<T>;