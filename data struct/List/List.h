#pragma once

#include"Sysutil.h"
#define ElemType int

typedef struct SListNode
{
	ElemType data;
	struct SListNode* next;
}SListNode;

typedef struct SList 
{
	SListNode* head;
}SList;

void SListInit(SList* plist);

void SListPushBack(SList* plist, ElemType x);
void SListPushFront(SList* plist, ElemType x);
void SListPopBack(SList* plist);
void SListPopFront(SList* plist);
void SListShow(SList* plist);

int SListLength(SList* plist);
SListNode* SListFind(SList* plist, ElemType key);
void SListClear(SList* plist);
void SListDestroy(SList* plist);

void SListDeleteByVal(SList* plist, ElemType key);
void SListInsertByVal(SList* plist, ElemType x);
void SListReverse(SList* plist);
void SListSort(SList* plist);
void SListRemoveAll(SList* plist, ElemType key);

SListNode* _Buynode()
{
	//申请新节点、断言、初始化、返回节点指针
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;
	s->next = NULL;
	return s;
}

void SListInit(SList* plist)
{
	plist->head = NULL;
}

void SListPushBack(SList* plist, ElemType x)
{
	//断言、申请新结点、赋值、找链表尾部
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;

	SListNode* p = plist->head;
	if (p == NULL)  //第一个结点为空，直接插入
		plist->head = s;
	else   //否则找到最后一个结点，将s插入
	{
		while (p->next != NULL)
					p = p->next;
			p->next = s;
	}
}

void SListPushFront(SList* plist, ElemType x)
{
	//断言、申请新结点、赋值、找头部
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;
	s->next = plist->head;
	plist->head = s;
}

void SListPopBack(SList* plist)
{
	//断言、判空、是否为第一个结点
	assert(plist);
	SListNode* p = plist->head;
	if (p != NULL)
	{
		if (p->next == NULL)  //若只有一个结点
			plist->head = NULL;
		else
		{
			SListNode* pre = NULL;
			while (p->next != NULL)
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
		}
		free(p);
	}
}

void SListPopFront(SList* plist)
{
	//断言、判空、将head后移
	assert(plist);
	SListNode* p = plist->head;
	if (p != NULL)
	{
		plist->head = p->next;
		free(p);
	}
}

void SListShow(SList* plist)
{
	//打印head-》的data
	SListNode* p = plist->head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("over.\n");
}

int SListLength(SList* plist)
{
	//断言、找NULL
	int length = 0;
	assert(plist);
	SListNode* p = plist->head;
	/*while (p->next != NULL)
	{
		++length;
		p = p->next;
	}*/
	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}

SListNode* SListFind(SList* plist, ElemType key)
{
	//断言、查找比对、返回
	assert(plist);
	SListNode* p = plist->head;
	while(p != NULL && p->data != key)
			p = p->next;	
	return p;
}

void SListClear(SList* plist)
{
	//断言、逐个头删、head置空
	assert(plist);
	SListNode* p = plist->head;
	while(p != NULL)
	{
		plist->head = p->next;  // 头删
		free(p);
		p = plist->head;
	}
}

void SListDestroy(SList* plist)
{
	SListClear(plist);  //
}

void SListDeleteByVal(SList* plist, ElemType key)
{
	//只能删除第一个相等的值
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	while(p != NULL && p->data!=key)  //不结束或不相等则后移
	{
		pre = p;
		p = p->next;
	}
	if (p != NULL)  //若不结束且相等，判是否为第一个结点
	{
		if (pre == NULL)  //删除第一个结点
			plist->head = p->next;
		else
			pre->next = p->next; 
		free(p);
	}
}

void SListInsertByVal(SList* plist, ElemType x)
{
	//断言、申请结点、比大小插入
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;
	
	if (plist->head == NULL)
		plist->head = s;
	else
	{
		SListNode* p = plist->head;
		SListNode* pre = NULL;
		while (p != NULL && p->data < x)
		{
			pre = p;
			p = p->next;
		}
		if (pre == NULL)  //头插
		{
			plist->head = s;
			s->next = p;
		}
		else
		{
			pre->next = s;
			s->next = p;
		}
	}
}

void SListReverse(SList* plist)
{
	//断开链表第一个结点，然后将后面结点依次头插
	assert(plist);
	SListNode* p, * q;
	if (plist->head == NULL || plist->head->next ==NULL)
		return;
	//否则断开链表,然后依次头插
	p = plist->head->next;
	plist->head->next = NULL;
	q = p;
	while (q != NULL)
	{
		q = q->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}

void SListSort(SList* plist)
{
	assert(plist);
	SListNode* p, * q;  //p负责比较和取下结点，q负责维护剩余链表
	if (plist->head == NULL || plist->head->next == NULL)
		return;
	//断开链表
	p = plist->head->next;
	plist->head->next = NULL;

	q = p;
	while (q != NULL)
	{
		q = q->next;
		SListNode* t = plist->head;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data)  //插入
		{
			pre = t;
			t = t->next;
		}
		if (pre == NULL)  //头部插入
		{
			p->next = plist->head;
			plist->head = p;
		}
		else     //中间或尾部插入
		{
			p->next = pre->next;
			pre->next = p;
		}
		p = q;
	}
}

void SListRemoveAll(SList* plist, ElemType key)
{
	//
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	while (p != NULL) 
	{
		while (p != NULL && p->data != key)  //不结束或不相等则后移
			{
				pre = p;
				p = p->next;
			}
			if (p != NULL)  //若不结束且相等，判是否为第一个结点
			{
				if (pre == NULL)  //删除第一个结点
					plist->head = p->next;
				else
					pre->next = p->next; //删除中间的相等的结点
				free(p);
			}
			if (pre != NULL)   //？
			{
				p = pre->next;
			}
			else
			{
				p = plist->head; //从头开始继续查找相等结点删除
			}

	}
}

//////////////////////////////////////////////////////////////////////////////////
//单循环链表 --> 自行完成
typedef struct SCListNode
{
	ElemType data;
	struct SCListNode* next;
}SCListNode;

typedef struct SCList
{
	SCListNode* head;
}SCList;
void SCListInit(SCList* plist);
void SCListPushBack(SCList* plist, ElemType x);
void SCListPushFront(SCList* plist, ElemType x);
void SCListPopBack(SCList* plist);
void SCListPopFront(SCList* plist);
void SCListShow(SCList* plist);

int SCListLength(SCList* plist);
SCListNode* SCListFind(SCList* plist, ElemType key);
void SCListClear(SCList* plist);
void SCListDestroy(SCList* plist);

void SCListDeleteByVal(SCList* plist, ElemType key);
void SCListInsertByVal(SCList* plist, ElemType x);
void SCListReverse(SCList* plist);

void SCListSort(SCList* plist);
void SCListRemoveAll(SCList* plist, ElemType key);

/////////////////////////////////////////////////////////////////////////////////////
//双向链表 
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

/////////////////////////////////////////////////////////////////////////////////////