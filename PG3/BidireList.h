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
	// ���X�g�̍Ōォ�ǂ������`�F�b�N����֐�
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

	// �擪�Ƀm�[�h��ǉ�
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

	// �����Ƀm�[�h��ǉ�
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

	// �m�[�h�̑}��
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

		Node<T>* current = begin;			// ���݂̃m�[�h
		Node<T>* nextNode = begin->next;	// ���̃m�[�h
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

	// �v�f�̕ύX
	inline void Change(T data, const int& index)
	{
		Node<T>* current = begin;			// ���݂̃m�[�h
		Node<T>* nextNode = begin->next;	// ���̃m�[�h
		for (int i = 0; i < index - 1; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		current->data = data;
	}

	// �ŏ��̃f�[�^
	inline T GetFront()
	{
		return begin.data;
	}

	// �Ō�̃f�[�^
	inline T GetBack()
	{
		return CheckBack(begin)->data;
	}

	// ���Ԃ̃f�[�^
	inline T GetData(const unsigned int& index)
	{
		auto current = begin;		// ���݂̃m�[�h
		auto nextNode = begin->next;	// ���̃m�[�h
		for (int i = 0; i < index; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		return current->data;
	}

	// �m�[�h�����炤
	inline Node<T> GetNode(const unsigned int& index)
	{
		auto current = begin;		// ���݂̃m�[�h
		auto nextNode = begin->next;	// ���̃m�[�h
		for (int i = 0; i < index; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		return *current;
	}

	// �擪�v�f�폜
	inline void PopFront()
	{
		Node<T>* newBeginNode = begin->next;
		delete newBeginNode->prev;
		newBeginNode->prev = nullptr;
		begin = newBeginNode;
		size--;
	}

	// �����v�f�폜
	inline void PopBack()
	{
		Node<T>* endNode = CheckBack(begin);
		delete endNode;
		endNode = nullptr;
		size--;
	}

	// �v�f�̍폜
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

		auto current = begin;		// ���݂̃m�[�h
		auto nextNode = begin->next;	// ���̃m�[�h
		for (int i = 0; i < index - 2; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		current->next = nextNode->next;
		size--;
	}


	// �N���A
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

	// �T�C�Y�̎擾
	inline unsigned int GetSize() { return size; }
};