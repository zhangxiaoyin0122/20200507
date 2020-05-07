#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack* sk, int n) {
	sk->_array = (Type*)malloc(sizeof(Type)*n);
	sk->_capacity = n;
	sk->_size = 0;
}
void StackPush(Stack* sk, Type data) {
	if (sk->_size == sk->_capacity) {
		sk->_capacity *= 2;
		sk->_array = (Type*)realloc(sk->_array, sizeof(Type)*sk->_capacity);
	}
	sk->_array[sk->_size++] = data;
}
void StackPop(Stack* sk) {
	if (sk->_size > 0) {
		sk->_size--;
	}
}
Type StackTop(Stack* sk) {
		return sk->_array[sk->_size - 1];
}
int StackEmpty(Stack* sk) {
	if (sk->_size == 0)
		return 1;
	return 0;
}
void StackDestory(Stack* sk) {
	free(sk->_array);
	sk->_array = NULL;
	sk->_capacity = sk->_size = 0;
}
