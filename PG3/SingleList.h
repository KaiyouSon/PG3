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
	SingleList() :size(0)
	{

	};
	SingleList(T data) :size(0)
	{
		start.data = data;
		size++;
	}

	// �ŏ��̃f�[�^
	inline T GetFront()
	{
		return start.data;
	}

	// �Ō�̃f�[�^
	inline T GetBack()
	{
		return CheckBack(&start)->data;
	}

	// ���Ԃ̃f�[�^
	inline T GetNode(const uint32_t& index)
	{
		auto current = start;		// ���݂̃m�[�h
		auto nextNode = start.next;	// ���̃m�[�h
		for (int i = 0; i < index; i++)
		{
			current = *nextNode;
			nextNode = current.next;
		}

		return current.data;
	}

	//	�T�C�Y�̎擾
	inline uint32_t GetSize()
	{
		return size;
	}

	// �m�[�h�̒ǉ�
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

	// �N���A
	inline void Clear()
	{
		start.data = 0;
		start.next = nullptr;
	}
};