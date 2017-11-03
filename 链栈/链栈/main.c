//
//  main.c
//  链栈
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/11/3.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false -1

typedef struct LinkListNode
{
    int data;
    struct LinkListNode *next;
}LLN, *pLLN;

typedef struct LinkListStack
{
    pLLN top;
    int count;
}Stack, *pStack;

void InitStack(pStack S);        //    初始化栈的函数
void Push(pStack S,int info);            //    进行压栈操作的函数
void TraverseStack(pStack S);    //    遍历栈函数
int Empty(pStack S);            //    判断栈是否为空的函数
int Pop(pStack S);                //    进行出栈操作的函数
void Clear(pStack S);            //    清空栈的函数


void InitStack(pStack S)
{
    S->top = (pLLN)malloc(sizeof(LLN));
    S->top = NULL;
    S->count = 0;
}

void Push(pStack S, int info)
{
    pLLN node = (pLLN)malloc(sizeof(LLN));
    node->data = info;
    node->next = S->top;
    S->top = node;
    S->count++;
}

void TraverseStack(pStack S)
{
    pLLN node = NULL;
    node = S->top;
    int i;
    for(i = 0; i < S->count; i++){
        printf("%d ", node->data);
        node = node->next;
    }
}

int Empty(pStack S)
{
    if(S->count == 0)
        return true;
    else
        return false;
}

int Pop(pStack S)
{
    pLLN node;
    if(Empty(S)){
        node = S->top;
        S->top = S->top->next;
        free(node);
        S->count--;
        return true;
    }
    return false;
}

int main()
{
    pStack S;
    printf("%d  ", S->count);
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    printf("%d ", S->count);
    TraverseStack(S);
    return 0;
}
