#pragma once
// slist.h
#include"Sysutil.h"
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;



// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SList* plist);



// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s);
	s->data = x;
	s->next = NULL;
	return s;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	assert(plist);
	SListNode* p = plist;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("over.\n");
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	//断言、申请结点、赋值、找到链表尾部插入
	assert(pplist);
	SListNode* s = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = s;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = s;
	}
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	SListNode* prev = NULL;
	SListNode* tail = *pplist;
	if (tail == NULL || tail->next == NULL) //空或只有一个
	{
		free(tail);
		*pplist = NULL;
	}
	else
	{
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	SListNode* first = *pplist;
	if (first == NULL)
	{
		return;
	}
	else if (first->next == NULL)
	{
		free(first);
		*pplist = NULL;
	}
	else
	{
		SListNode* nextnode = first->next;
		free(first);
		*pplist = nextnode;
	}
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* cur = plist;
	while (cur != NULL && cur->data != x)
	{
		cur = cur->next;
	}
	return cur;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* nextnode = pos->next;
	SListNode* newnode = BuySListNode(x);
	pos->next = newnode;
	newnode->next = nextnode;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* nextnode = pos->next;
	if (nextnode != NULL)
	{
		SListNode* nextnext = nextnode->next;
		free(nextnode);
		pos->next = nextnext;
	}
}
// 单链表的销毁
void SListDestory(SListNode** pplist)
{
	assert(pplist);
	SListNode* first = *pplist;
	if (first == NULL)
	{
		return;
	}
	else if (first->next == NULL)
	{
		free(first);
		*pplist = NULL;
	}
	else
	{
		while (first->next != NULL)
		{
			SListNode* nextnode = first->next;
					free(first);
					*pplist = nextnode;
		}
		
	}

}