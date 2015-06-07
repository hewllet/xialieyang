#include<stdlib.h>
void Swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


int NPosition(int num, int n){
	if (n > 1)
		return (num / ((n - 1) * 10)) % 10;
	else
		return num % 10;
}

int FindMaxDig(int a[], int n){
	int i, dig, max;
	max = *a, dig = 0;;
	for (i = 1; i < n; i++)
	if (a[i]>max)max = a[i];
	while (max){
		max /= 10; dig++;
	}
	return dig;
}

void RadixSort(int a[], int len){
	int i, j, k, id, pos;
	id = 0; k = 0;
	int buckets[9][20] = { 0 };
	int max_dig = FindMaxDig(a, len);
	for (i = 1; i <=max_dig; i++){
		for (j = 0; j <len; j++){
			pos = NPosition(a[j], i);
			while (buckets[pos][k])k++;
			buckets[pos][k] = a[j];
			k = 0;
		}
		for (j = 0; j < 9; j++){
			for (k = 0;k<20;k++)
			if (buckets[j][k] == 0)
				break;
			else
				a[id++] = buckets[j][k];
		}
	}
}



/*-------------------------
*Name:������
*Data:2015/06/05
--------------------------*/
void HeapSwap(int a[], int max, int tail){
	int tmp;
	tmp = a[max];
	a[max] = a[tail];
	a[tail] = tmp;
}

void HeadAdjust(int a[], int s, int n){
	int i, tmp;
	tmp = a[s];//sΪ���ڵ�iΪ�ӽڵ�
	for (i = 2 * s; i <=n; i *= 2){
		if (i < n&&a[i] < a[i + 1])
			i++;
		if (tmp >= a[i])
			break;
		a[s] = a[i];	s = i;//��ǰ�ı�Ŀ��ܶ��ӽڵ����Ӱ��
	}
	a[s] = tmp;
}

void Heapsort(int a[],int len){
	int i;
	for (i = len / 2; i >=0; i--)
		HeadAdjust(a, i, len);//��������


	for (i = len; i >= 1; i--){
		HeapSwap(a, 0, i);
		HeadAdjust(a, 0, i - 1);
	}//������Ժ󣬾͵�һλ�����Ԫ�أ������һλ�����������ĩβ���������������������
}




/*-----------------------
*Name:�鲢����(�ݹ�)
*Data:2015/06/05
------------------------*/
void merging(int *list1,int list1_size,int *list2,int list2_size,int array_size){
	int i, j, k, m;
	int *tmp = (int *)malloc(sizeof(int)*array_size);
	i = j = k = 0;
	while (i < list1_size &&j< list2_size){
		if (list1[i] < list2[j])
			tmp[k++] = list1[i++];
		else
			tmp[k++] = list2[j++];
	}
	while (i < list1_size)
		tmp[k++] = list1[i++];
	while (j < list2_size)
		tmp[k++] = list2[j++];
	for (m = 0; m < list1_size + list2_size; m++)
		list1[m] = tmp[m];
}

void Mergesort(int *a,int n){
	if (n>1){
		int *list1 = a;
		int list1_size = n / 2;
		int *list2 = a + n / 2;
		int list2_size = n - list1_size;
		Mergesort(list1, list1_size);
		Mergesort(list2, list2_size);
		merging(list1, list1_size, list2, list2_size, n);
	}
}


/*-----------------------
*Name:��������
*Data:2015/06/05
-------------------------*/
void Quicksort(int *a, int sta, int end)
{
	int i;
	int flag, tmp, low, high;
	low = sta; high = end;
	tmp = sta;//��һ���պͱ�ʶ������λԪ��
	flag = a[sta];
	sta++;
	if (sta <= end){
		while (sta <= end)
		if (a[end] < flag) {
			a[tmp] = a[end];
			tmp = end;//update blank
			end--;
			while (a[sta] < flag&&sta <= end)
				sta++;//�ҵ���flag���Ϊֹ
			if (sta <= end){
				a[tmp] = a[sta]; tmp = sta;
			}//�ҵ�
			sta++;
		}//if
		else end--;
		a[tmp] = flag;//���flag���մ�
		Quicksort(a, low, tmp - 1);
		Quicksort(a, tmp + 1, high);
	}
	}



/*-----------------------
*Name:��������
*Data:2015/06/05
------------------------*/
void Insertsort(int *a, int n)
{
	int i, j, k, tmp;
	for (i = 1; i < n; i++){
		if (a[i] < a[i-1])//��ǰǰ����Ǹ�Ԫ�ؾ��Ƿֽ磬��flag
			//move,insert
		for (j = 0; j < i; j++)
		if (a[i] < a[j]){
			tmp = a[i];
			//j֮��i֮ǰ�ĺ���
			for (k = i - 1; k >= j; k--)
				a[k + 1] = a[k];
			a[j] = tmp;//insert			
		}//if
	}//for
}


/*-----------------------
*Name:shell����
*Data:2015/06/05
-------------------------*/
void Shellsort(int *a,int n)
{
	int i, j, k, gap = n / 2, tmp;
	for (; gap > 0; gap /= 2)
		for (i = gap; i < n; i += gap){
			//ֱ�Ӳ�������
			if (a[i] < a[i - gap]){
				for (j = 0; j<i; j += gap)
				if (a[j]>a[i]){
					tmp = a[i];
					for (k = i - gap; k >= j; k -= gap)
						a[k + gap] = a[k];
					a[j] = tmp;
				}//if
			}
		}//for
}
/*-----------------------
*Name:ð������
*Data:2015/06/05
-------------------------*/
void Bubblesort(int *a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	for (j = 1; j<n - i; j++)
	if (a[j - 1] > a[j])  Swap(&a[j - 1], &a[j]);
}



/*------------------------
*Name:ѡ������
*Data:2015/06/05
--------------------------*/
void Selectsort(int *a,int n)
{
	int i, j, id;
	for (i = 0; i< n; i++){
		id = i; //��Ϊi֮ǰ�Ѿ��ź�
		for (j = i; j < n; j++)
		if (a[id]>a[j])  id = j;//��¼��С���±�
		if (id != i)  Swap(&a[i], &a[id]);
	}
}


