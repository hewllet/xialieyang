/*���������� �շ����� 
*/
#include"DataStruct.h"

BiThrTree gPreNode;//�������

/***����������***/
void CreateBiThrTree(BiThrTree *T){
	char c;
	scanf("%c", &c);
	if (' ' == c)
		*T = NULL;
	else{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		(*T)->data = c;
		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}

void InThreading(BiThrTree T){
	if (T){
		InThreading(T->lchild);
		if (!T->lchild){
			T->ltag = Thread;
			T->lchild = gPreNode;
		}
		//��Ϊָ������Ҫ�ȱ�������̣���Ϊ���������������ֻ�з��ʸ��ڵ�ʱ��ǰһ�����ΪT�ĺ��
		if (!gPreNode->rchild){
			gPreNode->rtag = Thread;
			gPreNode->rchild = T;//T�ĸ�������Һ���Ϊ�գ���ָ��T
		}
		gPreNode = T;
		InThreading(T->rchild);
	}
}


void InorderThreading( BiThrTree *thrNode,BiThrTree T  ){
	//thrNodeΪ����,TΪ���ĸ�
	//��ΪҪ�ı�BithrTree��ָ��ָ�����Դ���ָ���ָ��
	 *thrNode = (BiThrTree)malloc(sizeof(BiThrNode));
	(*thrNode)->rtag = Thread;
	(*thrNode)->ltag = Link;
	(*thrNode)->rchild = *thrNode;//thrNode����ָT���Һ���ָ����
	if (!T)(*thrNode)->lchild = *thrNode;
	else{
		T = (*thrNode)->lchild;
		gPreNode = *thrNode;
		InThreading(T);
		/*����������ָ*/
		gPreNode->rtag = Thread;
		gPreNode->rchild = *thrNode;
		(*thrNode)->rchild = gPreNode;
	}
}



/*����������*/

