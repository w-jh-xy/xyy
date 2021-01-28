#pragma once
#include"Sysutil.h"

#define ElemType int
typedef struct DCListNode  //�������
{
	ElemType data;
	struct DCListNode* pre;
	struct DCListNode* next;
}DCListNode;

typedef struct DCList  //����ͷ���
{
	DCListNode* first;  //ָ������ĵ�һ����㣨ͷ����һ����㣩
	DCListNode* last;   //ָ����������һ�����
	size_t		size;   //���������
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

DCListNode* _BuyDCListNode(ElemType x)  //������
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
	DCListNode* s = _BuyDCListNode(0);//�����½ڵ�
	plist->first = plist->last = s;   //ͷ����ʼ��
	plist->last->next = plist->first;//��˫������β����
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










//��ͷ˫������
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
