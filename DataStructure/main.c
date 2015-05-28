//#include"Queue.h"
//#include"Stack.h"
#include"BinaryTree.h" // defined queue.h
#include "Sort.h"

int main()
{
	int i;
	int a[] = { 24, 23, -123, 123, 44, 2, 67, 8, 56, 908, 54312543, 45, 132,-123123,-1,3435 };
	//int a[] = { 24, 23, -123, 123, 44, 2, 67, 8, 56 };
   	//int a[] = { 24, 23, -123, 123, 44, 2 };
    //int a[] = { 123, 44 };
	int n = sizeof(a) / sizeof(int);
	//Quicksort(a, 0, n - 1);
	//Shellsort(a, n);
	RadixSort(a, n);
	//Heapsort(a, n-1);
	//Insertsort(a, n);
	//for (i = 0; i < n; i++)printf("%d  ", a[i]);
	return 0;
	
}


