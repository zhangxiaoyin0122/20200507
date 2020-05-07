#pragma once

typedef int Type;
typedef struct Stack{
	 Type* _array;
	 int _size;
	 int _capacity;
}Stack;

 void StackInit(Stack* sk,int n);
 void StackPush(Stack* sk, Type data);
 void StackPop(Stack* sk);
 Type StackTop(Stack* sk);
 int StackEmpty(Stack* sk);
 void StackDestory(Stack* sk);
