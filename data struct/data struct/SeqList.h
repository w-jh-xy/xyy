#pragma once
#include"Sysutil.h"

#define ElemType int
#define SEQLIST_DEFAULT_SIZE 8

typedef struct SeqList
{
	ElemType* base;
	size_t    capacity;
	size_t    size;
}SeqList;

void SeqListInit(SeqList* pst);
void SeqListPushBack(SeqList* pst, ElemType x);
void SeqListPushFront(SeqList* pst,ElemType x);
void SeqListPopBack(SeqList* pst);
void SeqListPopFront(SeqList* pst);
void SeqListShow(SeqList* pst);
size_t SeqListLength(SeqList* pst);
size_t SeqListCapacity(SeqList* pst);
void SeqListClear(SeqList* pst);
void SeqListDestroy(SeqList* pst);
int SeqListFind(SeqList* pst, ElemType key);
void SeqListSort(SeqList* pst);
void SeqListInsert(SeqList* ps, size_t pos, ElemType x);
void SeqListDeleteByVal(SeqList* pst, ElemType key);
void SeqListDeleteByPos(SeqList* pst, int pos);

bool IsFull(SeqList* pst)//����
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)//�п�
{
	return pst->size == 0;
}


void SeqListInit(SeqList* pst)//��ʼ��
{
	//���ԡ������ڴ桢��ʼ��
	assert(pst);
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);//���ٳɹ�
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

void SeqListPushBack(SeqList* pst, ElemType x)//β��
{
	//���ԡ����������롢size++
	assert(pst);
	if (IsFull(pst))
	{
		printf("˳���������%d����β������\n", x);
		return;
	}
	else
	{
		pst->base[pst->size++] = x;
	}
}
void SeqListPushFront(SeqList* pst, ElemType x)//ͷ��
{
	//���ԡ��пա��ƶ������롢size--
	assert(pst);
	if (IsFull(pst))
	{
		printf("˳���������%d����ͷ������\n", x);
		return;
	}
	for (int i = pst->size; i >= 0; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[0] = x;
	pst->size++;
}

void SeqListPopBack(SeqList* pst)//βɾ
{
	//���ԡ��пա�βɾ
	assert(pst);
	if(IsEmpty(pst))
	{
		printf("˳����ѿգ�����βɾ\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList* pst)
{
	//���ԡ��пա�ͷɾ
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ�����ͷ��ɾ��\n");
		return;
	}
	for (int i = 0; i <= pst->size - 1; ++i)
	{
		pst->base[i] = pst->base[i + 1];
		
	}
	pst->size--;
}
void SeqListShow(SeqList* pst)
{
	assert(pst);
	for (int i = 0; i < pst->size; ++i)  //0 1 2 3 4 5
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

size_t SeqListLength(SeqList* pst)
{
	return pst->size;
}
size_t SeqListCapacity(SeqList* pst)
{
	return pst->capacity;
}
void SeqListClear(SeqList* pst)
{
	pst->size = 0;
}

void SeqListDestroy(SeqList* pst)
{
	assert(pst);
	free(pst->base);
	pst->base = NULL; // Ԥ��Ұָ��
	pst->capacity = pst->size = 0;
}

int SeqListFind(SeqList* pst, ElemType key)
{
	for (int i = 0; i < pst->size; ++i)
	{
		if (key == pst->base[i])
			return i;
	}
	return -1;
}

void SeqListSort(SeqList* pst)
{
	//ð������
	for (int i = 0; i < pst->size - 1; ++i) //��������
	{
		for (int j = 0; j < pst->size - i - 1; ++j)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				//��������
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}

void SeqListInsert(SeqList* ps, size_t pos, ElemType x)
{
	assert(ps);
	assert(pos <= ps->size);
	if (IsFull(ps))
	{
		printf("˳������������ܲ��룡");
		return;
	}
	size_t i = ps->size;
	while (i > pos)
	{
		ps->base[i] = ps->base[i - 1];
		--i;
	}
	ps->base[pos] = x;
	ps->size++;
}

void SeqListDeleteByVal(SeqList* pst, ElemType key)
{
	assert(pst);
	int index = SeqListFind(pst, key);
	if (index == -1)
	{
		printf("Ҫɾ����Ԫ��%d�����ڣ�����ɾ��.\n", key);
		return;
	}
	//for(int i=index; i<pst->size; ++i)
	//	pst->base[i] = pst->base[i+1];
	//pst->size--;
	SeqListDeleteByPos(pst, index);
}

void SeqListDeleteByPos(SeqList* pst, int pos)
{
	//�ж�λ�õĺϷ���
	assert(pst && (pos >= 0 && pos < pst->size));
	for (int i = pos; i < pst->size; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}