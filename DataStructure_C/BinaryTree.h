#include"DataStruct.h"
#include "Queue.h"
#include"Stack.h"
Status InitBiTree(BiTree *T){
	*T = NULL;
	return OK;
}

void DestroyBiTree(BiTree *T){
	if (*T)
	{
		if((*T)->lchild)
		DestroyBiTree(&(*T)->lchild);
		if ((*T)->rchild)
			DestroyBiTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}

Status CreateBiTree(BiTree *T){
	TElemType node;
	scanf("%c", &node);
	if (node == ' ') *T = NULL;
	else{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		if (!*T) exit(OVERFLOW);
		(*T)->data = node;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);

	}			
}

Status BiTreeEmpty(BiTree T){ 
	if (T)
		return FALSE;
	else
		return TRUE;
}

TElemType Root(BiTree T){ 
	if (BiTreeEmpty(T))
		return 0;
	else
		return T->data;
}



Status PreorderTraverse(BiTree T, Status(*TreeVisit)(TElemType e)){
	SqStack S;
	SElemType e;
	InitStack(&S);
	while (T || !StackEmpty(S)) {
		if (!T) {
			Pop(&S, &e);
			T = e;
		}
		else {
			TreeVisit(T->data);
			if(T->rchild)
			Push(&S,T->rchild);
			T = T->lchild;
		}
	}

}

Status InorderTraverse(BiTree T, Status(*TreeVisit)(TElemType e)){
	SqStack S;
	SElemType e;
	InitStack(&S);
	while (T || !StackEmpty(S)) {
		if (!T) {
			Pop(&S, &e);//�ýڵ�������Ϊ�գ������ý��
			T = e;
			TreeVisit(T->data);//����ý��
			T = T->rchild;//����ý���������
		}
		else {
			Push(&S, T);//����������ջ
			T = T->lchild;
		}

	}
}

Status PostorderTraverse(BiTree T, Status(*TreeVisit)(TElemType e)){
	SqStack S;
	SElemType e, tmp, root = T;
	InitStack(&S);
	while (T||!StackEmpty(S)) {
		if (!T) {
			GetTop(S, &T);
			if ((T = T->rchild) == NULL) {  //ȷ���ý��������Ϊ��,����Ϊ��������ֵ
				Pop(&S, &T); TreeVisit(T->data);
				if (T == root) return;
				if (!StackEmpty(S)) {
					GetTop(S, &tmp);
					while (T == tmp->rchild) {
						Pop(&S, &T); TreeVisit(T->data);
						if (root == T)return;
						GetTop(S, &tmp);
					}//�ж��Ƿ��������ѱ�����
					GetTop(S, &tmp); T = tmp->rchild;
				}
				else return;
			}
		}	
		else {
			Push(&S, T);
			T = T->lchild;
		}
	}
	return;
}

Status LevelOrderTraverse(BiTree T, Status(*TreeVisit)(TElemType e)){
	SqQueue Q;
	QElemType e;
	InitQueue(&Q);
	if (T) EnQueue(&Q, T);
	while (!QueueEmpty(Q)) {
		DeQueue(&Q, &e);
		T = e;
		TreeVisit(T->data);
		if (T->lchild)EnQueue(&Q, T->lchild);
		if (T->rchild)EnQueue(&Q, T->rchild);
	}
}

void TreeVisit(TElemType e){
	printf("%c\n", e);

}