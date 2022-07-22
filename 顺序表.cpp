#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;

typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;

bool ListInsert(SqList& L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1)
	{
		return false;
	}
	if (L.length >= MaxSize)
	{
		return false;
	}
	for (int j = L.length; j >= i; j--) //移动顺序表中的元素，依次往后移动
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//数组下标从0开始，插入第一个位置，下标为0
	L.length++;
	return true;
}
void PrintList(SqList& L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%3d",L.data[i]);
	}
	printf("\n");
}
bool ListDelete(SqList& L, int i, ElemType &e)
{
	if (i<1 || i>L.length)
	{
		return false;
	}
	if (L.length == 0)
	{
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}
int LocateElem(SqList L, ElemType e)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;//+1是元素在表中的位置
		}
	}
	return 0;
}
int main()
{
	SqList L;
	bool ret_1;//查看返回值
	bool ret_2;
	ElemType del;//存放被删除的元素
	int add_p;
	int del_p;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;
	scanf("%d", &add_p);
	ret_1 = ListInsert(L,2,add_p);//往第二个位置插入60这个元素
	if (ret_1)
	{
		printf("插入成功\n");
		PrintList(L);
	}
	else
	{
		printf("插入失败\n");
	}
	scanf("%d", &del_p);
	ret_2 = ListDelete(L, 2,del_p);
	if (ret_2)
	{
		printf("删除成功\n");
		printf("删除元素值为%d\n", del_p);
		PrintList(L);
	}
	else {
		printf("删除失败\n");
	}
	int elem_pos;
	elem_pos = LocateElem(L, 1);
	if (elem_pos)
	{
		printf("查找成功\n");
		printf("元素位置为%d\n", ret_1);
	}
	else
	{
		printf("查找失败\n");
	}
	return 0;
}