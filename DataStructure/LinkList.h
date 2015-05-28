//xixi 2015年1月23日22:08:46
#include"DataStruc.h"
#include<stdlib.h>
Status InitLIst_L(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!*L)
		return FAILED;
	else
		(*L)->next = NULL;
	return SUCCESS;
}

Status CreateListTail_L(LinkList *L, int n)//尾插法
{

	int i = 0;
	LinkList p1, p2;
	if (n < 1)
		return FAILED;
	p1 = (LinkList)malloc(sizeof(LNode));
	p2 = (LinkList)malloc(sizeof(LNode));
	(*L)->next=p1;
	p2 = p1;
	p2->next = NULL;
	scanf("%d", &p1->data);
	for (; i < n - 1; i++)
	{
		p1 = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p1->data);
		p2->next = p1;
		p1->next = NULL;
		p2 = p1;
	}
	return SUCCESS;
}

Status CreateListHead_L(LinkList *L, int n)//逆位序输入n个值,头插法
{
	LinkList p;
	int i;
	for (i = n; i > 0; i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = (*L)->next;  
		(*L)->next = p;
		
	}
	return SUCCESS;
}

Status DestoryList_L(LinkList *L)
{
	LinkList p;
	while (*L)
	{
		p = (*L)->next;
		free(*L);
		*L = p;
	}
	return SUCCESS;
}

Status ClearList_L(LinkList *L)
{
	LinkList p1, p2;
	p1 = (*L)->next;
	while (p1)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	(*L)->next = NULL;
	return SUCCESS;
}

Status ListEmpty_L(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return	TRUE;
}

int  ListLength_L(LinkList L)
{
	int count;
	while (L->next)
	{
		count++;
		L = L->next;
	}
	return count;
}

Status GetElem_L(LinkList L, int i, ElemType *e)
{
	LinkList p = L;
	for (; i > 0; i--)
	{
		p = p->next;
		i--;
	}
	if (p)
	{
		*e = p->data;
		return SUCCESS;
	}
	else
		return FAILED;
}
Status LocateElem_L(LinkList L, ElemType *e, Status(*compare)(ElemType, ElemType))
{
	LinkList p = L->next;
	while (p != NULL&&!(compare(p++->data, *e)));
	if (p&&compare(p->data, *e))
		return SUCCESS;
	else
		return FAILED;
}

Status PriorElem_L(LinkList L, ElemType cur_e, ElemType *pre_e)//注意条件,cur_e不为第一个元素
{
	LinkList p = L->next;
	while (p->next != NULL&&p++->next->data != cur_e);
	if (p->next&&p->next->data == cur_e)
	{
		*pre_e = p->data;
		return SUCCESS;
	}
	else
		return FAILED;
}

Status NextElem_L(LinkList L, ElemType cur_e, ElemType *next_e)//cur_e不为最后一个元素
{
	LinkList p = L->next;
	while (p->next&&p++->data != cur_e);
	if (p->next&&p->data == cur_e)
	{
		*next_e = p->next->data;
		return SUCCESS;
	}
	else
		return FAILED;
}

Status ListInsert_L(LinkList *L, int i, ElemType e)//要考虑i值是否合法 找前驱
{
	LinkList p1, p2, q;
	if (i < 1)
		return FAILED;
	q = (LinkList)malloc(sizeof(LNode));
	p1 = *L;
	while (i--)
	{
		p2 = p1;
		p1 = p1->next;//p2为前一结点,q为待插入结点
	}
	q->next = p2->next;
	p2->next = q;
	q->data = e;
}

Status ListDelete_L(LinkList *L, int i, ElemType *e)
{
	LinkList p1, p2;
	if (i < 1)
		return FAILED;
	p1 = *L;
	while (i--)
	{
		p2 = p1;
		p1 = p1->next;//p2为前一结点,q为待插入结点
	}
	p2->next = p1->next;
	free(p1);//p1不为null；
	p1 = NULL;
	return SUCCESS;
}
Status ListTraverse_L(LinkList L, Status(*ListVisit)(ElemType))//对结点元素的访问不是接结点
{
	LinkList p = L->next;
	while (p)
	{
		ListVisit(p->data);
		p = p->next;
	}
	return SUCCESS;
}

Status ListVisit(ElemType elem) {

	printf("%d\t", elem);
	return 0;
}