#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;//前驱，后继
}DNode,*DLinkList;

//头插法建立双向链表
DLinkList Dlist_head_insert(DLinkList& DL)
{
	DNode* s; //申请新空间
	int x;
	DL = (DLinkList)malloc(sizeof(DNode));//带头结点的链表
	DL->prior = NULL;
	DL->next = NULL;
	scanf("%d", &x);//3 4 5 6 7 9999
	while (x != 9999)
	{
		s=(DLinkList)malloc(sizeof(DNode));
		s->data = x;
		s->next = DL->next;
		if (DL->next != NULL)
		{
			DL->next->prior = s;
		}
		s->prior = DL;//让要插入的节点指向前一个节点
		DL->next = s;
		scanf("%d", &x);
	}
	return DL;
}

DLinkList Dlist_tail_insert(DLinkList& DL)
{
	int x;//存放输入的数据
	DL = (DLinkList)malloc(sizeof(DNode));
	DNode* s, * r = DL; //DLinkList s, r也可以，s是新空间，r是表尾指针
	DL->prior = NULL;
	scanf("%d", &x);
	while(x != 9999)
	{
		s = (DLinkList)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;//尾结点的指针域赋值尾NULL
	return DL;
}
DNode* GetElem(DLinkList DL, int i)
{
	int j = 1;
	DNode* p = DL->next;
	if (i == 0)
	{
		return DL;
	}
	if (i < 1) {
		return NULL;
	}
	while(p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//第i个位置插入e元素
bool DListFrontInsert(DLinkList DL, int i, ElemType e)
{
	DLinkList p = GetElem(DL, i - 1);
	if (NULL == p)
	{
		return false;
	}
	DLinkList s = (DLinkList)malloc(sizeof(DNode));
	s->data = e;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}
bool DListDelete(DLinkList DL, int i)
{
	DLinkList p = GetElem(DL, i - 1);
	if (NULL == p)
	{
		return false;
	}
	DLinkList q;
	if (q == NULL)
	{
		return false;
	}
	p->next = q->next;
	if (q->next != NULL)
	{
		q->next->prior = p;
	}
	free(q);
	return true;
}
void PrintDList(DLinkList DL)
{
	DL = DL->next;
	while (DL != NULL)
	{
		printf("%3d", DL->data);
		DL = DL->next;
	}
	printf("\n");
}
int main()
{
	DLinkList DL;
	DLinkList search;
	//Dlist_head_insert(DL);//头插法
	Dlist_tail_insert(DL);//尾插法
	PrintDList(DL);
	search = GetElem(DL, 2);
	if (search != NULL)
	{
		printf("按序号查找成功\n");
		printf("%d\n", search->data);
	}
	DListFrontInsert(DL, 3, 99);
	PrintDList(DL);
	DListDelete(DL, 2);
	PrintDList(DL);
	return 0;
}