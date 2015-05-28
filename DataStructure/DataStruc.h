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

#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACKINCREMENT 2 /* 存储空间分配增量 */
typedef struct SqStack
{
	SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
	SElemType *top; /* 栈顶指针 */
	int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack; /* 顺序栈 */

//*******************************************************************

		  /* c3-3.h 队列的顺序存储结构(可用于循环队列和非循环队列) */
#define MAXQSIZE 5 /* 最大队列长度(对于循环队列，最大队列长度要减1) */
typedef struct
{
	QElemType *base; /* 初始化的动态分配存储空间 */
	int front; /* 头指针,若队列不空,指向队列头元素 */
	int rear; /* 尾指针,若队列不空,指向队列尾元素的下一个位置 */
}SqQueue;


