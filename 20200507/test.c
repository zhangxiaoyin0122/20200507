#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
int GetMid(int* array, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	if (array[begin] > array[mid]) {
		if (array[mid] > array[end])
			return mid;
		else {
			if (array[begin] > array[end])
				return end;
			else
				return begin;
		}
	}
	else {
		if (array[mid] < array[end])
			return mid;
		else {
			if (array[begin] > array[end])
				return begin;
			else
				return end;
		}
	}
}
void Swap(int* array, int begin, int end) {
	int tmp = array[begin];
	array[begin] = array[end];
	array[end] = tmp;
}
int partion(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	Swap(array, begin, mid);
	int prev = begin;
	int cur = prev + 1;
	int key = array[begin];
	while (cur <= end) {
		if (array[cur] < key&&++prev != cur)
			Swap(array, prev, cur);
		cur++;
	}
	Swap(array, begin, prev);
	return prev;
}

//递归实现快排
void quickSort(int* array, int begin, int end) {
	if (begin >= end)
		return;
	int keypos = partion(array, begin, end);
	quickSort(array, begin, keypos - 1);
	quickSort(array, keypos + 1, end);
}
//利用栈非递归实现快排
void quickSortNor(int* array, int n){
	Stack sk;
	StackInit(&sk, 10);
	if (n > 1) {
		StackPush(&sk,n-1);
		StackPush(&sk, 0);
	}
	while (StackEmpty(&sk) != 1) {
		int begin = StackTop(&sk);
		StackPop(&sk);
		int end = StackTop(&sk);
		StackPop(&sk);
		int keypos = partion(array, begin, end);
		if (keypos + 1 < end) {
			StackPush(&sk, end);
			StackPush(&sk, keypos + 1);
		}
		if(begin < keypos-1){
			StackPush(&sk, keypos - 1);
			StackPush(&sk, begin);
		}
	}
}
void test() {
	int array[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size = sizeof(array) / sizeof(array[0]);
	quickSortNor(array,size);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
}

int main() {
	test();
	system("pause");
	return 0;
}