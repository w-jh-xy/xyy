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
	//�����½ڵ㡢���ԡ���ʼ�������ؽڵ�ָ��
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
	//���ԡ������½�㡢��ֵ��������β��
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;

	SListNode* p = plist->head;
	if (p == NULL)  //��һ�����Ϊ�գ�ֱ�Ӳ���
		plist->head = s;
	else   //�����ҵ����һ����㣬��s����
	{
		while (p->next != NULL)
					p = p->next;
			p->next = s;
	}
}

void SListPushFront(SList* plist, ElemType x)
{
	//���ԡ������½�㡢��ֵ����ͷ��
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;
	s->next = plist->head;
	plist->head = s;
}

void SListPopBack(SList* plist)
{
	//���ԡ��пա��Ƿ�Ϊ��һ�����
	assert(plist);
	SListNode* p = plist->head;
	if (p != NULL)
	{
		if (p->next == NULL)  //��ֻ��һ�����
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
	//���ԡ��пա���head����
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
	//��ӡhead-����data
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
	//���ԡ���NULL
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
	//���ԡ����ұȶԡ�����
	assert(plist);
	SListNode* p = plist->head;
	while(p != NULL && p->data != key)
			p = p->next;	
	return p;
}

void SListClear(SList* plist)
{
	//���ԡ����ͷɾ��head�ÿ�
	assert(plist);
	SListNode* p = plist->head;
	while(p != NULL)
	{
		plist->head = p->next;  // ͷɾ
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
	//ֻ��ɾ����һ����ȵ�ֵ
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	while(p != NULL && p->data!=key)  //����������������
	{
		pre = p;
		p = p->next;
	}
	if (p != NULL)  //������������ȣ����Ƿ�Ϊ��һ�����
	{
		if (pre == NULL)  //ɾ����һ�����
			plist->head = p->next;
		else
			pre->next = p->next; 
		free(p);
	}
}

void SListInsertByVal(SList* plist, ElemType x)
{
	//���ԡ������㡢�ȴ�С����
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
		if (pre == NULL)  //ͷ��
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
	//�Ͽ������һ����㣬Ȼ�󽫺���������ͷ��
	assert(plist);
	SListNode* p, * q;
	if (plist->head == NULL || plist->head->next ==NULL)
		return;
	//����Ͽ�����,Ȼ������ͷ��
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
	SListNode* p, * q;  //p����ȽϺ�ȡ�½�㣬q����ά��ʣ������
	if (plist->head == NULL || plist->head->next == NULL)
		return;
	//�Ͽ�����
	p = plist->head->next;
	plist->head->next = NULL;

	q = p;
	while (q != NULL)
	{
		q = q->next;
		SListNode* t = plist->head;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data)  //����
		{
			pre = t;
			t = t->next;
		}
		if (pre == NULL)  //ͷ������
		{
			p->next = plist->head;
			plist->head = p;
		}
		else     //�м��β������
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
		while (p != NULL && p->data != key)  //����������������
			{
				pre = p;
				p = p->next;
			}
			if (p != NULL)  //������������ȣ����Ƿ�Ϊ��һ�����
			{
				if (pre == NULL)  //ɾ����һ�����
					plist->head = p->next;
				else
					pre->next = p->next; //ɾ���м����ȵĽ��
				free(p);
			}
			if (pre != NULL)   //��
			{
				p = pre->next;
			}
			else
			{
				p = plist->head; //��ͷ��ʼ����������Ƚ��ɾ��
			}

	}
}

//////////////////////////////////////////////////////////////////////////////////
//��ѭ������ --> �������
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
//˫������ 
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