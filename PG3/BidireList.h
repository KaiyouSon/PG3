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
	BidireList() : begin(new Node<T>), size(0)
	{
	};
	BidireList(const T& data) : size(0)
	{
		begin.data = data;
		size++;
	}
	~BidireList()
	{
		Clear();
	}

	inline Node<T>* CreateNode(T data)
	{
		Node<T>* node = new Node<T>;
		node->data = data;

		return node;

	}

	// 先頭にノードを追加
	inline void PushFront(T data)
	{
		if (size == 0)
		{
			begin->data = data;
		}
		else
		{
			Node<T>* newNode = CreateNode(data);
			Node<T>* temp = begin;
			temp->prev = newNode;
			newNode->next = temp;
			begin = newNode;
		}

		size++;
	}

	// 末尾にノードを追加
	inline void PushBack(T data)
	{
		if (size == 0)
		{
			begin->data = data;
		}
		else
		{
			Node<T>* newNode = CreateNode(data);
			newNode->prev = CheckBack(begin);
			CheckBack(begin)->next = newNode;
		}

		size++;
	}

	// ノードの挿入
	inline void Insert(T data, const int& index)
	{
		if (index == 0)
		{
			PushFront(data);
			return;
		}
		if (index >= size)
		{
			PushBack(data);
			return;
		}

		Node<T>* current = begin;			// 現在のノード
		Node<T>* nextNode = begin->next;	// 次のノード
		for (int i = 0; i < index - 1; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		Node<T>* newNode = CreateNode(data);
		newNode->prev = current;
		newNode->next = nextNode;
		current->next = newNode;
		nextNode->prev = newNode;

		size++;
	}

	// 要素の変更
	inline void Change(T data, const int& index)
	{
		Node<T>* current = begin;			// 現在のノード
		Node<T>* nextNode = begin->next;	// 次のノード
		for (int i = 0; i < index - 1; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		current->data = data;
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
		delete newBeginNode->prev;
		newBeginNode->prev = nullptr;
		begin = newBeginNode;
		size--;
	}

	// 末尾要素削除
	inline void PopBack()
	{
		Node<T>* endNode = CheckBack(begin);
		delete endNode;
		endNode = nullptr;
		size--;
	}

	// 要素の削除
	inline void Erase(const unsigned int& index)
	{
		if (index == 0)
		{
			PopFront();
			return;
		}
		if (index == size - 1)
		{
			PopBack();
			return;
		}

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
	inline void Clear()
	{
		while (size > 0)
		{
			Node<T>* currentNode = begin;
			Node<T>* nextNode = begin->next;
			for (int i = 0; i < size - 1; i++)
			{
				currentNode = nextNode;
				nextNode = currentNode->next;
			}
			delete currentNode;
			currentNode = nullptr;
			size--;
		}
	}

	// サイズの取得
	inline unsigned int GetSize() { return size; }
};