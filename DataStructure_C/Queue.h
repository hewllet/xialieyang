#include"DataStruc.h"

Status InitQueue(SqQueue *Q)
{ /* ����һ���ն���Q */
	(*Q).base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if (!(*Q).base) /* �洢����ʧ�� */
		exit(OVERFLOW);
	(*Q).front = (*Q).rear = 0;
	return OK;
}

Status DestroyQueue(SqQueue *Q)
{ /* ���ٶ���Q,Q���ٴ��� */
	if ((*Q).base)
		free((*Q).base);
	(*Q).base = NULL;
	(*Q).front = (*Q).rear = 0;
	return OK;
}

Status ClearQueue(SqQueue *Q)
{ /* ��Q��Ϊ�ն��� */
	(*Q).front = (*Q).rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue Q)
{ /* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
	if (Q.front == Q.rear) /* ���пյı�־ */
		return TRUE;
	else
		return FALSE;
}

int QueueLength(SqQueue Q)
{ /* ����Q��Ԫ�ظ���,�����еĳ��� */
	return(Q.rear - Q.front);
}

Status GetHead(SqQueue Q, QElemType *e)
{ /* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
	if (Q.front == Q.rear) /* ���п� */
		return ERROR;
	*e = *(Q.base + Q.front);
	return OK;
}

Status EnQueue(SqQueue *Q, QElemType e)
{ /* ����Ԫ��eΪQ���µĶ�βԪ�� */
	if ((*Q).rear >= MAXQSIZE)
	{ /* ������������1���洢��Ԫ */
		(*Q).base = (QElemType *)realloc((*Q).base, ((*Q).rear + 1)*sizeof(QElemType));
		if (!(*Q).base) /* ���ӵ�Ԫʧ�� */
			return ERROR;
	}
	*((*Q).base + (*Q).rear) = e;
	(*Q).rear++;
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{ /* �����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
	if ((*Q).front == (*Q).rear) /* ���п� */
		return ERROR;
	*e = (*Q).base[(*Q).front];
	(*Q).front = (*Q).front + 1;
	return OK;
}

Status QueueTraverse(SqQueue Q, void(*QueueVisit)(QElemType))
{ /* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()��һ��viʧ��,�����ʧ�� */
	int i;
	i = Q.front;
	while (i != Q.rear)
	{
		QueueVisit(*(Q.base + i));
		i++;
	}
	//printf("\n");
	return OK;
}

Status QueueVisit(QElemType e){
	printf("%d\n", e);
	return 0;
}