#pragma once
#include "Sysutil.h"

#define ElemType int 

typedef struct DCListNode
{
	ElemType data;
	struct DCListNode* prev;
	struct DCListNode* next;
}DCListNode;

typedef struct DCList
{
	DCListNode* first;
	DCListNode* last;
	size_t      size;
}DCList;

DCListNode* _BuyDCListNode(ElemType x)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->next = s->prev = NULL;
	s->data = x;
	return s;
}

void DCListInit(DCList* plist);
void DCListPushBack(DCList* plist, ElemType x);
void DCListPushFront(DCList* plist, ElemType x);
void DCListShow(DCList* plist);
void DCListPopBack(DCList* plist);
void DCListPopFront(DCList* plist);
size_t DCListLength(DCList* plist);
void DCListClear(DCList* plist);
void DCListDestroy(DCList* plist);
DCListNode* DCListFind(DCList* plist, ElemType key);
void DCListDeleteByVal(DCList* plist, ElemType key);
void DCListReverse(DCList* plist);
void DCListInsertByVal(DCList* plist, ElemType x);

void DCListInit(DCList* plist)
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(0);
	plist->first = plist->last = s;

	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size = 0;
}

void DCListPushBack(DCList* plist, ElemType x)
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	s->prev = plist->last;
	plist->last->next = s;
	plist->last = s;

	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size++;
}

void DCListPushFront(DCList* plist, ElemType x)
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);

	s->next = plist->first->next;
	plist->first->next->prev = s;
	plist->first->next = s;
	s->prev = plist->first;

	if (plist->last == plist->first)
		plist->last = s;

	plist->size++;
}

void DCListShow(DCList* plist)
{
	DCListNode* p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void DCListPopBack(DCList* plist)
{
	assert(plist);
	DCListNode* p = plist->last;
	if (p != plist->first)
	{
		plist->last = p->prev;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;

		free(p);
		plist->size--;
	}
}

void DCListPopFront(DCList* plist)
{
	assert(plist);

	DCListNode* p;
	if (plist->size == 0)
		return;

	p = plist->first->next;

	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	plist->size--;
	if (plist->size == 0)
		plist->last = plist->first;

}

size_t DCListLength(DCList* plist)
{
	return plist->size;
}

void DCListClear(DCList* plist)
{
	assert(plist);
	DCListNode* p = plist->first->next;
	if (plist->size == 0)
		return;
	while (p != plist->first)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = plist->first->next;
	}
	plist->size = 0;
	plist->last = plist->first;
}
void DCListDestroy(DCList* plist)
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}

DCListNode* DCListFind(DCList* plist, ElemType key)
{
	assert(plist);
	DCListNode* p = plist->first->next;
	while (p != plist->first && p->data != key)
		p = p->next;
	if (p == plist->first)
		return NULL;
	return p;
}

void DCListDeleteByVal(DCList* plist, ElemType key)
{
	assert(plist);
	DCListNode* p = DCListFind(plist, key);
	if (p != NULL)
	{
		if (p == plist->last) //需要判断是否是最后一个节点
			plist->last = p->prev;

		p->prev->next = p->next;
		p->next->prev = p->prev;

		free(p);
		plist->size--;
	}
}

void DCListReverse(DCList* plist)
{
	assert(plist);
	DCListNode* p, * q;
	if (plist->size <= 1)
		return;

	p = plist->first->next;
	q = p->next;
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;

	while (q != plist->first)
	{
		p = q;
		q = q->next;

		p->next = plist->first->next;
		p->next->prev = p;
		p->prev = plist->first;
		p->prev->next = p;
	}
}

void DCListInsertByVal(DCList* plist, ElemType x)
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	DCListNode* p = plist->first->next;
	while (p != plist->first && x > p->data)
		p = p->next;
	if (p == plist->first)
		plist->last = s;

	s->next = p;
	s->prev = p->prev;
	s->prev->next = s;
	s->next->prev = s;
}