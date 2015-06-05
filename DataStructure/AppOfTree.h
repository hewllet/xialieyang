/*线索二叉树 赫夫曼树 
*/
#include"DataStruct.h"

BiThrTree gPreNode;//线索结点

/***线索二叉树***/
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
		//因为指向后继需要先遍历到后继，因为是中序遍历，所以只有访问父节点时的前一个结点为T的后继
		if (!gPreNode->rchild){
			gPreNode->rtag = Thread;
			gPreNode->rchild = T;//T的父节如果右孩子为空，则指向T
		}
		gPreNode = T;
		InThreading(T->rchild);
	}
}


void InorderThreading( BiThrTree *thrNode,BiThrTree T  ){
	//thrNode为线索,T为树的根
	//因为要改变BithrTree的指针指向，所以传入指针的指针
	 *thrNode = (BiThrTree)malloc(sizeof(BiThrNode));
	(*thrNode)->rtag = Thread;
	(*thrNode)->ltag = Link;
	(*thrNode)->rchild = *thrNode;//thrNode左孩子指T，右孩子指自身
	if (!T)(*thrNode)->lchild = *thrNode;
	else{
		T = (*thrNode)->lchild;
		gPreNode = *thrNode;
		InThreading(T);
		/*线索后处理，回指*/
		gPreNode->rtag = Thread;
		gPreNode->rchild = *thrNode;
		(*thrNode)->rchild = gPreNode;
	}
}



/*哈夫曼编码*/

