#pragma once
#include"Sysutil.h"

#define ElemType int
typedef struct DCListNode  //创建结点
{
	ElemType data;
	struct DCListNode* pre;
	struct DCListNode* next;
}DCListNode;

typedef struct DCList  //创建头结点
{
	DCListNode* first;  //指向链表的第一个结点（头结点后一个结点）
	DCListNode* last;   //指向链表的最后一个结点
	size_t		size;   //链表结点个数
}DCList;

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

DCListNode* _BuyDCListNode(ElemType x)  //申请结点
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->next = s->pre = NULL;
	s->data = x;
	return s;
}

void DCListInit(DCList* plist)
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(0);//申请新节点
	plist->first = plist->last = s;   //头结点初始化
	plist->last->next = plist->first;//将双链表首尾相连
	plist->first->pre = plist->last;
	plist->size = 0;
}
void DCListPushBack(DCList* plist, ElemType x)
{
	//

}
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










//无头双向链表
typedef struct DListNode
{
	ElemType data;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

typedef struct DList
{
	DListNode* head;
}DList;

void DListInit(DList* plist);
void DListPushBack(DList* plist, ElemType x);
void DListPushFront(DList* plist, ElemType x);
void DListShow(DList* plist);
void DListPopBack(DList* plist);
void DListPopFront(DList* plist);
size_t DListLength(DList* plist);
void DListClear(DList* plist);
void DListDestroy(DList* plist);
DListNode* DListFind(DList* plist, ElemType key);
void DListDeleteByVal(DList* plist, ElemType key);
void DListReverse(DList* plist);
void DListInsertByVal(DList* plist, ElemType x);
