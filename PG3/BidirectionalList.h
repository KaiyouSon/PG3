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
	// �P�������X�g�̍Ō�̂ǂ������`�F�b�N����֐�
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

	// �擪�Ƀm�[�h��ǉ�
	inline void PushFront(Node<T> p)
	{
		tempNode = begin;
		begin = p;
		begin.next = &tempNode;
		size++;
	}

	// �����Ƀm�[�h��ǉ�
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

	// �ŏ��̃f�[�^
	inline T GetFront()
	{
		return begin.data;
	}

	// �Ō�̃f�[�^
	inline T GetBack()
	{
		return CheckBack(&begin)->data;
	}

	// ���Ԃ̃f�[�^
	inline T GetNode(const uint32_t& index)
	{
		auto current = begin;		// ���݂̃m�[�h
		auto nextNode = begin.next;	// ���̃m�[�h
		for (int i = 0; i < index; i++)
		{
			current = *nextNode;
			nextNode = current.next;
		}

		return current.data;
	}

	// �T�C�Y�̎擾
	inline uint32_t GetSize() { return size; }

	// �N���A
	inline void Clear() { begin.data = 0; begin.next = nullptr; }
};

template<typename T>
using BidireList = BidirectionalList<T>;