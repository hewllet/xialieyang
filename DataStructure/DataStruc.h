#pragma once
#define ElemType int
#define SElemType BiTree
#define QElemType BiTree
#define TElemType  char
#define Status int
#define FAILED 0
#define FALSE 0
#define OVERFLOW 0
#define ERROR 0
#define SUCCESS 1
#define TRUE 1
#define OK 1

#include<stdlib.h>
#include<stdio.h>

typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LNode, *LinkList;



//******************************************************************

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode*lchild, *rchild;
}BiTNode, *BiTree;

//******************************************************************

//*****************************************************************

#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
#define STACKINCREMENT 2 /* �洢�ռ�������� */
typedef struct SqStack
{
	SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
	SElemType *top; /* ջ��ָ�� */
	int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
}SqStack; /* ˳��ջ */

//*******************************************************************

		  /* c3-3.h ���е�˳��洢�ṹ(������ѭ�����кͷ�ѭ������) */
#define MAXQSIZE 5 /* �����г���(����ѭ�����У������г���Ҫ��1) */
typedef struct
{
	QElemType *base; /* ��ʼ���Ķ�̬����洢�ռ� */
	int front; /* ͷָ��,�����в���,ָ�����ͷԪ�� */
	int rear; /* βָ��,�����в���,ָ�����βԪ�ص���һ��λ�� */
}SqQueue;


