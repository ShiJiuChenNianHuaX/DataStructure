#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

//头插法新建单链表
bool CreateList1(LinkList &L)
{
	LNode* s; //申请新节点s，包含data域和next指针域
	int x;//存放读取到的数据
	L = (LinkList)malloc(sizeof(LNode));//申请带头结点的链表
	L->next = NULL;//L->data内没有放东西
	scanf("%d", &x);//从标准输入读取数据
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//申请新空间给s
		s->data = x;//把读取到的值给申请的新空间中的data成员
		s->next = L->next;//把新节点的指针指向链表中第一个元素的下一个元素位置
		L->next = s;//把新空间的值赋值给链表的第一个元素（非头结点），这时候s的值就是第一个元素
		scanf("%d", &x);
	}
	return L;
}
//尾插法建立链表
bool CreastList2(LinkList& L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode)); //申请带头结点的链表
	LNode* s, * r = L;//LinkList s,r = L也可以.r代表表尾结点，指向链表尾部，s代表新节点
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//申请新空间赋给s
		s->data = x;
		r->next = s;//让尾部结点指向新结点
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;//尾插法尾指针必须为NULL
	return L;
}

//按序号查找
LinkList GetElem(LinkList L, int i) //i表示要查找元素的位置，i==0表示头结点
{
	int j = 1; //遍历列表
	LinkList p = L->next; //让p指向第一个元素，原本p指向头结点
	if (0 == i)
	{
		return L;
	}
	if (i < 1)
	{
		return NULL; 
	}
	while (p && j < i)
	{
		p = p->next;//让p指向下一个节点
		j++;
	}
	return p;
}

//按值查找
LinkList LocateElem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p -> next;
	}
	return p;
}

//往第i个位置插入元素
bool LinkFrontInsert(LinkList L, int i, ElemType e)
{
	LinkList p = GetElem(L, i - 1);//获取索要插入位置的前一个节点的地址值
	if (NULL == p)
	{
		return false;//i不对
	}
	LinkList s = (LinkList)malloc(sizeof(LNode)); //给新节点申请空间
	s->data = e;//把插入的值放入对应的空间
	s->next = p -> next;
	p->next = s;
	return true;
}
//删除第i个位置的元素
bool ListDelete(LinkList L, int i)
{
	LinkList p = GetElem(L, i - 1); //查找删除未知的前驱结点
	if (NULL == p)
	{
		return false;
	}
	LinkList q = p->next;
	if (NULL == q)
	{
		return false; //要删除的节点不存在
	}
	p -> next = q->next;
	free(q);
	q = NULL;
	return true;
}
void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);
		L = L->next;
	}
}
int main()
{
	LinkList L;//创建一个链表头，结构体指针类型
	LinkList GetElem_search;//存储拿到的某个结点
	LinkList LocateElem_search;//存储拿到的某个结点
	CreateList1(L);//头插法建立列表
	PrintList(L);
	GetElem_search = GetElem(L, 2);
	if (GetElem_search != NULL)
	{
		printf("按序号查找成功\n");
		printf("%d\n", GetElem_search->data);
	}
	LocateElem_search = LocateElem(L, 6);
	if (LocateElem_search != NULL)
	{
		printf("按值查找成功\n");
		printf("%d\n", LocateElem_search->data);
	}
	LinkFrontInsert(L, 2, 99);
	PrintList(L);
	ListDelete(L, 4);//删除第四个结点
	printf("----------");
	PrintList(L);
	return 0;
}