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
	BidireList() : begin(nullptr), size(0)
	{

	};
	BidireList(const T& data) : size(0)
	{
		begin.data = data;
		size++;
	}

	// �擪�Ƀm�[�h��ǉ�
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

	// �����Ƀm�[�h��ǉ�
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

	// �m�[�h�̑}��
	inline void Insert(Node<T> p, const int& index)
	{
		Node<T>* current = begin;			// ���݂̃m�[�h
		Node<T>* nextNode = begin->next;	// ���̃m�[�h
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

	// �v�f�̕ύX
	inline void Change(T p, const int& index)
	{
		Node<T>* current = begin;			// ���݂̃m�[�h
		Node<T>* nextNode = begin->next;	// ���̃m�[�h
		for (int i = 0; i < index - 1; i++)
		{
			current = nextNode;
			nextNode = current->next;
		}

		current->data = p;
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
		newBeginNode->prev = nullptr;
		begin = nullptr;
		begin = newBeginNode;
		size--;
	}

	// �����v�f�폜
	inline void PopBack()
	{
		Node<T>* endNode = CheckBack(begin);
		endNode->next = nullptr;
		size--;
		//PushBack(*endPrevNode);
	}

	// �v�f�̍폜
	inline void Erase(const unsigned int& index)
	{
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
	inline void Clear() { begin = nullptr; }

	// �T�C�Y�̎擾
	inline unsigned int GetSize() { return size; }
};