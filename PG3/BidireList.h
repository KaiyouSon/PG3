#pragma once

template<typename T>
struct Node
{
	T data;
	Node<T>* prev;
	Node<T>* next;

	Node() : prev(nullptr), next(nullptr)
	{
	}
	Node(T data) : data(data), prev(nullptr), next(nullptr)
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
class BidireList
{
private:
	Node<T>* begin;
	unsigned int size;

private:
	// リストの最後かどうかをチェックする関数
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
	BidireList() : begin(nullptr), size(0)
	{

	};
	BidireList(const T& data) : size(0)
	{
		begin.data = data;
		size++;
	}

	// 先頭にノードを追加
	inline void PushFront(Node<T> p)
	{
		if (size == 0)
		{
			begin = &p;
		}
		else
		{

			Node<T>* temp = begin;
			temp->prev = &p;
			p.next = temp;
			begin = &p;
		}

		size++;
	}

	// 末尾にノードを追加
	inline void PushBack(Node<T> p)
	{
		if (size == 0)
		{
			begin = &p;
		}
		else
		{
			p.prev = CheckBack(begin);
			CheckBack(begin)->next = &p;
		}

		size++;
	}

	// ノードの挿入
	inline void Insert(Node<T> p, const int& index)
	{
		Node<T>* current = begin;			// 現在のノード
		Node<T>* nextNode = begin->next;	// 次のノード
		for (int i = 0; i < index - 1; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		p.prev = current;
		p.next = nextNode;
		current->next = &p;

		size++;
	}

	// 要素の変更
	inline void Change(T p, const int& index)
	{
		Node<T>* current = begin;			// 現在のノード
		Node<T>* nextNode = begin->next;	// 次のノード
		for (int i = 0; i < index - 1; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		current->data = p;
	}

	// 最初のデータ
	inline T GetFront()
	{
		return begin.data;
	}

	// 最後のデータ
	inline T GetBack()
	{
		return CheckBack(begin)->data;
	}

	// 中間のデータ
	inline T GetData(const unsigned int& index)
	{
		auto current = begin;		// 現在のノード
		auto nextNode = begin->next;	// 次のノード
		for (int i = 0; i < index; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		return current->data;
	}

	// ノードをもらう
	inline Node<T> GetNode(const unsigned int& index)
	{
		auto current = begin;		// 現在のノード
		auto nextNode = begin->next;	// 次のノード
		for (int i = 0; i < index; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		return *current;
	}

	// 先頭要素削除
	inline void PopFront()
	{
		Node<T>* newBeginNode = begin->next;
		newBeginNode->prev = nullptr;
		begin = nullptr;
		begin = newBeginNode;
		size--;
	}

	// 末尾要素削除
	inline void PopBack()
	{
		Node<T>* endNode = CheckBack(begin);
		endNode->next = nullptr;
		size--;
		//PushBack(*endPrevNode);
	}

	// 要素の削除
	inline void Erase(const unsigned int& index)
	{
		auto current = begin;		// 現在のノード
		auto nextNode = begin->next;	// 次のノード
		for (int i = 0; i < index - 2; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		current->next = nextNode->next;
		size--;
	}


	// クリア
	inline void Clear() { begin = nullptr; }

	// サイズの取得
	inline unsigned int GetSize() { return size; }
};