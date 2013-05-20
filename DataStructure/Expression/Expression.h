#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
//#define OVERFLOW 0

//�������ڵ�����
typedef enum { INT, CHAR } ElemTag; //INTΪʵ�ͣ�CHARΪ�ַ��� 

//������������ 
typedef struct TElemTag
{
    ElemTag tag;  
    union
    {
        int num;
        char c;
    };
} TElemTag;

//��������ʽ�洢�ṹ 
typedef struct BiTNode
{
    TElemTag data; //������ 
    struct BiTNode *lchild, *rchild;    //���Һ���ָ�� 
} BiTNode, *BiTree;

typedef BiTree SElemType;   //ջSqStack��Ԫ��

//ջ��˳��洢�ṹ 
#define STACK_INIT_SIZE 30  //��ʼ�洢�ռ� 
#define STACKINCREMENT 5    //�洢�ռ����� 

typedef struct SqStack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

int InitStack(SqStack *S)
{
    (*S).base = (SElemType *) malloc (STACK_INIT_SIZE * sizeof(SElemType));
    if(!(*S).base)
        exit(OVERFLOW);
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
    return OK;
}

int StackEmpty(SqStack S)
{
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

int Push(SqStack *S, SElemType e)    //Ԫ��eѹջ 
{
    if((*S).top - (*S).base >= (*S).stacksize)
    {//ջ����׷�Ӵ洢�ռ� 
        (*S).base = (SElemType *) realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!(*S).base)  //�洢����ʧ�� 
            exit(OVERFLOW);
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    *((*S).top)++ = e;
    return OK;
}

int Pop(SqStack *S, SElemType *e)
{
    if((*S).base == (*S).top)
       return ERROR;
    *e = *--(*S).top;
    return OK;
}

int GetTop(SqStack S, SElemType *e)
{
    if(S.top > S. base)
    {
        *e = *(S.top - 1);
        return OK;
    }
    return ERROR;
}
